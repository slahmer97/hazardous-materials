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

void GameScheduler::onMessageReceived(const std::shared_ptr<WssServer::Connection>& connection, const std::string& msg) {
    Game *game;
    Player *p;
    ClientMessage *clientMessage = ClientMessage::getClientMessage(msg);
    int type;
    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::CREATE_GAME )
        type = 2;
    else if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::JOIN_GAME)
         type = 2;
    else
        type = 1;


    std::string player_id = boost::lexical_cast<std::string>(connection.get());
    std::cout<<"New player has sent message with id : "<<player_id<<std::endl;

    p = get_player(type,player_id);

    if(p == nullptr){
        //ERROR player doesn't exist
        std::cout<<"Couldn't fetch player object"<<std::endl;
        return;
    }

    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::CREATE_GAME){
        game = new Game(clientMessage->get_game_name());
        m_offline_games.push_back(game);
        p->set_game(game);
        //TODO continue..
        return ;
    }
    if(clientMessage->get_msg_type() == ClientMessage::CLIENT_MESSAGE_TYPE::JOIN_GAME){
        std::string game_id = clientMessage->get_game_name();
        game = get_offline_game(game_id);
        if(game == nullptr){
            std::cout<<"game doesn't exist with this id";
            return;
        }
        p->set_game(game);
        //TODO notify client...
        return;
    }
    else if(game->get_game_id() == "choosing team and grid" /* TODO*/){

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