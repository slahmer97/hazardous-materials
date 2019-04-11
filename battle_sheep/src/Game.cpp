//
// Created by sidahmedlahmer on 3/26/19.
//

#include <Game.h>

Game::Game(const std::string& game_id){
    m_game_id = game_id;
    m_t1 = new Team();
    m_t2 = new Team();
}

void Game::switch_turn(){
    switch (m_current_turn){
        case TEAM1_PLAYER1:
            m_current_turn = TEAM2_PLAYER1;
            break;
        case TEAM1_PLAYER2:break;
            m_current_turn = TEAM2_PLAYER2;
        case TEAM2_PLAYER1:break;
            m_current_turn = TEAM1_PLAYER2;
        case TEAM2_PLAYER2:break;
            m_current_turn = TEAM1_PLAYER1;
    }
    //TODO on_game_state_change();
}

void Game::on_game_state_changed() {
    //TODO updating the view for all players....
}

void Game::play(Player *player, const std::string& msg) {

}


void Game::start() {

    //TODO
}

bool Game::is_my_turn(Player * p){
    if(m_t1->get_first_player() == p && m_current_turn == TEAM1_PLAYER1)
        return true;
    if(m_t1->get_second_player() == p && m_current_turn == TEAM1_PLAYER2)
        return true;
    if(m_t2->get_first_player() == p && m_current_turn == TEAM2_PLAYER1)
        return true;
    return m_t2->get_second_player() == p && m_current_turn == TEAM2_PLAYER2;
}
Player* Game::has(const std::string& player_id) {

    Player*p;

    p = m_t1->has(player_id);
    if(p)
        return p ;


    p = m_t2->has(player_id);
    if(p)
        return p;


    return nullptr;
}
