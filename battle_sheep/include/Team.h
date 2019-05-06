//
// Created by sidahmedlahmer on 3/26/19.
//

#ifndef HAZARDOUS_MATERIALS_TEAM_H
#define HAZARDOUS_MATERIALS_TEAM_H


#include <Player.h>
class Player;
class Team {
public:
    Team();
    //TODO

    Player* has(const std::string&);
    Player* get_first_player();
    Player* get_second_player();
    void broadcast_message(const std::string&);
    void set_first_player(Player*);
    void set_second_player(Player*);
    void forward_chat_message(Player*,const std::string& msg);
    void set_lost();
    void on_game_end();
private:
    Player *m_player1,*m_player2;
    bool winner = true;

};


#endif //HAZARDOUS_MATERIALS_TEAM_H