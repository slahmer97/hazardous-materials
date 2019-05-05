//
// Created by stevlulz on 3/7/19.
//

#include <Skill.h>
#include <iostream>

#include "../include/Skill.h"
#define POINT_COST 50

Skill::Skill(ENGINE_TYPE engine_type)
{
    m_engine_type = engine_type;
    m_points = 100;
}
ENGINE_TYPE Skill::get_engine_type()
{
    return m_engine_type;
}

int Skill::decrease_points(int dec)
{
    if(dec < 0){
        return -1;
    }
    m_points = (m_points < dec) ? 0 : m_points - dec;
    return m_points;
}

int Skill::increase_points(int inc)
{
    if(inc < 0){
        return -1;
    }
    m_points += inc;
    return m_points;
}

int Skill::get_points()
{
    return m_points;
}

std::string Skill::shot_type_to_string(SHOT_TYPE shot) {
    if(shot == PORTE_AVION_SKILL)
        return "porte_avion_skill";
    else if(shot == CROISEUR_SKILL)
        return "croiseur_skill";
    else if(shot == CONTRE_TORPILLEUR_SKILL)
        return "contre_torpilleur_skill";
    else if(shot == CUIRASSE_SKILL)
        return "cuirasse_skill";
    else if(shot == TORPILLEUR_SKILL)
        return "torpilleur_skill";
    else if(shot == BOMBARDIER_SKILL)
        return "bombardier_skill";
    else if(shot == INTERCEPTEUR_SKILL)
        return "intercepteur_skill";
    else if(shot == BROUILLEUR_SKILL)
        return "brouilleur_skill";
    else if(shot == PATROUILE_SKILL)
        return "patrouile_skill";
    else if(shot == RECONNAISSANCE_SKILL)
        return "reconnaissance_skill";
    else if(shot == NORMAL_SHOT)
        return "normal_shot";


    return "normal_shot";
}
SHOT_TYPE Skill::shot_type_to_type(const std::string &shot) {
    if(shot == "porte_avion_skill")
        return  PORTE_AVION_SKILL;
    else if(shot == "croiseur_skill")
        return CROISEUR_SKILL;
    else if(shot == "contre_torpilleur_skill")
        return CONTRE_TORPILLEUR_SKILL;
    else if(shot == "cuirasse_skill")
        return CUIRASSE_SKILL;
    else if(shot == "torpilleur_skill")
        return TORPILLEUR_SKILL;
    else if(shot == "bombardier_skill")
        return BOMBARDIER_SKILL;
    else if(shot == "intercepteur_skill")
        return INTERCEPTEUR_SKILL;
    else if(shot == "brouilleur_skill")
        return BROUILLEUR_SKILL;
    else if(shot == "patrouile_skill")
        return PATROUILE_SKILL;
    else if(shot == "reconnaissance_skill")
        return RECONNAISSANCE_SKILL;
    else if(shot == "normal_shot")
        return NORMAL_SHOT;
    return NORMAL_SHOT;
}
ENGINE_TYPE Skill::shot_type_to_engine_type(SHOT_TYPE shot) {
    if(shot == PORTE_AVION_SKILL)
        return  PORTE_AVION;
    else if(shot == CROISEUR_SKILL)
        return CROISEUR;
    else if(shot == CONTRE_TORPILLEUR_SKILL)
        return CONTRE_TORPILLEUR;
    else if(shot == CUIRASSE_SKILL)
        return CUIRASSE;
    else if(shot == TORPILLEUR_SKILL)
        return TORPILLEUR;
    else if(shot == BOMBARDIER_SKILL)
        return BOMBARDIER;
    else if(shot == INTERCEPTEUR_SKILL)
        return INTERCEPTEUR;
    else if(shot == BROUILLEUR_SKILL)
        return BROUILLEUR;
    else if(shot == PATROUILE_SKILL)
        return PATROUILE;
    else if(shot == RECONNAISSANCE_SKILL)
        return RECONNAISSANCE;
    else if(shot == NORMAL_SHOT)
        return NOT_INTRODUCED;
    return NOT_INTRODUCED;
}
SHOT_TYPE Skill::engine_type_to_shot_type(ENGINE_TYPE engine) {
    if(engine == PORTE_AVION)
        return  PORTE_AVION_SKILL;
    else if(engine == CROISEUR)
        return CROISEUR_SKILL;
    else if(engine == CONTRE_TORPILLEUR)
        return CONTRE_TORPILLEUR_SKILL;
    else if(engine == CUIRASSE)
        return CUIRASSE_SKILL;
    else if(engine == TORPILLEUR)
        return TORPILLEUR_SKILL;
    else if(engine == BOMBARDIER)
        return BOMBARDIER_SKILL;
    else if(engine == INTERCEPTEUR)
        return INTERCEPTEUR_SKILL;
    else if(engine == BROUILLEUR)
        return BROUILLEUR_SKILL;
    else if(engine == PATROUILE)
        return PATROUILE_SKILL;
    else if(engine == RECONNAISSANCE)
        return RECONNAISSANCE_SKILL;
    else if(engine == NOT_INTRODUCED)
        return NORMAL_SHOT;
    return NORMAL_SHOT;
}
int Skill::engine_type_is_shot_type(SHOT_TYPE shot)
{
    if(m_engine_type==shot_type_to_engine_type(shot))
        return 1;
    else
        return -1;
}
Skill_porte_avion::Skill_porte_avion() : Skill(ENGINE_TYPE::PORTE_AVION) {}
Skill_porte_avion::Skill_porte_avion(ENGINE_TYPE engine_type) : Skill(engine_type) {}
int Skill_porte_avion::use(Grid *grid, int x, int y, bool horizontal)
{
    if (get_points() < POINT_COST)
        return -1;

    decrease_points(POINT_COST);
    return grid->line_shot(x, y, 3, false, horizontal);
}
int Skill_porte_avion::use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal)
{
    std::cerr << "Skill porte avion can't attack two grids in same time";
    //std::exit(1);
    return -1000;
}

