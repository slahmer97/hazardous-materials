//
// Created by sidahmedlahmer on 3/19/19.
//

#include <ServerMessage.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <vector>
std::string ServerMessage::error_to_string(ERRORS e){
    if(e == LOGIN_REQUIRE)
        return "login_required";
    else if(e == GAME_DOES_NOT_EXIST)
        return "game_does_not_exist";
    else if(e == ACTION_FAILED)
        return "action_failed";
    else if(e == CONNECTION_LOST)
        return "connection_lost";
    else if(e == ALREADY_CHOSEN)
        return "already_chosen";
    else if(e == ENGINE_ID_DOES_NOT_EXIST)
        return "engine_id_does_not_exist";
    else if(e == GRID_ID_DOES_NOT_EXIST)
        return "grid_id_does_not_exist";

}
ServerMessage::ERRORS ServerMessage::error_to_enum(const std::string& s){
    if(s == "login_required")
        return LOGIN_REQUIRE;
    else if(s == "game_does_not_exist")
        return GAME_DOES_NOT_EXIST;
    else if(s == "action_failed")
        return ACTION_FAILED;
    else if(s == "connection_lost")
        return CONNECTION_LOST;
    else if(s == "already_chosen")
        return ALREADY_CHOSEN;
    else if(s == "engine_id_does_not_exist")
        return ENGINE_ID_DOES_NOT_EXIST;
    else if(s == "grid_id_does_not_exist")
        return GRID_ID_DOES_NOT_EXIST;
}
ServerMessage::SERVER_MESSAGE_TYPE ServerMessage::to_enum(const std::string& type) {
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
    else if(type == "login_success")
        return LOGIN_SUCCESS;
    else if(type == "created_success")
        return CREATED_SUCCESS;
    else if(type == "join_success")
        return JOIN_SUCCESS;
    else if(type == "start")
        return START;
    else if(type == "grid")
        return GRID;
    else if(type == "engine_added")
        return ENGINE_ADDED;
    else if(type == "move_success")
        return MOVE_SUCCESS;
    else if(type == "rotate_success")
        return ROTATE_SUCCESS;
    else if(type == "grid_assign_success")
        return GRID_ASSIGN_SUCCESS;
    else if(type == "error")
        return ERROR;
    else if(type == "shot_success")
        return SHOT_SUCCESS;
    //TODO
    return NONEE;
}

std::string ServerMessage::to_string(ServerMessage::SERVER_MESSAGE_TYPE type){
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
    else if(type == LOGIN_SUCCESS)
        return std::string("login_success");
    else if(type == CREATED_SUCCESS)
        return std::string("created_success");
    else if(type == JOIN_SUCCESS)
        return std::string("join_success");
    else if(type == START)
        return std::string("start");
    else if(type == GRID)
        return std::string("grid");
    else if(type == ENGINE_ADDED)
        return std::string("engine_added");
    else if(type == MOVE_SUCCESS)
        return std::string("move_success");
    else if(type == ROTATE_SUCCESS)
        return std::string("rotate_success");
    else if(type == GRID_ASSIGN_SUCCESS)
        return std::string("grid_assign_success");
    else if(type == ERROR)
        return std::string("error");
    else if(type == SHOT_SUCCESS)
        return std::string("shot_success");

    return std::string("none");//check later
}
std::string ServerMessage::getKillPlayerMessage(int id_player_grid) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(KILL_PLAYER));
    pt.put("id",id_player_grid);


    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}

std::string ServerMessage::getShotSuccessMessage() {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(SHOT_SUCCESS));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();}

std::string ServerMessage::getMoveSuccessMessage(int id){
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(MOVE_SUCCESS));
    pt.put("id",id);

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}

std::string ServerMessage::getRotateSuccessMessage(int id) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(ROTATE_SUCCESS));
    pt.put("id",id);

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();}


std::string ServerMessage::getGridAssinementMessage(const std::string& username,int id_grid) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(GRIDS_ASSIGNEMENT));
    pt.put("id",id_grid);
    pt.put("username",username.c_str());

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string ServerMessage::getChatMessage(const std::string& message,int id) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(CHAT_S));
    pt.put("id",id);
    pt.put("chat_msg",message.c_str());

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string ServerMessage::getCurrentTurnMessage(int id) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(CURRENT_TURN));
    pt.put("id",id);

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string ServerMessage::getGridAssignSuccess() {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(GRID_ASSIGN_SUCCESS));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();}


std::string ServerMessage::getScoreBroadCastMessage(Score* score) {
    boost::property_tree::ptree pt,s1,s2,s3,s4,p;
    pt.put("msg_type",to_string(SCORE_BROADCAST));

    s1.put("",score->get_s1());
    s2.put("",score->get_s2());
    s3.put("",score->get_s3());
    s4.put("",score->get_s4());
    p.push_back(std::make_pair("",s1));
    p.push_back(std::make_pair("",s2));
    p.push_back(std::make_pair("",s3));
    p.push_back(std::make_pair("",s4));
    pt.add_child("score",p);

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string ServerMessage::getLoginSuccessMessage() {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(LOGIN_SUCCESS));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}


