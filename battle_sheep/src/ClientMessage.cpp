//
// Created by sidahmedlahmer on 3/19/19.
//

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <ClientMessage.h>
#include <Engine.h>

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
    else if(_message_type == "choose_grid"){
        return CHOOSE_GRID;
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
    else if(_message_type == ClientMessage::CLIENT_MESSAGE_TYPE::CHOOSE_GRID){
        return "choose_grid";
    }


    return "none";
}

std::string ClientMessage::getLoginMessage(const std::string& username, const std::string& password) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(LOGIN));
    pt.put("login",username);

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}
std::string ClientMessage::getAdd_engineMessage(ENGINE_TYPE type,int horizontal,int x,int y) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(ADD_ENGINE));
    pt.put("engine_type",Engine::engine_type_to_string(type));
    pt.put("id",horizontal);
    pt.put("x",x);
    pt.put("y",y);


    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}
std::string ClientMessage::getShotMessage(SHOT_TYPE type,int x,int y,int id) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(SHOT));
    pt.put("id",id);
    pt.put("shot_type",Skill::shot_type_to_string(type));
    pt.put("x",x);
    pt.put("y",y);
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
} //
std::string ClientMessage::getChatMessage(const std::string& msg) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(CHAT_C));
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
}//
std::string ClientMessage::getSkipTurnMessage() {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(SKIP_TURN));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}//
std::string ClientMessage::getRotateMessage(int id,int clock) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(ROTATE));
    pt.put("clock",clock);
    pt.put("engine_id",id);

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}//
std::string ClientMessage::getCreateGameMessage(const std::string& msg){
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(CREATE_GAME));
    pt.put("game_name",msg);
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}//
std::string ClientMessage::getMoveMessage(int id,int x,int y) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(MOVE));
    pt.put("engine_id",id);
    pt.put("x",x);
    pt.put("y",y);
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}//
std::string ClientMessage::getRegisterMessage(const std::string & login, const std::string & pass) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(REGISTER));
    pt.put("login",std::string(login)+std::string("..")+std::string(pass));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}//
std::string ClientMessage::getChoseGridMessage(int id) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(CHOOSE_GRID));
    pt.put("id",id);
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();}//

ClientMessage* ClientMessage::getClientMessage(const std::string& json){
        ClientMessage *clientMessage;
        clientMessage = new ClientMessage(Score(-1,-1,-1,-1));
        boost::property_tree::ptree ptree;
        std::istringstream is (json);
        try {
            boost::property_tree::json_parser::read_json(is,ptree);
        }catch (boost::property_tree::json_parser_error e){
            std::cout<<"[-] invalide message format"<<std::endl;
            return nullptr;
        }


        std::string msg_type_tmp = ptree.get<std::string>("msg_type");

        std::cout<<"Message type : "<<msg_type_tmp<<std::endl;

        CLIENT_MESSAGE_TYPE msg_type = to_enum(msg_type_tmp);
        clientMessage->set_msg_type(msg_type);

        if(msg_type == SHOT ||  msg_type == MOVE || msg_type == ROTATE){
            clientMessage->set_id( ptree.get<int>("id"));
            if(msg_type == SHOT){
                clientMessage->set_x_y(ptree.get<int>("x"),ptree.get<int>("y"));
                clientMessage->set_shot_type(Skill::shot_type_to_type(ptree.get<std::string>("shot_type")));
            }
            else if(msg_type == MOVE){
                clientMessage->set_engine_id(ptree.get<int>("engine_id"));
                clientMessage->set_x_y(ptree.get<int>("x"),ptree.get<int>("y"));
            }
            else if(msg_type == ROTATE){
                clientMessage->set_clock(ptree.get<int>("clock"));
                clientMessage->set_engine_id(ptree.get<int>("engine_id"));
            }
            return clientMessage;
        }
        else{

            if(msg_type == REGISTER){
                clientMessage->set_login(ptree.get<std::string>("login"));
            }
            else if(msg_type == CREATE_GAME || msg_type == JOIN_GAME){
                clientMessage->set_game_name(ptree.get<std::string>("game_name"));
            }
            else if(msg_type == CHAT_C ){
                clientMessage->set_chat_msg(ptree.get<std::string>("chat_msg"));
            }
            else if(msg_type == CHOOSE_GRID){
                clientMessage->set_id(ptree.get<int>("id"));
            }
            else if(msg_type == ADD_ENGINE){
                clientMessage->set_x_y(ptree.get<int>("x"),ptree.get<int>("y"));
                clientMessage->set_horizontal(ptree.get<int>("id"));
            }

            return clientMessage;
        }

}


ClientMessage::CLIENT_MESSAGE_TYPE ClientMessage::get_msg_type() {
    return m_msg_type;
}


void ClientMessage::set_login(std::string l) {
    m_login = std::string(l.c_str());
}
void ClientMessage::set_id(int id) {
    m_id = id;
}
void ClientMessage::set_x_y(int x , int y) {
    m_coor_x= x;
    m_coor_y = y;
}
void ClientMessage::set_score(Score s) {
    m_score = s;
}
void ClientMessage::set_engine_id(int id) {
    m_engine_id = id;
}
void ClientMessage::set_chat_msg(const std::string & msg) {
    m_chat_msg = msg;
}
void ClientMessage::set_game_name(const std::string & n) {
    m_game_name = n;
}
void ClientMessage::set_grid_type(const std::string & s) {
    m_grid_type = s;
}
void ClientMessage::set_engine_type(ENGINE_TYPE e) {
    m_engine_type = e;
}
void ClientMessage::set_shot_type(SHOT_TYPE s) {
    m_skill_type = s;
}


int ClientMessage::get_id() {
    return m_id;
}
std::string ClientMessage::get_login() {
    return m_login;
}
int ClientMessage::get_x() {
    return m_coor_x;
}
int ClientMessage::get_y() {
    return m_coor_y;
}
Score ClientMessage::get_score() {
    return m_score;
}
std::string ClientMessage::get_chat_msg() {
    return m_chat_msg;
}
std::string ClientMessage::get_game_name() {
    return m_game_name;
}
SHOT_TYPE ClientMessage::get_shot_type() {
    return m_skill_type;
}
ENGINE_TYPE ClientMessage::get_engine_type() {
    return m_engine_type;
}

ClientMessage::ClientMessage(const Score &mScore) : m_score(mScore) {}
void ClientMessage::set_msg_type(CLIENT_MESSAGE_TYPE t) {
    m_msg_type = t;
}
void ClientMessage::set_clock(int i) {
    m_coor_x = i;
}
int ClientMessage::get_clock() {
    return m_coor_x;
}

void ClientMessage::set_horizontal(int id) {
    this->m_id = id;
}

bool ClientMessage::get_horizontal() {
    return m_id >= 1;
}

bool ClientMessage::get_reading_direction() {
    return this->m_coor_x > 0;
}
int ClientMessage::get_distance() {
    return this->m_coor_y;
}



int ClientMessage::get_engine_id(){
    return this->m_engine_id;
}

