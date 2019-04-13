//
// Created by sidahmedlahmer on 3/19/19.
//

#ifndef HAZARDOUS_MATERIALS_SERVERMESSAGE_H
#define HAZARDOUS_MATERIALS_SERVERMESSAGE_H

#include "enum.h"
#include "ClientMessage.h"
#include "Score.h"
#include <sstream>
#include <iostream>

class ServerMessage {
public:
    enum SERVER_MESSAGE_TYPE{
        KILL_PLAYER,GRIDS_ASSIGNEMENT,ERROR,CHAT_S,CURRENT_TURN,SCORE_BROADCAST
    };
    enum SKILL_TYPE{
        SKILLED,NORMAL
    };
    enum ERRORS{BLABLA};

    static std::string getKillPlayerMessage(unsigned char id_player_grid);
    static std::string getGridAssinementMessage(const std::string& username, unsigned char id_grid);
    static std::string getErrorMessage(ERRORS error,ClientMessage::CLIENT_MESSAGE_TYPE clientMessage);
    static std::string getGridMessage(const std::string&);//TODO param is just the return string from Player.get_pub/priv_grid
    static std::string getChatMessage(const std::string& message,unsigned char id);
    static std::string getCurrentTurnMessage(unsigned char id);
    static std::string getScoreBroadCastMessage(Score);
    static ServerMessage* getServerMessage(const std::string& json_ServerMessage);
    static SERVER_MESSAGE_TYPE to_enum(const std::string&);
    static std::string to_string(SERVER_MESSAGE_TYPE);

private:
    SERVER_MESSAGE_TYPE m_msg_type;
    unsigned char m_id;
    std::string m_grid;
    std::string m_chat_msg;
    std::string m_username;
    ERRORS m_error_type;
    Score m_score;
    ClientMessage::CLIENT_MESSAGE_TYPE error_message; //maybe remove later...
public:
    ServerMessage(Score m_score);

    const Score &get_score() const;
    void set_score(const Score &score);

    SERVER_MESSAGE_TYPE get_msg_type() const;
    void set_msg_type(SERVER_MESSAGE_TYPE messageType);
    unsigned char get_id() const;
    void set_id(unsigned char id);
    const std::string &get_grid() const;
    void set_grid(const std::string &grid);
    const std::string &get_chat_msg() const;
    void set_chat_msg(const std::string &chatMsg);
    const std::string &get_username() const;
    void set_username(const std::string &username);

};




#endif //HAZARDOUS_MATERIALS_SERVERMESSAGE_H
