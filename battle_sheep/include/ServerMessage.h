//
// Created by sidahmedlahmer on 3/19/19.
//

#ifndef HAZARDOUS_MATERIALS_SERVERMESSAGE_H
#define HAZARDOUS_MATERIALS_SERVERMESSAGE_H

#include "enum.h"
#include "ClientMessage.h"
#include <sstream>
#include <iostream>

namespace network{
class ServerMessage {
public:
    enum SERVER_MESSAGE_TYPE{
        KILL_PLAYER,GRIDS_ASSIGNEMENT,ERROR,CHAT_S,CURRENT_TURN,SCORE_BROADCAST
    };
    enum SKILL_TYPE{
        SKILLED,NORMAL
    };
    enum ERRORS{BLABLA};

    ServerMessage();
    static std::string getKillPlayerMessage(unsigned char id_player_grid);
    static std::string getGridAssinementMessage(std::string username, unsigned char id_grid);
    static std::string getErrorMessage(ERRORS error,std::string clientMessage);//client message to be modified into CLIENT_MESSAGE_TYPE
    static std::string getChatMessage(std::string message,unsigned char id);
    static std::string getCurrentTurnMessage(unsigned char id);
    static std::string getScoreBroadCastMessage(std::string score);
    static network::ServerMessage* getServerMessage(std::string json_ServerMessage);
private:
    SERVER_MESSAGE_TYPE m_msg_type;
    unsigned char m_id;
    std::string m_grid;
    std::string m_chat_msg;
    std::string m_username;
    ERRORS m_error_type;
    std::string score;
    ClientMessage::CLIENT_MESSAGE_TYPE error_message; //maybe remove later...
public:
    SERVER_MESSAGE_TYPE get_msg_type() const;
    void set_msg_type(SERVER_MESSAGE_TYPE m_msg_type);
    unsigned char get_id() const;
    void set_id(unsigned char m_id);
    const std::string &get_grid() const;
    void set_grid(const std::string &m_grid);
    const std::string &get_chat_msg() const;
    void set_chat_msg(const std::string &m_chat_msg);
    const std::string &get_username() const;
    void set_username(const std::string &m_username);

private:
    static SERVER_MESSAGE_TYPE to_enum(std::string);
    static std::string to_string(SERVER_MESSAGE_TYPE);
};

}


#endif //HAZARDOUS_MATERIALS_SERVERMESSAGE_H
