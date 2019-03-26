//
// Created by sidahmedlahmer on 3/26/19.
//

#ifndef HAZARDOUS_MATERIALS_TEAM_H
#define HAZARDOUS_MATERIALS_TEAM_H


#include "Player.h"

class Team {
public:
    Team();
    //TODO
private:
    std::shared_ptr<Player> m_player1,m_player2;
};


#endif //HAZARDOUS_MATERIALS_TEAM_H
