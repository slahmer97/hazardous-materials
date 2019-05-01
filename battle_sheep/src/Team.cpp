//
// Created by sidahmedlahmer on 3/26/19.
//

#include <Team.h>

#include "Team.h"

Team::Team(){
    m_player1 = nullptr;
    m_player2 = nullptr;
}
Player *Team::has(const std::string &name){
    if(m_player1->is_me(name))
        return m_player1;
    if(m_player2->is_me(name))
        return m_player2;
    return nullptr;
}
Player* Team::get_first_player(){return m_player1;}
Player* Team::get_second_player(){return m_player2;}
void Team::broadcast_message(const std::string& _msg){
    if(m_player1 != nullptr)
        m_player1->send_message(_msg);
    else
        std::cout<<"Player 1 is null"<<std::endl;
    if(m_player2 != nullptr)
      m_player2->send_message(_msg);
    else
        std::cout<<"Player 2 is null"<<std::endl;

}
void Team::set_first_player(Player *p) {
    m_player1 = p;
}
void Team::set_second_player(Player *p) {
    m_player2 = p;
}

void Team::forward_chat_message(Player* player,const std::string& msg){
    if(m_player1 != player && m_player1 != nullptr ){
        m_player1->forward_chat_message(msg);
    }
    if(m_player2 != player && m_player2 != nullptr)
        m_player2->forward_chat_message(msg);
}
