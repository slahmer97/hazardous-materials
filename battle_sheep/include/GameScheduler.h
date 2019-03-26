//
// Created by sidahmedlahmer on 3/26/19.
//

#ifndef HAZARDOUS_MATERIALS_GAMESCHEDULER_H
#define HAZARDOUS_MATERIALS_GAMESCHEDULER_H

#include <iostream>
#include <vector>
#include <Game.h>
#include <server_wss.hpp>
#include "Player.h"

using WssServer = SimpleWeb::SocketServer<SimpleWeb::WSS>;

class GameScheduler {
public:
    static void onConnectionOpened(std::shared_ptr<WssServer::Connection> connection);
    static void onMessageReceived(std::shared_ptr<WssServer::Connection> connection, std::string msg);
    static void onConnectionClosed(std::shared_ptr<WssServer::Connection> connection,int status,const std::string& );
    static void onError(std::shared_ptr<WssServer::Connection> connection, const SimpleWeb::error_code &ec);

private:
    static std::vector<Game*> m_online_games;
    static std::vector<Game*> m_offline_games;
    static std::vector<Player*> m_offline_players;
};


#endif //HAZARDOUS_MATERIALS_GAMESCHEDULER_H
