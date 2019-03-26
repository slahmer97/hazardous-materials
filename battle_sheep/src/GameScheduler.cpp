//
// Created by sidahmedlahmer on 3/26/19.
//

#include <GameScheduler.h>

#include "GameScheduler.h"

void GameScheduler::onConnectionOpened(std::shared_ptr<WssServer::Connection> connection) {
        std::cout<<"New player has opened a connection "<<std::endl;
}

void GameScheduler::onMessageReceived(std::shared_ptr<WssServer::Connection> connection, std::string msg) {
    sleep(5);
    std::cout<<"Player has sent a message"<<std::endl;
}

void GameScheduler::onConnectionClosed(std::shared_ptr<WssServer::Connection> connection,int status,const std::string&) {
    std::cout<<"Player has closed connection"<<std::endl;
}

void GameScheduler::onError(std::shared_ptr<WssServer::Connection> connection, const SimpleWeb::error_code &ec) {
    std::cout<<"Player has got error :"<<std::endl;
}