Skill_bombardier::Skill_bombardier(ENGINE_TYPE engine_type) : Skill(engine_type) {}
Skill_bombardier::Skill_bombardier() : Skill(ENGINE_TYPE::BOMBARDIER) {}
int Skill_bombardier::use(Grid *grid, int x, int y, bool horizontal)
{
    std::cerr << "Skill porte avion can't attack two grids in same time";
    // std::exit(1);
    return -1000;
}
int Skill_bombardier::use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal)
{

    if (get_points() < POINT_COST)
        return -1;

    decrease_points(POINT_COST);
    int ret1 = grid1->rectangular_shot(x, y, 3, 3, false);
    int ret2 = grid2->rectangular_shot(x, y, 3, 3, false);

    return ret1 + ret2;
}

Skill_croiseur::Skill_croiseur() : Skill(ENGINE_TYPE::CROISEUR)
{
}
Skill_croiseur::Skill_croiseur(ENGINE_TYPE engine_type) : Skill(engine_type) {}
int Skill_croiseur::use(Grid *grid, int x, int y, bool horizontal)
{
    if (get_points() < POINT_COST)
        return -1;

    decrease_points(POINT_COST);
    int ret = grid->line_shot(x, y, 3, false, horizontal);
    return ret;
}
int Skill_croiseur::use(Grid *grid, Grid *grid2, int x, int y, bool horizontal)
{
    std::cerr << "Skill porte avion can't attack two grids in same time";
    //std::exit(1);
    return -1000;
}

Skill_contre_torpilleur::Skill_contre_torpilleur() : Skill(ENGINE_TYPE::CONTRE_TORPILLEUR)
{
}
Skill_contre_torpilleur::Skill_contre_torpilleur(ENGINE_TYPE engine_type) : Skill(engine_type)
{
}
int Skill_contre_torpilleur::use(Grid *grid, int x, int y, bool horizontal)
{
    if (get_points() < POINT_COST)
        return -1;

    decrease_points(POINT_COST);
    int ret = grid->rectangular_shot(x, y, 2, 2, false);
    return ret;
}
int Skill_contre_torpilleur::use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal)
{
    std::cerr << "Skill porte avion can't attack two grids in same time";
    //std::exit(1);
    return -1000;
}

