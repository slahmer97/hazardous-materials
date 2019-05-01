//
// Created by sidahmedlahmer on 3/26/19.
//

#ifndef HAZARDOUS_MATERIALS_PLAYER_H
#define HAZARDOUS_MATERIALS_PLAYER_H

#include <iostream>
#include "../simple_web_socket/server_wss.hpp"
#include "Game.h"
#include <Grid.h>
#include <Engine.h>

using WssServer = SimpleWeb::SocketServer<SimpleWeb::WSS>;
class Game;
class Grid;
class Engine;
class Player {
public:
    Player(const std::shared_ptr<WssServer::Connection>& m_connection);

    int get_engine_size();
    unsigned char get_id() const;
    void set_id(int id);
    const std::string &get_username() const;
    void set_username(char *username);
    void sendMessage(const std::string& msg);
    void desactivate_chat();
    void activate_chat();
    bool get_chat_status();
    WssServer::Connection* get_connection();

    void send_message(const std::string&);
    bool equals(Player*);
    bool is_me(const std::string&);

    Game * get_game();
    void set_game(Game*);

    Grid * get_grid();

    std::string get_priv_grid();

    std::string get_pub_grid();

    void set_logged_in();
    bool is_logged_in();

    std::vector<Engine*> get_engines();

    void forward_chat_message(const std::string& );
    bool is_ready();
    Engine* get_engine_by_id(int id);
    Engine* create_engine(ENGINE_TYPE);
private:
    std::vector<Engine*> m_engine;
    int m_id = -1;
    std::string m_username;
    bool m_mute_chat = true;
    Game * m_game;
    //TODO player type ...planes,...
    WssServer::Connection *m_connection;
    Grid* m_grid;
    bool m_logged_in = false;

};


#endif //HAZARDOUS_MATERIALS_PLAYER_H
