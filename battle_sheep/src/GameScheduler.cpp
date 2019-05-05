#include <utility>

#include <utility>
#include <boost/lexical_cast.hpp>
//
// Created by sidahmedlahmer on 3/26/19.
//

#include <GameScheduler.h>
#include <ServerMessage.h>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>

std::map<std::string,std::vector<Player*>> m_player_game_offline;
std::vector<Game*> GameScheduler::m_online_games;
std::vector<Game*> GameScheduler::m_offline_games;
std::vector<Player*> GameScheduler::m_offline_players;
void GameScheduler::onConnectionOpened(const std::shared_ptr<WssServer::Connection>& connection) {
    Player *p;
    p = new Player(connection);
    std::cout<<"[+] New player has opened connection with id : "<<boost::lexical_cast<std::string>(connection.get())<<std::endl;
    GameScheduler::m_offline_players.push_back(p);
}

void GameScheduler::onMessageReceived(const std::shared_ptr<WssServer::Connection>& connection, const std::string& msg){
    std::cout<<"\n--->Received : \n"<<msg<<std::endl;
    Game *game = nullptr;
    Player *p;
    ClientMessage *clientMessage = ClientMessage::getClientMessage(msg);

    if(clientMessage == nullptr){
        //connection.get()->send(ServerMessage::getErrorMessage());
        return;
    }
    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE ::MOVE){
        int a = 22;
    }
    int type;
    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::CREATE_GAME )
        type = 2;
    else if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::JOIN_GAME)
        type = 2;
    else if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::LOGIN)
        type = 2;
    else if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::CHOOSE_GRID)
        type = 2;
    else
        type = 1;


    std::string player_id = boost::lexical_cast<std::string>(connection.get());
    std::cout<<"[+] new player has sent message with id : "<<player_id<<std::endl;

    p = get_player(1,player_id);

    if(p == nullptr)//TODO CHANGE LATER
        p = get_player(2,player_id);

    if(p == nullptr){
        //ERROR player doesn't exist
        std::cout<<"[-] could not fetch player object, maybe your connection were lost, try to reconnect , id : "<<player_id<<std::endl;
        std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::CONNECTION_LOST,clientMessage->get_msg_type());
        connection.get()->send(err);
        return;
    }
    else
        std::cout<<"[+] player with id :"<<player_id<<" has been successfully fetched"<<std::endl;



    //give first chance to login
    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::LOGIN){
        std::string user_name = clientMessage->get_login();
        gameLoginRoutine(p,user_name);
        return;
    }

    //must be logged in to perform any other action
    if(!p->is_logged_in()){
        std::cout<<"[-] player with id : "<<player_id<<"must be logged in order to perform any action"<<std::endl;
        std::string msg_action_denied = ServerMessage::getErrorMessage(ServerMessage::ERRORS::LOGIN_REQUIRE,clientMessage->get_msg_type());
        p->send_message(msg_action_denied);
        return;
    }

    //create game
    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::CREATE_GAME){
        std::string game_name = clientMessage->get_game_name();
        gameCreationRoutine(p,game_name);
        return ;
    }

    //join a game
    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::JOIN_GAME){
        std::string game_id = clientMessage->get_game_name();
        gameJoinRoutine(p,game_id,player_id);
        return;
    }

    //at this point each player must have affected to him..
    game = p->get_game();
    if(game == nullptr){
        std::cout<<"[-] unknnow game for player with id : "<<player_id<<" please try to reconnect"<<std::endl;

        return;
    }

    std::cout<<"[+] Player has :choose_gr "<<p->get_engine_size()<<" engines"<<std::endl;
    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::CHOOSE_GRID){
        int id = clientMessage->get_id();
        gameGridsAssignementRoutine(p,game,id,player_id);

    }
    else if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::CHAT_C){
        //chat
        std::string msg_chat = clientMessage->get_chat_msg();
        gameChatRoutine(p,game,msg_chat,player_id);
    }
    else if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::ADD_ENGINE){
        //qsdqsdmlj
        gameEngineAddRoutine(p,game,player_id,clientMessage);
    }
    else /*(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::MOVE)*/ {
        game = p->get_game();
        if(game->is_my_turn(p)){

            game->play(p,clientMessage);
        }
        else{
            std::cout<<"[-] =======================it's not your turn now"<<std::endl;
        }

    }

}

