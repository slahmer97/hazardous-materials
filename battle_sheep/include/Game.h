//
// Created by sidahmedlahmer on 3/26/19.
//

#ifndef HAZARDOUS_MATERIALS_GAME_H
#define HAZARDOUS_MATERIALS_GAME_H


#include "Team.h"
#include <Score.h>
#include "Player.h"
#include <ClientMessage.h>
#include <Grid.h>
class Team;
class Player;
class Score;
class ClientMessage;
class Grid;
//TODO check play method...if we make method for each action and call the right one out side..or doing it inside play function...
class Game {
private:
    enum TURN{TEAM1_PLAYER1,TEAM1_PLAYER2,TEAM2_PLAYER1,TEAM2_PLAYER2};
public:
    Game(const std::string&);
    void start();
    void play(Player* player,ClientMessage*);//TODO check if we
    Player* has(const std::string&);
    bool is_my_turn(Player*);
    int get_current_turn_id();
    void broadcast_message(const std::string&);
    std::string get_game_id();
    int assign_grid(Player*,int);
    Player* get_player(int);
    bool is_all_grids_assigned();
    bool is_ready();
    void forward_chat_message(Player*,const std::string& msg);
private:
    std::string m_game_id;
    Team* m_t1,*m_t2;
    TURN m_current_turn;
    Score* m_score;
    Grid* get_grid_by_id(int id);
    void switch_turn();
    void on_game_state_changed();
    void update_score();



    void shot1routine(Player* p,Engine* engine,Grid*grid,int hori,int x,int y);
};


#endif //HAZARDOUS_MATERIALS_GAME_H