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
    m_current_turn = TEAM1_PLAYER1;


}
std::string Game::get_game_id(){
    return m_game_id;
}
void Game::switch_turn(){
    switch (m_current_turn){
        case TEAM1_PLAYER1:
            m_current_turn = TEAM2_PLAYER1;
            break;
        case TEAM1_PLAYER2:
            m_current_turn = TEAM2_PLAYER2;
            break;
        case TEAM2_PLAYER1:
            m_current_turn = TEAM1_PLAYER2;
            break;
        case TEAM2_PLAYER2:
            m_current_turn = TEAM1_PLAYER1;
            break;
    }
     on_game_state_changed();
}

void Game::on_game_state_changed() {

    std::string score = ServerMessage::getScoreBroadCastMessage(*m_score);
    broadcast_message(score);



    int current_turn_id = get_current_turn_id();
    std::string turn = ServerMessage::getCurrentTurnMessage(current_turn_id);
    broadcast_message(turn);


    //send  priv grids

    //team 1 priv grid exchange
  std::string m1 = ServerMessage::getGridMessage(1,m_t1->get_first_player()->get_priv_grid());

    m_t1->get_second_player()->send_message(m1);

    m_t1->get_first_player()->send_message(ServerMessage::getGridMessage(1,m_t1->get_first_player()->get_priv_grid()));
    m_t1->get_second_player()->send_message(ServerMessage::getGridMessage(2,m_t1->get_second_player()->get_priv_grid()));
    m_t1->get_first_player()->send_message(ServerMessage::getGridMessage(2,m_t1->get_second_player()->get_priv_grid()));

    //team2 priv grid exchange
    m_t2->get_second_player()->send_message(ServerMessage::getGridMessage(3,m_t2->get_first_player()->get_priv_grid()));
    m_t2->get_first_player()->send_message(ServerMessage::getGridMessage(3,m_t2->get_first_player()->get_priv_grid()));
    m_t2->get_second_player()->send_message(ServerMessage::getGridMessage(4,m_t2->get_second_player()->get_priv_grid()));
    m_t2->get_first_player()->send_message(ServerMessage::getGridMessage(4,m_t2->get_second_player()->get_priv_grid()));



    // 1 ==> 3,4
    m_t2->get_second_player()->send_message(ServerMessage::getGridMessage(1,m_t1->get_first_player()->get_pub_grid()));
    m_t2->get_first_player()->send_message(ServerMessage::getGridMessage(1,m_t1->get_first_player()->get_pub_grid()));


    // 2 ==> 3,4
    m_t2->get_second_player()->send_message(ServerMessage::getGridMessage(2,m_t1->get_second_player()->get_pub_grid()));
    m_t2->get_first_player()->send_message(ServerMessage::getGridMessage(2,m_t1->get_second_player()->get_pub_grid()));


    //3 ==> 1,2
    m_t1->get_second_player()->send_message(ServerMessage::getGridMessage(3,m_t2->get_first_player()->get_pub_grid()));
    m_t1->get_first_player()->send_message(ServerMessage::getGridMessage(3,m_t2->get_first_player()->get_pub_grid()));

    //4 ==> 1,2
    m_t1->get_second_player()->send_message(ServerMessage::getGridMessage(4,m_t2->get_second_player()->get_pub_grid()));
    m_t1->get_first_player()->send_message(ServerMessage::getGridMessage(4,m_t2->get_second_player()->get_pub_grid()));

}

void Game::play(Player *player,ClientMessage * clientMessage){

    std::cout<<"[+] a player with id : "<<player->get_id()<<" is playing"<<std::endl;
    ClientMessage::CLIENT_MESSAGE_TYPE msg_type = clientMessage->get_msg_type();
    if(msg_type == ClientMessage::CLIENT_MESSAGE_TYPE::ADD_ENGINE){
        ENGINE_TYPE engineType = clientMessage->get_engine_type();
        Engine* engine = player->create_engine(engineType);
        //TODO check if engine is null..
        if(engine == nullptr){
            std::cout<<"[-] player->create_engine() returned nullptr"<<std::endl;
            return;
        }
        bool h = clientMessage->get_horizontal();
        int x = clientMessage->get_x();
        int y= clientMessage->get_y();
        int ret = player->get_grid()->add_engine(engine,h,x,y);
        if(ret == 1){
            std::string sent_msg = ServerMessage::getEngineAddedMessage();
            player->send_message(sent_msg);
            switch_turn();
        }
        else{
            std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ACTION_FAILED,msg_type);
            player->send_message(err);
        }
    }
    else if(msg_type == ClientMessage::CLIENT_MESSAGE_TYPE::MOVE){
        int engine_id = clientMessage->get_engine_id();
        int x = clientMessage->get_x();
        int y = clientMessage->get_y();
        Engine* engine = player->get_engine_by_id(engine_id);
        if(engine == nullptr){
            std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ENGINE_ID_DOES_NOT_EXIST,msg_type);
            player->send_message(err);
            return;
        }

        int ret = engine->move_engine(player->get_grid(),x,y);
        if(ret == 1){
            std::string msg = ServerMessage::getMoveSuccessMessage(engine_id);
            player->send_message(msg);
            switch_turn();
        }
        else{
            std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ACTION_FAILED,msg_type);
            player->send_message(err);
        }
    }
    else{
        std::cout<<"Action is not supported yet"<<std::endl;
    }


}


void Game::start() {
    std::string start_msg =ServerMessage::getStartMessage();
    broadcast_message(start_msg);

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
int  Game::get_current_turn_id(){
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

bool Game::is_ready() {

    if(m_t1->get_first_player() == nullptr || m_t1->get_second_player() == nullptr)
        return false;

    return !(m_t2->get_first_player() == nullptr || m_t2->get_second_player() == nullptr);

}