Skill_cuirasse::Skill_cuirasse() : Skill(ENGINE_TYPE::CUIRASSE)
{
}
Skill_cuirasse::Skill_cuirasse(ENGINE_TYPE engine_type) : Skill(engine_type)
{
}
int Skill_cuirasse::use(Grid *grid, int x, int y, bool horizontal)
{
    if (get_points() < POINT_COST)
        return -1;
    int ret = grid->cross_shot(x, y, 1, false);
    return ret;
}
int Skill_cuirasse::use(Grid *grid, Grid *grid2, int x, int y, bool horizontal)
{
    std::cerr << "Skill porte avion can't attack two grids in same time";
    //std::exit(1);
    return -1000;
}

Skill_torpilleur::Skill_torpilleur() : Skill(ENGINE_TYPE::TORPILLEUR)
{
}
Skill_torpilleur::Skill_torpilleur(ENGINE_TYPE engine_type) : Skill(engine_type)
{
}
int Skill_torpilleur::use(Grid *grid, int x, int y, bool horizontal)
{

    if (get_points() < POINT_COST)
        return -1;
    //int ret = grid->first_to_drawn(x,y,horizontal,false);
    return 1;
}
int Skill_torpilleur::use(Grid *grid, Grid *grid2, int x, int y, bool horizontal)
{
    std::cerr << "Skill porte avion can't attack two grids in same time";
    //std::exit(1);
    return -1000;
}

Skill_intercepteur::Skill_intercepteur() : Skill(ENGINE_TYPE::INTERCEPTEUR)
{
}
Skill_intercepteur::Skill_intercepteur(ENGINE_TYPE engine_type) : Skill(engine_type)
{
}
int Skill_intercepteur::use(Grid *grid, int x, int y, bool horizontal)
{
    std::cerr << "Skill porte avion can't attack two grids in same time";
    // std::exit(1);
    return -1000;
}
int Skill_intercepteur::use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal)
{
    if (get_points() < POINT_COST)
        return -1;
    int ret1 = grid1->line_shot(x, y, 3, false, horizontal);
    int ret2 = grid2->line_shot(x, y, 3, false, horizontal);
    return ret1 + ret2;
}

Skill_brouilleur::Skill_brouilleur() : Skill(ENGINE_TYPE::BROUILLEUR)
{
}
Skill_brouilleur::Skill_brouilleur(ENGINE_TYPE engine_type) : Skill(engine_type)
{
}
int Skill_brouilleur::use(Grid *grid, int x, int y, bool horizontal)
{

    if (get_points() < POINT_COST)
        return -1;

    int ret = grid->rectangular_shot(x, y, 2, 2, true);

    return ret;
}
int Skill_brouilleur::use(Grid *grid, Grid *grid2, int x, int y, bool horizontal)
{
    std::cerr << "Skill porte avion can't attack two grids in same time";
    //std::exit(1);
    return -1000;
}

Skill_patrouille::Skill_patrouille() : Skill(ENGINE_TYPE::PATROUILE)
{
}
Skill_patrouille::Skill_patrouille(ENGINE_TYPE engine_type) : Skill(engine_type)
{
}
int Skill_patrouille::use(Grid *grid, int x, int y, bool horizontal)
{
    std::cerr << "Skill porte avion can't attack two grids in same time";
    //std::exit(1);
    return -1000;
}
int Skill_patrouille::use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal)
{
    std::cerr << "Skill patrouille can't attack two grids in same time";
    //std::exit(1);
    return -1000;
}

//TOCHECK
std::vector<std::vector<Square *>> Skill_patrouille::use(Grid *grid, int x, int y)
{
    if (get_points() < POINT_COST)
        return std::vector<std::vector<Square *>>();

    return grid->radar_rectangular(x, y, 3, 3);
}

Skill_reconnaissance::Skill_reconnaissance() : Skill(ENGINE_TYPE::RECONNAISSANCE)
{
}
Skill_reconnaissance::Skill_reconnaissance(ENGINE_TYPE engine_type) : Skill(engine_type)
{
}
int Skill_reconnaissance::use(Grid *grid, int x, int y, bool horizontal)
{
    if (get_points() < POINT_COST)
        return -1;
    int ret = grid->first_to_drawn(x, y, horizontal, false);
    return ret;
}
int Skill_reconnaissance::use(Grid *grid, Grid *grid2, int x, int y, bool horizontal)
{
    std::cerr << "Skill porte avion can't attack two grids in same time";
    //std::exit(1);
    return -1000;
}
/*
Skill_incendiary::Skill_incendiary() : Skill(ENGINE_TYPE::INCENDIARY)
{
}
*/