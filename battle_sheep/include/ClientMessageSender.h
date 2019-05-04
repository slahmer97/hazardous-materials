//
// Created by sidahmed on 27.04.19.
//

#ifndef HAZARDOUS_MATERIALS_CLIENTMESSAGESENDER_H
#define HAZARDOUS_MATERIALS_CLIENTMESSAGESENDER_H

#include <client_wss.hpp>
#include "enum.h"

using WssClient = SimpleWeb::SocketClient<SimpleWeb::WSS>;

class ClientMessageSender {

private:
    static WssClient::Connection* server;
    static bool checkServerStatus();
public:
   static bool isUp();
   static void setServer(WssClient::Connection*);

   static bool sendRegisterRequest(const std::string& username,const std::string& pass);
   static bool sendChatRequest(const std::string& msg);
   static bool sendLoginRequest(const std::string& username,const std::string& pass);
   static bool sendJoinGameRequest(const std::string& game_id);
   static bool sendCreateGameRequest(const std::string& game_id);
   static bool sendChooseGridRequest(int& grid_id);
   static bool sendRotateEngineRequest(int id,bool clock);
   static bool sendMoveEngineRequest(int id, bool reading_direction, int movement_value);
   static bool sendAddEngineRequest(ENGINE_TYPE type ,bool horizontal, int x, int y);


};



#endif //HAZARDOUS_MATERIALS_CLIENTMESSAGESENDER_H
