//
// Created by sidahmedlahmer on 3/19/19.
//

#include <ServerMessage.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
network::ServerMessage::SERVER_MESSAGE_TYPE network::ServerMessage::to_enum(std::string type) {
    if(type == "kill_player")
        return SERVER_MESSAGE_TYPE ::KILL_PLAYER;
    else if(type == "grid_assignement")
        return GRIDS_ASSIGNEMENT;
    else if(type == "chat_s")
        return CHAT_S;
    else if(type == "current_turn")
        return CURRENT_TURN;
    else if(type == "score_broadcast")
        return SCORE_BROADCAST;
    //TODO
    return SCORE_BROADCAST;
}

std::string network::ServerMessage::to_string(network::ServerMessage::SERVER_MESSAGE_TYPE type){
    if(type == KILL_PLAYER)
        return std::string("kill_player");
    else if(type == GRIDS_ASSIGNEMENT)
        return std::string("grid_assignement");
    else if(type == CHAT_S)
        return std::string("chat_s");
    else if(type == CURRENT_TURN)
        return std::string("current_turn");
    else if(type == SERVER_MESSAGE_TYPE::SCORE_BROADCAST)
        return std::string("score_broadcast");
}
std::string network::ServerMessage::getKillPlayerMessage(unsigned char id_player_grid) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(KILL_PLAYER));
    pt.put("id",id_player_grid);


    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string network::ServerMessage::getGridAssinementMessage(std::string username, unsigned char id_grid) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(GRIDS_ASSIGNEMENT));
    pt.put("id",id_grid);
    pt.put("username",username.c_str());

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string network::ServerMessage::getChatMessage(std::string message, unsigned char id) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(CHAT_S));
    pt.put("id",id);
    pt.put("chat_msg",message.c_str());

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string network::ServerMessage::getCurrentTurnMessage(unsigned char id) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(CURRENT_TURN));
    pt.put("id",id);

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string network::ServerMessage::getScoreBroadCastMessage(std::string score) {
    boost::property_tree::ptree pt,s1,s2,s3,s4,p;
    pt.put("msg_type",to_string(SCORE_BROADCAST));

    s1.put("",1);
    s2.put("",2);
    s3.put("",0);
    s4.put("",6);
    p.push_back(std::make_pair("",s1));
    p.push_back(std::make_pair("",s2));
    p.push_back(std::make_pair("",s3));
    p.push_back(std::make_pair("",s4));
    pt.add_child("score",p);

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();}

network::ServerMessage* network::ServerMessage::getServerMessage(std::string json_ServerMessage){
    ServerMessage*serverMessage;
    serverMessage = new ServerMessage();
    boost::property_tree::ptree ptree;
    std::istringstream is (json_ServerMessage);
    boost::property_tree::read_json(is,ptree);

    std::string msg_type_tmp = ptree.get<std::string>("msg_type");
    SERVER_MESSAGE_TYPE msg_type = to_enum(msg_type_tmp);
    serverMessage->set_msg_type(msg_type);
    if(msg_type == KILL_PLAYER || msg_type == CURRENT_TURN ){
        auto id = ptree.get<uint8_t>("id");
        serverMessage->set_id(id);
    }
    else if(msg_type == GRIDS_ASSIGNEMENT){
        auto id = ptree.get<uint8_t>("id");
        serverMessage->set_id(id);
        std::string username = ptree.get<std::string>("username");
        serverMessage->set_username(username);
    }
    else if(msg_type == CHAT_S){
        auto id = ptree.get<uint8_t>("id");
        serverMessage->set_id(id);
        std::string message = ptree.get<std::string>("message");
        serverMessage->set_chat_msg(message);
    }
    //TODO continue..

    return serverMessage;
}

network::ServerMessage::SERVER_MESSAGE_TYPE network::ServerMessage::get_msg_type() const {
    return m_msg_type;
}
void network::ServerMessage::set_msg_type(network::ServerMessage::SERVER_MESSAGE_TYPE m_msg_type) {
    ServerMessage::m_msg_type = m_msg_type;
}
unsigned char network::ServerMessage::get_id() const {
    return m_id;
}
void network::ServerMessage::set_id(unsigned char m_id) {
    ServerMessage::m_id = m_id;
}
const std::string &network::ServerMessage::get_grid() const {
    return m_grid;
}
void network::ServerMessage::set_grid(const std::string &m_grid) {
    ServerMessage::m_grid = m_grid;
}
const std::string &network::ServerMessage::get_chat_msg() const {
    return m_chat_msg;
}
void network::ServerMessage::set_chat_msg(const std::string &m_chat_msg) {
    ServerMessage::m_chat_msg = m_chat_msg;
}
const std::string &network::ServerMessage::get_username() const {
    return m_username;
}
void network::ServerMessage::set_username(const std::string &m_username) {
    ServerMessage::m_username = m_username;
}
