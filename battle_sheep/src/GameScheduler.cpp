#include <utility>
#include <boost/lexical_cast.hpp>
//
// Created by sidahmedlahmer on 3/26/19.
//

#include <GameScheduler.h>
#include <ServerMessage.h>
#include <iostream>
std::map<std::string,std::vector<Player*>> m_player_game_offline;
std::vector<Game*> GameScheduler::m_online_games;
std::vector<Game*> GameScheduler::m_offline_games;
std::vector<Player*> GameScheduler::m_offline_players;
void GameScheduler::onConnectionOpened(const std::shared_ptr<WssServer::Connection>& connection) {
    Player *p;
    p = new Player(connection);
    std::cout<<"New player has opened connection with id : "<<boost::lexical_cast<std::string>(connection.get())<<std::endl;
    GameScheduler::m_offline_players.push_back(p);
}

void GameScheduler::onMessageReceived(const std::shared_ptr<WssServer::Connection>& connection, const std::string& msg){
    std::cout<<"\n--->Received : \n"<<msg<<std::endl;
    Game *game = nullptr;
    Player *p;
    ClientMessage *clientMessage = ClientMessage::getClientMessage(msg);
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

    p = get_player(type,player_id);

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
        //TODO maybe check in database ...
        std::string user_name = clientMessage->get_login(); //TODO split later login = username,password
        p->set_username(user_name);
        p->set_logged_in();
        std::string login_success_msg = ServerMessage::getLoginSuccessMessage();
        p->send_message(login_success_msg);
        std::cout<<"[+] player with username :"<<p->get_username()<<" has been successfully logged in"<<std::endl;
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
        game = new Game(clientMessage->get_game_name());
        m_offline_games.push_back(game);
        p->set_game(game);
        std::cout<<"[+] a new game has been created with name "<<clientMessage->get_game_name()<<std::endl;
        std::string created_success_msg = ServerMessage::getCreatedSucessMessage();
        p->send_message(created_success_msg);
        return ;
    }

    //join a game
    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::JOIN_GAME){
        std::string game_id = clientMessage->get_game_name();
        std::cout<<"[+] player with id "<<player_id<<" going performed join_game game_id : "<<game_id<<std::endl;
        game = get_offline_game(game_id);
        if(game == nullptr){
            std::cout<<"[-] game doesn't exist with this id";
            std::string game_n_exist = ServerMessage::getErrorMessage(ServerMessage::ERRORS::GAME_DOES_NOT_EXIST,clientMessage->get_msg_type());
            p->send_message(game_n_exist);
            return;
        }
        p->set_game(game);
        std::cout<<"[+] player with id "<<player_id<<" has joint game with id : "<<game_id<<std::endl;
        std::string join_success = ServerMessage::getJoinSuccessMessage();
        p->send_message(join_success);
        return;
    }

    game = p->get_game();
    if(game == nullptr){
        std::cout<<"[-] unknnow game for player with id : "<<player_id<<" please try to reconnect"<<std::endl;

        return;
    }
    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::CHOOSE_GRID){
        int id = clientMessage->get_id();
        int ret = game->assign_grid(p,id);
        if(ret <= 0){
            std::cout<<"[-] player with id : "<<player_id<<" failed to get grid id : "<<id<<" on game :"<<game->get_game_id()<<std::endl;
            std::string grid_is_already_chosen = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ALREADY_CHOSEN,clientMessage->get_msg_type());
            p->send_message(grid_is_already_chosen);
            return;
        }
        else{
            notify_all_except(id,player_id,game);
        }

    }

    else {
        game = p->get_game();
        if(game->is_my_turn(p)){
            game->play(p,clientMessage);
        }

    }

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
