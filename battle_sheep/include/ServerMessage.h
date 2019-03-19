//
// Created by sidahmedlahmer on 3/19/19.
//

#ifndef HAZARDOUS_MATERIALS_SERVERMESSAGE_H
#define HAZARDOUS_MATERIALS_SERVERMESSAGE_H

#include "enum.h"

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


    static std::string getKillPlayerMessage(unsigned char id_player_grid);
    static std::string getGridAssinementMessage(std::string username, unsigned char id_grid);
    static std::string getErrorMessage(ERRORS error,std::string clientMessage);//client message to be modified into CLIENT_MESSAGE_TYPE
    static std::string getChatMessage(std::string message,unsigned char id);
    static std::string getCurrentTurnMessage(unsigned char id);
    static std::string getScoreBroadCastMessage(std::string score);


private:
    SERVER_MESSAGE_TYPE m_msg_type;
    unsigned char m_id;
    std::string m_grid;
    std::string m_chat_msg;
    std::string m_username;
    ERRORS m_error;
    std::string score;
   // CLIENT_MESSAGE



};

}


#endif //HAZARDOUS_MATERIALS_SERVERMESSAGE_H