void GameScheduler::gameLoginRoutine(Player* p,std::string login){
    //TODO maybe check in database ...
    std::string user_name = std::move(login); //TODO split later login = username,password
    p->set_username(const_cast<char *>(user_name.c_str()));
    p->set_logged_in();
    std::string login_success_msg = ServerMessage::getLoginSuccessMessage();
    p->send_message(login_success_msg);
    std::cout<<"[+] player with username :"<<user_name<<" has been successfully logged in"<<std::endl;
}



void GameScheduler::onConnectionClosed(const std::shared_ptr<WssServer::Connection>& connection,int status,const std::string&) {
    //TODO .................
    std::cout<<"Player has closed connection id : "<<boost::lexical_cast<std::string>(connection.get())<<std::endl;
}

void GameScheduler::onError(const std::shared_ptr<WssServer::Connection>& connection, const SimpleWeb::error_code &ec) {
    //TODO................
    std::cout<<"Player has got a connection error id : "<<boost::lexical_cast<std::string>(connection.get())<<std::endl;
}
void GameScheduler::test(const std::string &m) {
    for(Player* p : GameScheduler::m_offline_players)
        p->send_message(m);
}
Player *GameScheduler::get_player(int type,const std::string& connection){
    if(type == 1){//look in online_game set
        for(Game* g : m_online_games){
            Player*p = g->has(connection);
            if(p != nullptr)
                return p;
        }

    }
    else if(type == 2) {//look in offline player set
        for(Player* g : m_offline_players)
            if(g->is_me(connection))
                return g;
    }
    else
        for(Player* g : m_offline_players)
            if(g->is_me(connection))
                return g;

    return nullptr;
}
Game* GameScheduler::get_offline_game(const std::string& id){
    for(Game* g : m_offline_games)
        if(g->get_game_id() == id)
            return g;
    return nullptr;
}
Game* GameScheduler::get_online_game(const std::string& id){
    for(Game* g : m_online_games)
        if(g->get_game_id() == id)
            return g;
    return nullptr;
}

void GameScheduler::notify_all_except(int id,const std::string& player_id ,Game *pGame){
    Player *pp = pGame->get_player(id);
    if(pp == nullptr){
        std::cout<<"[-] notifying players failed .. game with id "<<pGame->get_game_id()<<" does not have player with id "<<player_id<<std::endl;
        return;
    }
    std::string msg = ServerMessage::getGridAssinementMessage(pp->get_username(),id) ;
    for(Player*p : m_offline_players)
        if(p->get_game() == pGame)
            if(!p->is_me(player_id))
                p->send_message(msg);

    std::cout<<"[+] all players has been notified successfully | player with id : "<<player_id<<" has grid with id"<<id<<std::endl;
}

void GameScheduler::gameCreationRoutine(Player* p,const std::string& game_name) {
    Game *game = new Game(game_name);
    m_offline_games.push_back(game);
    p->set_game(game);
    std::cout<<"[+] a new game has been created with name "<<game_name<<std::endl;
    std::string created_success_msg = ServerMessage::getCreatedSucessMessage();
    p->send_message(created_success_msg);
}

