//
// Created by sidahmed on 27.04.19.
//

#include "ClientMessageSender.h"
#include "ClientMessage.h"
WssClient::Connection* ClientMessageSender::server = nullptr;

void ClientMessageSender::setServer(WssClient::Connection * connection) {
    std::cout<<"Server Connection is set up "<<std::endl;

    ClientMessageSender::server = connection;
}

bool ClientMessageSender::checkServerStatus() {
    return ClientMessageSender::server != nullptr;
}

bool ClientMessageSender::sendLoginRequest(const std::string username,const  std::string pass){
    std::string msg = ClientMessage::getLoginMessage(username,pass);
    ClientMessageSender::server->send(msg);
    std::cout<<"Client Sent : "<<msg<<std::endl;

    return checkServerStatus();
}

bool ClientMessageSender::sendRegisterRequest(const std::string username,const  std::string pass){
    std::string msg = ClientMessage::getRegisterMessage(username,pass);
    ClientMessageSender::server->send(msg);
    std::cout<<"Client Sent : "<<msg<<std::endl;

    return checkServerStatus();
}

bool ClientMessageSender::sendAddEngineRequest(ENGINE_TYPE type, int horizontal, int x, int y){
    std::string msg = ClientMessage::getAdd_engineMessage(type,horizontal,x,y);
    ClientMessageSender::server->send(msg);
    std::cout<<"Client Sent : "<<msg<<std::endl;

    return checkServerStatus();
}

bool ClientMessageSender::sendJoinGameRequest(const std::string game_id) {
    std::string msg = ClientMessage::getJoinGameMessage(game_id);
    ClientMessageSender::server->send(msg);
    std::cout<<"Client Sent : "<<msg<<std::endl;

    return checkServerStatus();
}
bool ClientMessageSender::sendCreateGameRequest(const std::string game_id) {
    std::string msg = ClientMessage::getCreateGameMessage(game_id);
    ClientMessageSender::server->send(msg);
    std::cout<<"Client Sent : "<<msg<<std::endl;

    return checkServerStatus();
}
bool ClientMessageSender::sendChooseGridRequest(int grid_id) {
    std::string msg = ClientMessage::getChoseGridMessage(grid_id);
    ClientMessageSender::server->send(msg);
    std::cout<<"Client Sent : "<<msg<<std::endl;

    return checkServerStatus();
}

bool ClientMessageSender::sendRotateEngineRequest(int id,int clock,int node_dist){
    std::string msg = ClientMessage::getRotateMessage(id, clock,node_dist);
    ClientMessageSender::server->send(msg);
    std::cout<<"Client Sent : "<<msg<<std::endl;

    return checkServerStatus();
}

bool ClientMessageSender::sendMoveEngineRequest(int id,int reading_direction, int movement_value) {
    std::string msg = ClientMessage::getMoveMessage(id,reading_direction,movement_value);
    ClientMessageSender::server->send(msg);
    std::cout<<"Client Sent : "<<msg<<std::endl;
    return checkServerStatus();
}

bool ClientMessageSender::sendChatRequest(const std::string msg_chat) {

    std::string msg = ClientMessage::getChatMessage(msg_chat);
    ClientMessageSender::server->send(msg);
    std::cout<<"Client Sent : "<<msg<<std::endl;
    return checkServerStatus();
}

bool ClientMessageSender::isUp() {
    return server != nullptr;
}

bool ClientMessageSender::sendShotRequest(int engine_id,int target_grid,int hori,int x,int y) {

    std::string msg = ClientMessage::getShotMessage(engine_id,target_grid,hori,x,y);
    ClientMessageSender::server->send(msg);
    std::cout<<"Client Sent : "<<msg<<std::endl;
    return checkServerStatus();
}



