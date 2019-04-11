//
// Created by sidahmedlahmer on 3/19/19.
//

#ifndef HAZARDOUS_MATERIALS_CLIENTMESSAGE_H
#define HAZARDOUS_MATERIALS_CLIENTMESSAGE_H

#include <string>
#include "Score.h"
#include "enum.h"

namespace network{
class ClientMessage {
public:
    enum CLIENT_MESSAGE_TYPE{
        LOGIN,REGISTER,ADD_ENGINE,SHOT,CHAT_C,MOVE,ROTATE,SKIP_TURN,CREATE_GAME,JOIN_GAME,MUTE_CHAT,NONE_C
    };
    static CLIENT_MESSAGE_TYPE to_enum(const std::string&);
    static std::string to_string(CLIENT_MESSAGE_TYPE);
    static std::string getLoginMessage(const std::string&,const std::string&);
    static std::string getRegisterMessage(const std::string&,const std::string&);
    static std::string getAdd_engineMessage(ENGINE_TYPE,int,int);
    static std::string getShotMessage(SHOT_TYPE,int,int, unsigned char);
    static std::string getChatMessage(const std::string& msg);
    static std::string getMoveMessage();
    static std::string getRotateMessage(unsigned char);
    static std::string getSkipTurnMessage();
    static std::string getCreateGameMessage(std::string);
    static std::string getJoinGameMessage(const std::string& id);
    static std::string getMuteChatMessage();

private:
    CLIENT_MESSAGE_TYPE m_msg_type;
    unsigned char m_id;
    std::string m_login;
    int m_coor_x,m_coo_y;
    Score m_score;
    std::string m_chat_msg;
    std::string m_game_name;
    std::string m_grid_type;
    ENGINE_TYPE m_engine_type;
    SHOT_TYPE  m_skill_type;
};




}


#endif //HAZARDOUS_MATERIALS_CLIENTMESSAGE_H
