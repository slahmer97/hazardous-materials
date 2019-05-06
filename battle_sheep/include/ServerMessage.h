//
// Created by sidahmedlahmer on 3/19/19.
//

#ifndef HAZARDOUS_MATERIALS_SERVERMESSAGE_H
#define HAZARDOUS_MATERIALS_SERVERMESSAGE_H

#include "enum.h"
#include "ClientMessage.h"
#include "Score.h"
#include <sstream>
#include <iostream>

class ServerMessage {
public:
    enum SERVER_MESSAGE_TYPE{
        KILL_PLAYER,GRIDS_ASSIGNEMENT,ERROR,CHAT_S,CURRENT_TURN,SCORE_BROADCAST,LOGIN_SUCCESS,CREATED_SUCCESS,JOIN_SUCCESS,START,GRID,ENGINE_ADDED,
        MOVE_SUCCESS,ROTATE_SUCCESS,GRID_ASSIGN_SUCCESS,SHOT_SUCCESS,WON,LOST,NONEE

    };
    enum SKILL_TYPE{
        SKILLED,NORMAL
    };
    enum ERRORS{LOGIN_REQUIRE,GAME_DOES_NOT_EXIST,CONNECTION_LOST,ALREADY_CHOSEN,ACTION_FAILED,ENGINE_ID_DOES_NOT_EXIST,GRID_ID_DOES_NOT_EXIST,GAME_ID_ALREADY_EXIST};

    static std::string getGridAssignSuccess();
    static std::string getShotSuccessMessage();
    static std::string getMoveSuccessMessage(int id);
    static std::string getRotateSuccessMessage(int id);
    static std::string getEngineAddedMessage();
    static std::string getStartMessage();
    static std::string getKillPlayerMessage(int id_player_grid);
    static std::string getGridAssinementMessage(const std::string& username,int id_grid);
    static std::string getErrorMessage(ERRORS error,ClientMessage::CLIENT_MESSAGE_TYPE clientMessage);
    static std::string getGridMessage(int id,const std::string&);//TODO param is just the return string from Player.get_pub/priv_grid
    static std::string getChatMessage(const std::string& message,int id);
    static std::string getJoinSuccessMessage();
    static std::string getCreatedSucessMessage();
    static std::string getCurrentTurnMessage(int id);
    static std::string getScoreBroadCastMessage(Score*);
    static std::string getLoginSuccessMessage();
    static ServerMessage* getServerMessage(const std::string& json_ServerMessage);
    static SERVER_MESSAGE_TYPE to_enum(const std::string&);
    static std::string to_string(SERVER_MESSAGE_TYPE);
    static std::string error_to_string(ERRORS);
    static ERRORS error_to_enum(const std::string&);

private:
    SERVER_MESSAGE_TYPE m_msg_type;
    int m_id;//unsigned char TODO
    std::string m_grid;
    std::string m_chat_msg;
    std::string m_username;
    ERRORS m_error_type;
    Score m_score;
    ClientMessage::CLIENT_MESSAGE_TYPE error_message; //maybe remove later...
public:
    ServerMessage(Score m_score);

    const Score &get_score() const;
    void set_score(const Score &score);

    SERVER_MESSAGE_TYPE get_msg_type() const;
    void set_msg_type(SERVER_MESSAGE_TYPE messageType);
    int get_id() const;
    void set_id(int id);
    const std::string &get_grid() const;
    void set_grid(const std::string &grid);
    const std::string &get_chat_msg() const;
    void set_chat_msg(const std::string &chatMsg);
    const std::string get_username() const;
    void set_username(const std::string &username);
    void set_err_type(ERRORS);
    void set_client_msg(ClientMessage::CLIENT_MESSAGE_TYPE);


    ERRORS get_err_type();
};




#endif //HAZARDOUS_MATERIALS_SERVERMESSAGE_H