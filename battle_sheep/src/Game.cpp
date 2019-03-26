//
// Created by sidahmedlahmer on 3/26/19.
//

#include <Game.h>

Game::Game(std::string game_id){
    m_game_id = game_id;
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
