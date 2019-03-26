//
// Created by sidahmedlahmer on 3/26/19.
//

#ifndef HAZARDOUS_MATERIALS_PLAYER_H
#define HAZARDOUS_MATERIALS_PLAYER_H

#include <iostream>
#include <server_wss.hpp>
using WssServer = SimpleWeb::SocketServer<SimpleWeb::WSS>;

class Player {
public:
    Player(std::shared_ptr<WssServer::Connection> m_connection);

    unsigned char get_id() const;

    void set_id(unsigned char m_id);

    const std::string &get_username() const;

    void set_username(const std::string &m_username);

    void sendMessage(std::string msg);

    std::shared_ptr<WssServer::Connection> get_connection();
    bool equals(Player*);
private:
    unsigned char m_id;
    std::string m_username;
    //TODO player type ...planes,...
    std::shared_ptr<WssServer::Connection> m_connection;
};


#endif //HAZARDOUS_MATERIALS_PLAYER_H
