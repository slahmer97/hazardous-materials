//
// Created by sidahmedlahmer on 3/26/19.
//

#include <Team.h>

#include "Team.h"

Team::Team(){}
Player *Team::has(const std::string &name){
    if(m_player1->is_me(name))
        return m_player1;
    if(m_player2->is_me(name))
        return m_player2;
    return nullptr;
}
Player* Team::get_first_player(){return m_player1;}
Player* Team::get_second_player(){return m_player2;}