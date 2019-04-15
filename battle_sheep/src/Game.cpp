//
// Created by sidahmedlahmer on 3/26/19.
//

#include <Game.h>
#include <ServerMessage.h>
Game::Game(const std::string& game_id){
    m_game_id = game_id;
    m_t1 = new Team();
    m_t2 = new Team();
    m_score = new Score(10,10,10,10);


}
std::string Game::get_game_id(){
    return m_game_id;
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
     on_game_state_changed();
}

void Game::on_game_state_changed() {
    //TODO updating the view for all players....
    std::string t1_player1_pub_view = m_t1->get_first_player()->get_pub_grid();
    m_t1->broadcast_message(t1_player1_pub_view);
    std::string t1_player2_pub_view = m_t1->get_second_player()->get_pub_grid();
    m_t1->broadcast_message(t1_player2_pub_view);

    std::string t1_player1_priv_view = m_t1->get_first_player()->get_priv_grid();
    std::string t1_player2_priv_view = m_t1->get_second_player()->get_priv_grid();
    m_t2->broadcast_message(t1_player1_priv_view);
    m_t2->broadcast_message(t1_player2_priv_view);


    std::string t2_player1_pub_view = m_t2->get_first_player()->get_pub_grid();
    m_t2->broadcast_message(t2_player1_pub_view);
    std::string t2_player2_pub_view = m_t2->get_second_player()->get_pub_grid();
    m_t2->broadcast_message(t2_player2_pub_view);

    std::string t2_player1_priv_view = m_t2->get_first_player()->get_priv_grid();
    std::string t2_player2_priv_view = m_t2->get_second_player()->get_priv_grid();
    m_t1->broadcast_message(t2_player1_priv_view);
    m_t1->broadcast_message(t2_player2_priv_view);


    std::string score = ServerMessage::getScoreBroadCastMessage(*m_score);
    broadcast_message(score);
    unsigned char current_turn_id = get_current_turn_id();
    std::string turn = ServerMessage::getCurrentTurnMessage(current_turn_id);
    broadcast_message(turn);


    //send data to players...
}

void Game::play(Player *player,ClientMessage * clientMessage) {

}


void Game::start() {

    //test

    std::string grid_assign_1 = ServerMessage::getGridAssinementMessage(m_t1->get_first_player()->get_username(),1);
    m_t1->get_second_player()->send_message(grid_assign_1);
    std::string grid_assign_2 = ServerMessage::getGridAssinementMessage(m_t1->get_second_player()->get_username(),2);
    m_t1->get_first_player()->send_message(grid_assign_2);
    m_t2->broadcast_message(grid_assign_1);
    m_t2->broadcast_message(grid_assign_2);

    std::string grid_assign_3 = ServerMessage::getGridAssinementMessage(m_t2->get_first_player()->get_username(),3);
    m_t2->get_second_player()->send_message(grid_assign_3);
    std::string grid_assign_4 = ServerMessage::getGridAssinementMessage(m_t2->get_second_player()->get_username(),4);
    m_t2->get_first_player()->send_message(grid_assign_4);
    m_t1->broadcast_message(grid_assign_3);
    m_t1->broadcast_message(grid_assign_4);

    on_game_state_changed();
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
unsigned char  Game::get_current_turn_id(){
    if(m_current_turn == TEAM1_PLAYER1)
        return 1;
    if(m_current_turn == TEAM1_PLAYER2)
        return 2;
    if(m_current_turn == TEAM2_PLAYER1)
        return 3;
    if(m_current_turn == TEAM2_PLAYER2)
        return 4;
}

void Game::broadcast_message(const std::string & msg){
    m_t1->broadcast_message(msg);
    m_t2->broadcast_message(msg);
}

int Game::assign_grid(Player* player,int grid_num){
    if(grid_num == 1 && m_t1->get_first_player() != nullptr)
        return -1;
    else if(grid_num == 1 && m_t1->get_first_player() == nullptr){
        m_t1->set_first_player(player);
        return 1;
    }


    if(grid_num == 2 && m_t1->get_second_player() != nullptr)
        return -2;
    else if(grid_num == 2 && m_t1->get_second_player() == nullptr){
        m_t1->set_second_player(player);
        return 2;
    }

    if(grid_num == 3 && m_t2->get_first_player() != nullptr)
        return -3;
    else if(grid_num == 3 && m_t2->get_first_player() == nullptr){
        m_t2->set_first_player(player);
        return 3;
    }


    if(grid_num == 4 && m_t2->get_second_player() != nullptr)
        return -4;
    else if(grid_num == 4 && m_t2->get_second_player() == nullptr){
        m_t2->set_second_player(player);
        return 4;
    }

    return 0;
}

Player *Game::get_player(int i){
    if(i == 1)
        return m_t1->get_first_player();
    if(i == 2)
        return m_t1->get_second_player();
    if(i == 3)
        return m_t2->get_first_player();
    if(i == 4)
        return m_t2->get_second_player();
    return nullptr;
}
