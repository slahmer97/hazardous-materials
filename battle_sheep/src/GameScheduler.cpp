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

void GameScheduler::onMessageReceived(const std::shared_ptr<WssServer::Connection>& connection, std::string msg) {

    int type = 1;//TODO
    std::string player_id = boost::lexical_cast<std::string>(connection.get());
    std::cout<<"New player has sent message with id : "<<player_id<<std::endl;
    Player *p = get_player(type,player_id);
    if(p == nullptr){
        //ERROR player doesn't exist

        return;
    }
    Game *game = p->get_game();
    if(game == nullptr){


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
    else if(type == 2){//look in offline_game set
        for(Game* g : m_offline_games){
            Player*p = g->has(connection);
            if(p != nullptr)
                return p;
        }

    }
    else {//look in offline player set
        for(Player* g : m_offline_players)
            if(g->is_me(connection))
                return g;
    }
    return nullptr;
}
