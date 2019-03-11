//
// Created by stevlulz on 3/7/19.
//

#include <Skill.h>
#include <iostream>

#include "../include/Skill.h"


#define POINT_COST 50
Skill::Skill(ENGINE_TYPE engine_type) {
    m_engine_type = engine_type;
    m_points = 100;
}
ENGINE_TYPE Skill::get_engine_type() {
    return m_engine_type;
}

void Skill::decrease_points(int dec) {
    m_points =(m_points < dec)?0:m_points-dec;
}

void Skill::increase_points(int inc) {
    m_points +=inc;
}

int Skill::get_points() {
    return m_points;
}


Skill_porte_avion::Skill_porte_avion() : Skill(ENGINE_TYPE::PORTE_AVION){}
Skill_porte_avion::Skill_porte_avion(ENGINE_TYPE engine_type) : Skill(engine_type){}
int Skill_porte_avion::use(Grid *grid, int x, int y, bool horizontal) {
    if(get_points() < 50)
        return -1;

    decrease_points(50);
    return  grid->line_shot(x,y,3, false,horizontal);
}
int Skill_porte_avion::use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal){
    std::cerr<<"Skill porte avion can't attack two grids in same time";
    std::exit(1);
}


Skill_bombardier::Skill_bombardier(ENGINE_TYPE engine_type) : Skill(engine_type){}
Skill_bombardier::Skill_bombardier() : Skill(ENGINE_TYPE::BOMBARDIER){}
int Skill_bombardier::use(Grid *grid, int x, int y, bool horizontal) {
    std::cerr<<"Skill porte avion can't attack two grids in same time";
    std::exit(1);
}
int Skill_bombardier::use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal){

    if(get_points() < POINT_COST)
        return -1;

    decrease_points(POINT_COST);
    int ret1 = grid1->rectangular_shot(x,y,3,3,false);
    int ret2 = grid2->rectangular_shot(x,y,3,3,false);

    return ret1+ret2;
}


Skill_croiseur::Skill_croiseur() :Skill(ENGINE_TYPE::CROISEUR) {

}
Skill_croiseur::Skill_croiseur(ENGINE_TYPE engine_type) : Skill(engine_type){}
int Skill_croiseur::use(Grid *grid, int x, int y, bool horizontal) {
    if(get_points() < POINT_COST)
        return -1;

    decrease_points(POINT_COST);
    int ret = grid->line_shot(x,y,3, false,horizontal);
    return ret;
}
int Skill_croiseur::use(Grid *grid, Grid *grid2, int x, int y, bool horizontal) {
    std::cerr<<"Skill porte avion can't attack two grids in same time";
    std::exit(1);
}

Skill_contre_torpilleur::Skill_contre_torpilleur() : Skill(ENGINE_TYPE::TORPILLEUR){

}
Skill_contre_torpilleur::Skill_contre_torpilleur(ENGINE_TYPE engine_type) : Skill(engine_type){

}
int Skill_contre_torpilleur::use(Grid *grid,int x, int y, bool horizontal) {
    if(get_points() < POINT_COST)
        return -1;

    decrease_points(POINT_COST);
    int ret = grid->rectangular_shot(x,y,2,2,false);
    return ret;
}
int Skill_contre_torpilleur::use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal) {
    std::cerr<<"Skill porte avion can't attack two grids in same time";
    std::exit(1);
}

Skill_cuirasse::Skill_cuirasse() :Skill(ENGINE_TYPE::CUIRASSE){

}
Skill_cuirasse::Skill_cuirasse(ENGINE_TYPE engine_type) : Skill(engine_type){

}
int Skill_cuirasse::use(Grid *grid, int x, int y, bool horizontal) {
    if(get_points() < POINT_COST)
        return -1;
    int ret = grid->cross_shot(x,y,1,false);
    return ret;
}
int Skill_cuirasse::use(Grid *grid, Grid *grid2, int x, int y, bool horizontal) {
    std::cerr<<"Skill porte avion can't attack two grids in same time";
    std::exit(1);
}

Skill_torpilleur::Skill_torpilleur() :Skill(ENGINE_TYPE::TORPILLEUR){

}
Skill_torpilleur::Skill_torpilleur(ENGINE_TYPE engine_type) : Skill(engine_type){

}
int Skill_torpilleur::use(Grid *grid,int x, int y, bool horizontal) {

    if(get_points() < POINT_COST)
        return -1;
    //int ret = grid->first_to_drawn(x,y,horizontal,false);
    return 1;
}
int Skill_torpilleur::use(Grid *grid, Grid *grid2, int x, int y, bool horizontal) {
    std::cerr<<"Skill porte avion can't attack two grids in same time";
    std::exit(1);
}

Skill_intercepteur::Skill_intercepteur() :Skill(ENGINE_TYPE::INTERCEPTEUR){

}
Skill_intercepteur::Skill_intercepteur(ENGINE_TYPE engine_type) : Skill(engine_type){

}
int Skill_intercepteur::use(Grid *grid, int x, int y, bool horizontal) {
    std::cerr<<"Skill porte avion can't attack two grids in same time";
    std::exit(1);
}
int Skill_intercepteur::use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal) {
    if(get_points() < POINT_COST)
        return -1;
    int ret1 = grid1->line_shot(x,y,3,false,horizontal);
    int ret2 = grid2->line_shot(x,y,3,false,horizontal);
    return ret1+ret2;
}


Skill_brouilleur::Skill_brouilleur():Skill(ENGINE_TYPE::BROUILLEUR) {

}
Skill_brouilleur::Skill_brouilleur(ENGINE_TYPE engine_type) : Skill(engine_type){

}
int Skill_brouilleur::use(Grid *grid, int x, int y, bool horizontal) {

    if(get_points() < POINT_COST)
        return -1;

    int ret = grid->rectangular_shot(x,y,2,2,true);

    return ret;
}
int Skill_brouilleur::use(Grid *grid, Grid *grid2, int x, int y, bool horizontal) {
    std::cerr<<"Skill porte avion can't attack two grids in same time";
    std::exit(1);
}


Skill_patrouille::Skill_patrouille() :Skill(ENGINE_TYPE::PATROUILE){

}
Skill_patrouille::Skill_patrouille(ENGINE_TYPE engine_type) : Skill(engine_type){

}
int Skill_patrouille::use(Grid *grid, int x, int y, bool horizontal) {
    std::cerr<<"Skill porte avion can't attack two grids in same time";
    std::exit(1);
}
int Skill_patrouille::use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal) {
    std::cerr<<"Skill patrouille can't attack two grids in same time";
    std::exit(1);
}

//TOCHECK
std::vector<std::vector<Square *>> Skill_patrouille::use(Grid *grid, int x, int y) {
    if(get_points() < POINT_COST)
        return std::vector<std::vector<Square *>>();

    return grid->radar_rectangular(x,y,3,3);
}


Skill_reconnaissance::Skill_reconnaissance():Skill(ENGINE_TYPE::RECONNAISSANCE) {

}
Skill_reconnaissance::Skill_reconnaissance(ENGINE_TYPE engine_type) : Skill(engine_type){

}
int Skill_reconnaissance::use(Grid *grid, int x, int y, bool horizontal) {
    if(get_points() < POINT_COST)
        return -1;
    int ret = grid->first_to_drawn(x,y,horizontal,false);
    return ret;
}
int Skill_reconnaissance::use(Grid *grid, Grid *grid2, int x, int y, bool horizontal) {
    std::cerr<<"Skill porte avion can't attack two grids in same time";
    std::exit(1);
}