std::string ServerMessage::getErrorMessage(ServerMessage::ERRORS error, ClientMessage::CLIENT_MESSAGE_TYPE clientMessage) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(ERROR));
    pt.put("err",error_to_string(error));
    pt.put("client_msg",ClientMessage::to_string(clientMessage));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string ServerMessage::getGridMessage(int id, const std::string &grid) {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(GRID));
    pt.put("grid",grid.c_str());
    pt.put("id",id);

    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}
std::string ServerMessage::getEngineAddedMessage(){
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(ENGINE_ADDED));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);
    return buff.str();
}



std::string ServerMessage::getCreatedSucessMessage() {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(CREATED_SUCCESS));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string ServerMessage::getJoinSuccessMessage() {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(JOIN_SUCCESS));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();
}
std::string ServerMessage::getStartMessage() {
    boost::property_tree::ptree pt;
    pt.put("msg_type",to_string(START));
    std::ostringstream buff;
    boost::property_tree::write_json(buff,pt);

    return buff.str();}


ServerMessage* ServerMessage::getServerMessage(const std::string& json_ServerMessage){

    boost::property_tree::ptree ptree;
    std::istringstream is (json_ServerMessage);
    try {
        boost::property_tree::json_parser::read_json(is,ptree);
    }catch (boost::property_tree::json_parser_error e){
        std::cout<<"[-] invalide message format"<<std::endl;
        return nullptr;
    }
    ServerMessage*serverMessage;
    serverMessage = new ServerMessage(Score(-1, -1, -1, -1));


    std::string msg_type_tmp = ptree.get<std::string>("msg_type");
    SERVER_MESSAGE_TYPE msg_type = to_enum(msg_type_tmp);
    serverMessage->set_msg_type(msg_type);
    if(msg_type == KILL_PLAYER || msg_type == CURRENT_TURN ||msg_type == MOVE_SUCCESS){
        auto id = ptree.get<int>("id");
        serverMessage->set_id(id);
    }
    else if(msg_type == GRIDS_ASSIGNEMENT){
        auto id = ptree.get<int>("id");
        serverMessage->set_id(id);
        std::string username = ptree.get<std::string>("username");
        serverMessage->set_username(username);
    }
    else if(msg_type == CHAT_S){
        auto id = ptree.get<int>("id");
        serverMessage->set_id(id);
        std::string message = ptree.get<std::string>("chat_msg");
        serverMessage->set_chat_msg(message);
    }
    else if(msg_type == SCORE_BROADCAST){
        std::vector<int> sc(4);
        int counter = 0;
        for(auto& s : ptree.get_child("score"))
            sc[counter++] = s.second.get_value<int>();
        serverMessage->set_score(Score(sc[0],sc[1],sc[2],sc[3]));
    }
    else if(msg_type == ERROR){
        std::string err = ptree.get<std::string>("err");
        std::string client_ms = ptree.get<std::string>("client_msg");
        serverMessage->set_err_type(error_to_enum(err));
        serverMessage->set_client_msg(ClientMessage::to_enum(client_ms));
    }
    else if(msg_type == GRID){
        serverMessage->set_grid(ptree.get<std::string>("grid"));
        serverMessage->set_id(ptree.get<int>("id"));
    }

    return serverMessage;
}

ServerMessage::SERVER_MESSAGE_TYPE ServerMessage::get_msg_type() const {
    return m_msg_type;
}
void ServerMessage::set_msg_type(ServerMessage::SERVER_MESSAGE_TYPE messageType) {
    ServerMessage::m_msg_type = messageType;
}
int ServerMessage::get_id() const {
    return m_id;
}
void ServerMessage::set_id(int id) {
    ServerMessage::m_id = id;
}
const std::string &ServerMessage::get_grid() const {
    return m_grid;
}
void ServerMessage::set_grid(const std::string &grid) {
    ServerMessage::m_grid = grid;
}
const std::string &ServerMessage::get_chat_msg() const {
    return m_chat_msg;
}
void ServerMessage::set_chat_msg(const std::string &chatMsg) {
    ServerMessage::m_chat_msg = chatMsg;
}
const std::string ServerMessage::get_username() const {
    return m_username;
}
void ServerMessage::set_username(const std::string &username) {
    ServerMessage::m_username = username;
}
const Score &ServerMessage::get_score() const {
    return m_score;
}
void ServerMessage::set_score(const Score &score) {
    ServerMessage::m_score = score;
}
ServerMessage::ServerMessage(Score m_score) : m_score(m_score) {}

void ServerMessage::set_err_type(ERRORS msg) {
    m_error_type = msg;
}
void ServerMessage::set_client_msg(ClientMessage::CLIENT_MESSAGE_TYPE s){
    error_message = s;
}

ServerMessage::ERRORS ServerMessage::get_err_type(){
    return m_error_type;
}

