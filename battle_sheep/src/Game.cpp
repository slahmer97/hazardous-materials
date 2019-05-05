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
    //update score

    //TODO may be check if some player is dead then send them END OF GAME
    on_game_state_changed();
    std::cout<<"[+]************************Switching turn ("<<get_current_turn_id()<<")************************************"<<std::endl;
}

void Game::on_game_state_changed() {

    update_score();
    std::string score = ServerMessage::getScoreBroadCastMessage(m_score);
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
    if(msg_type == ClientMessage::MOVE){//==========================================================
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
    else if(msg_type == ClientMessage::ROTATE){//===================================================
        int engine_id = clientMessage->get_engine_id();
        int clock_wise = clientMessage->get_x();
        int node_dist = clientMessage->get_y();
        Engine* engine = player->get_engine_by_id(engine_id);
        if(engine == nullptr){
            std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ENGINE_ID_DOES_NOT_EXIST,msg_type);
            player->send_message(err);
            return;
        }

        int ret = engine->rotate_engine(player->get_grid(),clock_wise,node_dist);
        if(ret == 1){
            std::string msg = ServerMessage::getRotateSuccessMessage(engine_id);// TODO
            player->send_message(msg);
            switch_turn();
        }
        else{
            std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ACTION_FAILED,msg_type);
            player->send_message(err);
        }


    }
    else if(msg_type == ClientMessage::SKIP_TURN){
        switch_turn();
    }
    else if(msg_type == ClientMessage::SHOT){
        //TODO
        int engine_id = clientMessage->get_engine_id();
        int x = clientMessage->get_x();
        int y = clientMessage->get_y();
        int hori = clientMessage->get_horizontal();
        int grid_id = clientMessage->get_grid_id_1();
        Grid * grid = get_grid_by_id(grid_id);
        Engine* engine = player->get_engine_by_id(engine_id);

        if(engine == nullptr){
            std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ENGINE_ID_DOES_NOT_EXIST,msg_type);
            player->send_message(err);
            return;
        }
        if(grid == nullptr){
            std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::GRID_ID_DOES_NOT_EXIST,msg_type);
            player->send_message(err);
            return;
        }

        shot1routine(player,engine,grid,hori,x,y);

    }
    else if(msg_type == ClientMessage::SHOT2){
        int engine_id = clientMessage->get_engine_id();
        int x = clientMessage->get_x();
        int y = clientMessage->get_y();
        int hori = clientMessage->get_horizontal();
        int grid_id1 = clientMessage->get_grid_id_1();
        int grid_id2 = clientMessage->get_grid_id_2();

        Grid* grid1 = get_grid_by_id(grid_id1);
        Grid* grid2 = get_grid_by_id(grid_id2);

        Engine* engine = player->get_engine_by_id(engine_id);

        if(engine == nullptr){
            std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ENGINE_ID_DOES_NOT_EXIST,msg_type);
            player->send_message(err);
            return;
        }
        if(grid1 == nullptr || grid2 == nullptr ){
            std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::GRID_ID_DOES_NOT_EXIST,msg_type);
            player->send_message(err);
            return;
        }

        shot2routine(player,engine,grid1,grid2,hori,x,y);
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
void Game::update_score(){
    int score = 0;
    for(Engine* e : m_t1->get_first_player()->get_engines())
        score += static_cast<int>(e->get_current_health_point());
    m_score->set_s1(score);
    if(score == 0){
        std::string msg = ServerMessage::getKillPlayerMessage(1);
        m_t1->get_first_player()->send_message(msg);
        m_t1->get_first_player()->set_dead();
    }

    score = 0;
    for(Engine* e : m_t1->get_second_player()->get_engines())
        score += static_cast<int>(e->get_current_health_point());
    m_score->set_s2(score);

    if(score == 0){
        std::string msg = ServerMessage::getKillPlayerMessage(2);
        m_t1->get_second_player()->send_message(msg);
        m_t1->get_second_player()->set_dead();
    }

    score = 0;
    for(Engine* e : m_t2->get_first_player()->get_engines())
        score += static_cast<int>(e->get_current_health_point());
    m_score->set_s3(score);
    if(score <= 0){
        std::string msg = ServerMessage::getKillPlayerMessage(3);
        m_t2->get_first_player()->send_message(msg);
        m_t2->get_first_player()->set_dead();
    }


    score = 0;
    for(Engine* e : m_t2->get_second_player()->get_engines())
        score += static_cast<int>(e->get_current_health_point());
    this->m_score->set_s4(score);
    if(score <= 0){
        std::string msg = ServerMessage::getKillPlayerMessage(4);
        m_t2->get_second_player()->send_message(msg);
        m_t2->get_second_player()->set_dead();
    }


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

    if(m_t2->get_first_player() == nullptr || m_t2->get_second_player() == nullptr)
        return false;
    if(! m_t1->get_first_player()->is_ready() || !m_t1->get_second_player()->is_ready() )
        return false;

    return !(!m_t2->get_first_player()->is_ready() || !m_t2->get_second_player()->is_ready());

}
bool Game::is_all_grids_assigned() {
    return m_t1->get_first_player() != nullptr && m_t1->get_second_player() != nullptr &&
           m_t2->get_first_player() != nullptr && m_t2->get_second_player() != nullptr;
}
void Game::forward_chat_message(Player* player,const std::string& msg) {

    std::string send_msg = ServerMessage::getChatMessage(msg,player->get_id());
    m_t1->forward_chat_message(player,send_msg);
    m_t2->forward_chat_message(player,send_msg);
}
Grid *Game::get_grid_by_id(int id) {
    switch (id){
        case 1:
            return m_t1->get_first_player()->get_grid();
        case 2:
            return m_t1->get_second_player()->get_grid();
        case 3:
            return m_t2->get_first_player()->get_grid();
        case 4:
            return m_t2->get_second_player()->get_grid();
        default:
            std::cerr<<"[-] grid with id : "<<id<<" doesn't exist"<<std::endl;
            return nullptr;
    }
}
void Game::shot1routine(Player* p,Engine *engine, Grid *grid,int h,int x,int y){


    SHOT_TYPE  shotType = engine->get_shot_type();
    bool is_shot = shotType == SHOT_TYPE ::NORMAL_SHOT || shotType == SHOT_TYPE ::PORTE_AVION_SKILL ||
                   shotType == SHOT_TYPE ::CROISEUR_SKILL ||  shotType == SHOT_TYPE ::CONTRE_TORPILLEUR_SKILL ||
                   shotType ==   SHOT_TYPE ::CUIRASSE_SKILL || shotType == SHOT_TYPE ::TORPILLEUR_SKILL ||
                   shotType == SHOT_TYPE ::BROUILLEUR_SKILL || shotType == SHOT_TYPE ::RECONNAISSANCE_SKILL;
    bool is_radare = shotType == SHOT_TYPE :: PATROUILE_SKILL;

    if(is_shot){
        int ret = engine->Skill_shot(grid,x,y,h,shotType);
        if(ret >= 0){
                std::string shot_suc_msg = ServerMessage::getShotSuccessMessage();
                p->send_message(shot_suc_msg);
                std::cout<<"[+]" <<shot_suc_msg<<std::endl;
                switch_turn();
        }
        else{
                std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ACTION_FAILED,ClientMessage::CLIENT_MESSAGE_TYPE::SHOT);
                p->send_message(err);
                std::cerr<<"[-] player could not perform this shot============= "<<std::endl;
        }
        return;
    }
    if(is_radare){
        //TODO=========================================

       // Grid* grid1 = engine.





    }


    //
  //;TODOOOOOOOOOOOOOOOO
   // ;


}

void Game::shot2routine(Player *p, Engine *engine, Grid *grid1, Grid *grid2,int hori,int x,int y){

    SHOT_TYPE  shotType = engine->get_shot_type();

    bool is_right_skill_two_grid = shotType == SHOT_TYPE ::BOMBARDIER_SKILL ||  shotType == SHOT_TYPE ::INTERCEPTEUR_SKILL;

    if(is_right_skill_two_grid){
        int ret = engine->Skill_shot(grid1,grid2,x,y,hori,shotType);
        if(ret >= 0){
            std::string shot_suc_msg = ServerMessage::getShotSuccessMessage();
            p->send_message(shot_suc_msg);
            std::cout<<"[+]" <<shot_suc_msg<<std::endl;
            switch_turn();
        }
        else{
            std::string err = ServerMessage::getErrorMessage(ServerMessage::ERRORS::ACTION_FAILED,ClientMessage::CLIENT_MESSAGE_TYPE::SHOT);
            p->send_message(err);
            std::cerr<<"[-] player could not perform this shot============= "<<std::endl;
        }
        return;
    }





}


