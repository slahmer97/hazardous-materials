//
// Created by sidahmedlahmer on 3/19/19.
//

#ifndef HAZARDOUS_MATERIALS_CLIENTMESSAGE_H
#define HAZARDOUS_MATERIALS_CLIENTMESSAGE_H

#include <string>
#include "Score.h"
#include "enum.h"

class ClientMessage {
public:
    enum CLIENT_MESSAGE_TYPE{
        LOGIN,REGISTER,ADD_ENGINE,SHOT,CHAT_C,MOVE,ROTATE,SKIP_TURN,CREATE_GAME,CHOOSE_GRID,JOIN_GAME,MUTE_CHAT,NONE_C
    };
    static CLIENT_MESSAGE_TYPE to_enum(const std::string&);
    static std::string to_string(CLIENT_MESSAGE_TYPE);
    static std::string getLoginMessage(const std::string&,const std::string&);
    static std::string getRegisterMessage(const std::string&,const std::string&);
    static std::string getAdd_engineMessage(ENGINE_TYPE type,int horizontal,int x,int y);
    static std::string getShotMessage(SHOT_TYPE,int,int,int);
    static std::string getChatMessage(const std::string& msg);
    static std::string getMoveMessage(int,int,int);
    static std::string getRotateMessage(int,int);
    static std::string getSkipTurnMessage();
    static std::string getCreateGameMessage(const std::string&);
    static std::string getJoinGameMessage(const std::string& id);
    static std::string getMuteChatMessage();
    static std::string getChoseGridMessage(int);
    static ClientMessage* getClientMessage(const std::string&);

private:
    CLIENT_MESSAGE_TYPE m_msg_type;
    int m_id;
    std::string m_login;
    int m_coor_x,m_coor_y;
    Score m_score;
    int m_engine_id;
    std::string m_chat_msg;
    std::string m_game_name;
    std::string m_grid_type;
    ENGINE_TYPE m_engine_type;
    SHOT_TYPE  m_skill_type;


public:
    void set_msg_type(CLIENT_MESSAGE_TYPE);
    void set_id(int);
    void set_login(std::string);
    void set_x_y(int,int);
    void set_score(Score);

    ClientMessage(const Score &mScore);

    void set_engine_id(int);
    void set_horizontal(int);
    bool get_horizontal();
    void set_chat_msg(const std::string&);
    void set_game_name(const std::string&);
    void set_grid_type(const std::string&);
    void set_engine_type(ENGINE_TYPE);
    void set_shot_type(SHOT_TYPE);
    CLIENT_MESSAGE_TYPE get_msg_type();
    int get_id();
    std::string get_login();
    bool get_reading_direction();
    int get_distance();
    int get_x();
    int get_y();
    int get_engine_id();
    Score get_score();
    std::string get_chat_msg();
    std::string get_game_name();
    ENGINE_TYPE get_engine_type();
    SHOT_TYPE  get_shot_type();
    int get_clock();

    void set_clock(int i);
};







#endif //HAZARDOUS_MATERIALS_CLIENTMESSAGE_H
