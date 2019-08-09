//
// Created by sidahmedlahmer on 3/26/19.
//

#ifndef HAZARDOUS_MATERIALS_GAMESCHEDULER_H
#define HAZARDOUS_MATERIALS_GAMESCHEDULER_H

#include <iostream>
#include <vector>
#include <Game.h>
#include "../simple_web_socket/server_wss.hpp"
#include "Player.h"
#include <map>
using WssServer = SimpleWeb::SocketServer<SimpleWeb::WSS>;

class GameScheduler {
public:
    static void onConnectionOpened(const std::shared_ptr<WssServer::Connection>& connection);
    static void onMessageReceived(const std::shared_ptr<WssServer::Connection>& connection, const std::string&);
    static void onConnectionClosed(const std::shared_ptr<WssServer::Connection>& connection,int status,const std::string& );
    static void onError(const std::shared_ptr<WssServer::Connection>& connection, const SimpleWeb::error_code &ec);

    static void test(const std::string&);

    static Player* get_player(int , const std::string&);
    static Game* get_offline_game(const std::string&);
    static Game* get_online_game(const std::string&);
private:
    static std::map<std::string,std::vector<Player*>> m_player_game_offline;
    static std::vector<Game*> m_online_games;
    static std::vector<Game*> m_offline_games;
    static std::vector<Player*> m_offline_players;

    static void gameLoginRoutine(Player*,std::string login);
    static void gameCreationRoutine(Player*,const std::string& game_name);
    static void gameJoinRoutine(Player*,const std::string&,std::string player_id);
    static void gameGridsAssignementRoutine(Player*,Game*,int id,const std::string& player_id);
    static void gameChatRoutine(Player*p,Game*,std::string msg,const std::string& player_id);
    static void gameEngineAddRoutine(Player*,Game*,const std::string& player_id,ClientMessage*);


    static void notify_all_except(int id,const std::string&,Game *pGame);
};


#endif //HAZARDOUS_MATERIALS_GAMESCHEDULER_H