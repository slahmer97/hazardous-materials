//
// Created by sidahmedlahmer on 3/19/19.
//

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "ClientMessage.h"

using namespace network;

ClientMessage::CLIENT_MESSAGE_TYPE ClientMessage::to_enum(const std::string& _message_type){
    if(_message_type == "login"){
        return CLIENT_MESSAGE_TYPE ::LOGIN;
    }
    else if(_message_type == "register"){
        return REGISTER;
    }
    else if(_message_type == "add_engine"){
        return ADD_ENGINE;
    }
    else if(_message_type == "shot"){
        return SHOT;
    }
    else if(_message_type == "chat_c"){
        return CHAT_C;
    }
    else if(_message_type == "move"){
        return  MOVE;
    }
    else if(_message_type == "skip_turn"){
        return SKIP_TURN;
    }
    else if(_message_type == "create_game"){
        return CREATE_GAME;
    }
    else if(_message_type == "join_game"){
        return JOIN_GAME;
    }
    else if(_message_type == "mute_chat"){
        return MUTE_CHAT;
    }



    return NONE_C;
}
std::string ClientMessage::to_string(ClientMessage::CLIENT_MESSAGE_TYPE _message_type){
    if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::LOGIN){
        return "login";
    }
    else if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::REGISTER){
        return "register";
    }
    else if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::ADD_ENGINE){
        return "add_engine";
    }
    else if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::SHOT){
        return "shot";
    }
    else if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::CHAT_C){
        return "chat_c";
    }
    else if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::MOVE){
        return  "move";
    }
    else if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::SKIP_TURN){
        return "skip_turn";
    }
    else if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::CREATE_GAME){
        return "create_game";
    }
    else if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::JOIN_GAME){
        return "join_game";
    }
    else if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::MUTE_CHAT){
        return "mute_chat";
    }


    return "none";
}

std::string ClientMessage::getLoginMessage(const std::string& username, const std::string& password) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(LOGIN));
    pt.put("login",username+".."+password);

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}

std::string ClientMessage::getAdd_engineMessage(ENGINE_TYPE type, int x, int y) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(ADD_ENGINE));
    pt.put("engine_type","croisseur");//engine_type_to_string(type)
    pt.put("coor_x",x);
    pt.put("coor_y",y);


    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}

std::string ClientMessage::getShotMessage(SHOT_TYPE type,int x,int y, unsigned char id) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(ADD_ENGINE));
    pt.put("id",id);
    pt.put("shot_type","TROPILLEUR");//shot_type_to_string(type)
    pt.put("coor_x",x);
    pt.put("coor_y",y);
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}

std::string ClientMessage::getChatMessage(const std::string& msg) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(ADD_ENGINE));
    pt.put("chat_msg",msg);
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}

std::string ClientMessage::getMuteChatMessage() {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(MUTE_CHAT));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}

std::string ClientMessage::getJoinGameMessage(const std::string& name) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(JOIN_GAME));
    pt.put("game_name",name);
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}

std::string ClientMessage::getSkipTurnMessage() {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(SKIP_TURN));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}

std::string ClientMessage::getRotateMessage(unsigned char clock) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(ROTATE));
    pt.put("clock",clock);
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}