void GameScheduler::gameJoinRoutine(Player * p, const std::string& game_id,std::string player_id) {
    std::cout<<"[+] player with id "<<player_id<<" going performed join_game game_id : "<<game_id<<std::endl;
    Game *game = get_offline_game(game_id);
    if(game == nullptr){
        std::cout<<"[-] game doesn't exist with this id";
        std::string game_n_exist = ServerMessage::getErrorMessage(ServerMessage::ERRORS::GAME_DOES_NOT_EXIST,ClientMessage::CLIENT_MESSAGE_TYPE::JOIN_GAME);
        p->send_message(game_n_exist);
        return;
    }
    p->set_game(game);
    std::cout<<"[+] player with id "<<player_id<<" has joint game with id : "<<game_id<<std::endl;
    std::string join_success = ServerMessage::getJoinSuccessMessage();
    p->send_message(join_success);
}

void GameScheduler::gameGridsAssignementRoutine(Player* p,Game* game,int id,const std::string& player_id){
    int ret = game->assign_grid(p,id);
    if(ret <= 0){
        std::cout<<"[-] player with id : "<<player_id<<" failed to get grid id : "<<id<<" on game :"<<game->get_game_id()<<std::endl;
        std::string grid_is_already_chosen = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ALREADY_CHOSEN,ClientMessage::CLIENT_MESSAGE_TYPE::CHOOSE_GRID);
        p->send_message(grid_is_already_chosen);
        return;
    }
    else{
        std::string msg_grid_assign_success = ServerMessage::getGridAssignSuccess();
        p->send_message(msg_grid_assign_success);
        p->set_id(id);
        notify_all_except(id,player_id,game);
    }
}

void GameScheduler::gameChatRoutine(Player *p,Game*game,std::string msg,const std::string& player_id) {

    std::cout<<"=================CHAT<< Player_id : "<<player_id<<" MGG : "<<msg<<std::endl;
    if(p->is_ready()){
        std::string chatMsg = std::move(msg);
        game->forward_chat_message(p,chatMsg);
    }
    else{
        std::cout<<"[-] player with id "<<player_id<<" can't send chat message unless he has grid assigned to him"<<std::endl;
        return;
    }
}

void GameScheduler::gameEngineAddRoutine(Player *p, Game *game, const std::string& player_id,ClientMessage* clientMessage) {
    if(!p->get_game()->is_all_grids_assigned()){
        std::cout<<"[-] All grids must be assigned before adding an engine !!";
        return;
    }
    if(p->is_ready() ) {
        std::cout << "[-] Player with id : " << player_id << " has assinged all his engine on his grid " << std::endl;
        return;
    }
    ENGINE_TYPE engineType = clientMessage->get_engine_type();
    std::cout<<"*****************Engine type "<<Engine::engine_type_to_string(engineType)<<std::endl;
    Engine* engine = p->create_engine(engineType);
    //TODO check if engine is null..
    if(engine == nullptr){
        std::cout<<"[-] player->create_engine() returned nullptr"<<std::endl;
        return;
    }

    if(engine->has_skill()){
        std::cout<<"\t\t\t[+]^^^^^^^^^^^^^Engine has Skill^^^^^^^^^^^^^^^"<<std::endl;
    }
    else
        std::cerr<<"\t\t\t^^^^^^^^^^^^^Engine Skill is Null^^^^^^^^^^^^^^^"<<std::endl;


    bool h = clientMessage->get_horizontal();
    int x = clientMessage->get_x();
    int y= clientMessage->get_y();
    std::cout<<"==============H : "<<h<<"\t x : "<<x<<"\t y : "<<y<<std::endl;
    int ret = p->get_grid()->add_engine(engine,h,x,y);
    if(ret == 1){
        std::string sent_msg = ServerMessage::getEngineAddedMessage();
        p->send_message(sent_msg);
        p->send_message(p->get_priv_grid());
    }
    else{
        std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ACTION_FAILED,ClientMessage::CLIENT_MESSAGE_TYPE::ADD_ENGINE);
        p->send_message(err);
        std::cerr<<"[-] position has already a grid"<<std::endl;
        return;
    }


    if(game->is_ready()){
        std::cout<<"game is ready .."<<std::endl;
        std::cout<<"game ref : "<<game;
        game->start();

    }
}