//
// Created by stevlulz on 3/7/19.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Engine.h>


Engine::Engine(int size_a){

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    if(size_a < 1 || size_a > 5)
        size_a = 3;
    m_size=size_a;
    m_current_health_point=size_a;
    m_motor_state=MOTOR;
    m_motor_place = rand()%(m_size);
    m_weapon_place = -1;
    m_is_on_grid=false;
    m_x = -1;
    m_y = -1;
}


Engine::Engine(int size_a, ENGINE_TYPE engine_type):Engine(size_a) {
        m_skill = FactorySkill::getSkill(engine_type);
        m_weapon_state = WEAPON_STATE::WEAPON;
        m_weapon_place = m_motor_place;
        while(m_weapon_place==m_motor_place)
        {
            m_weapon_place=rand()%(m_size);
        }

}


void Engine::add_skill(ENGINE_TYPE engine_type,SHOT_TYPE shot_type){
        m_skill = FactorySkill::getSkill(shot_type,engine_type);
}

//Getters

int Engine::get_size()
{
    return m_size;
}

float Engine::get_current_health_point()
{
    return m_current_health_point;
}

bool Engine::is_horizontal()
{
    return m_horizontal;
}

int Engine::get_x()
{
    return m_x;
}

int Engine::get_y()
{
    return m_y;
}
int Engine::get_motor_place()
{
    return m_motor_place;
}
int Engine::get_weapon_place()
{
 return m_weapon_place;
}
bool Engine::get_is_on_grid()
{
    return m_is_on_grid;
}



//Setters
void Engine::set_horizontal(bool horizontal_a)
{
    m_horizontal = horizontal_a;
}
void Engine::set_x(int x_a)
{
    m_x = x_a;
    if(m_x < 0 || m_x >9)
        m_is_on_grid = false;
    if(m_y < 10 && m_y >= 0)
         m_is_on_grid = true;
}
void Engine::set_y(int y_a)
{
    m_y=y_a;
    if(m_y < 0 || m_y >9)
        m_is_on_grid = false;

    if(m_x < 10 && m_x >= 0)
        m_is_on_grid = true;
}
void Engine::set_is_on_grid(bool is_on_grid_a)
{
    if( m_x >= 0 && m_x < 10 && m_y < 10 && m_y >= 0)
        m_is_on_grid=is_on_grid_a;
    else
        m_is_on_grid = false;
}
/*
void Engine::set_grid(int grid_number_a)
{

}
*/

//TODO
float Engine::take_a_hit(float dammage)
{
    m_current_health_point-=dammage;
    return m_current_health_point;
}


int Engine::normal_shot(Grid *grid, int x, int y)
{
    if(grid==nullptr)
        return -100;
    return grid->normal_shot(x, y);
}

int Engine::Skill_shot(Grid *grid, int x, int y, bool horizontal, SHOT_TYPE type_of_shot)
{
    if(grid==nullptr)
        return -100;
    switch (type_of_shot){

        case PORTE_AVION_SKILL:
            return ((Skill_porte_avion*)&m_skill)->use(grid, x, y, horizontal);
        case CROISEUR_SKILL:
            return ((Skill_croiseur*)&m_skill)->use(grid, x, y, horizontal);
        case CONTRE_TORPILLEUR_SKILL:
            return ((Skill_contre_torpilleur*)&m_skill)->use(grid, x, y, horizontal);
        case CUIRASSE_SKILL:
            return ((Skill_cuirasse*)&m_skill)->use(grid, x, y, horizontal);
        case TORPILLEUR_SKILL:
            return ((Skill_torpilleur*)&m_skill)->use(grid, x, y, horizontal);
        case BROUILLEUR_SKILL:
            return ((Skill_brouilleur*)&m_skill)->use(grid, x, y, horizontal);
        case RECONNAISSANCE_SKILL:
            return ((Skill_reconnaissance*)&m_skill)->use(grid, x, y, horizontal);
        default:
            return -1000;//this function can't call other skills :/
    }
}

int Engine::Skill_shot(Grid *grid1, Grid *grid2, int x, int y, bool horizontal, SHOT_TYPE type_of_shot)
{
    if(grid1==nullptr || grid2 == nullptr)
        return -100;
    switch (type_of_shot){
        case BOMBARDIER_SKILL:
            return ((Skill_bombardier*)&m_skill)->use(grid1,grid2,x,y,horizontal);
        case INTERCEPTEUR_SKILL:
            return ((Skill_intercepteur*)&m_skill)->use(grid1,grid2,x,y,horizontal);
        case PATROUILE_SKILL:
            return ((Skill_patrouille*)&m_skill)->use(grid1,grid2,x,y,horizontal); //TODO move it to other skill shot function
        default:
            return -1000;
    }

}
int Engine::move_engine(Grid *grid, bool reading_direction, int movement_value)
{
    if(grid==nullptr)
        return -100;
    int new_x=m_x;
    int new_y=m_y;

    if(m_horizontal)
    {
        new_x+=( reading_direction ? movement_value : (-movement_value) );
    }
    else
    {
        new_y+=( reading_direction ? movement_value : (-movement_value) );
    }


    if(grid->check_putable(this,m_horizontal,m_size,m_x, m_y))
    {
        grid->remove_engine(this);
        grid->add_engine(this,m_horizontal,new_x,new_y);

        return 1;
    }
    return -1;
}

int Engine::rotate_engine(Grid *grid ,bool clockwise, int node_distance)
{
    if(grid==nullptr)
        return -100;
    int new_x = m_x;
    int new_y = m_y;
    if (m_horizontal)
    {
        if (clockwise)
        {
            new_x +=node_distance;
            new_y+= -(m_size - 1)+node_distance;
        }
        else
        {
            new_x+=node_distance;
            new_y-=node_distance;
        }
    }
    else
    {
        if (clockwise)
        {
            new_x-=node_distance;
            new_y+=node_distance;
        }
        else
        {
            new_y+=node_distance;
            new_x+=-(m_size - 1)+node_distance;
        }
    }

    if(grid->check_putable(this,!m_horizontal,m_size,m_x, m_y))
    {
        grid->remove_engine(this);
        grid->add_engine(this,!m_horizontal,new_x,new_y);
        return 1;
    }
    return -1;
}

void Engine::desactivate_motor() {
    m_motor_state = MOTOR_STATE ::MOTOR_DESACTIVATED;
}
void Engine::desactivate_weapon() {
    m_weapon_state = WEAPON_STATE::WEAPON_DESACTIVATED;
}
void Engine::activate_motor() {
    m_motor_state = MOTOR_STATE::MOTOR;
}
void Engine::activate_weapon() {
    m_weapon_state = WEAPON_STATE ::WEAPON;
}
void Engine::kill_weapon() {
    m_weapon_state = WEAPON_STATE::WEAPON_DEAD;
}
void Engine::kill_motor() {
    m_motor_state = MOTOR_STATE::MOTOR_DEAD;
}

float Engine::take_care(float care){
    m_current_health_point+=care;
    return m_current_health_point;
}

ENGINE_TYPE Engine::get_engine_type() {
    if(m_skill == nullptr)
        return NOT_INTRODUCED;
    return m_skill->get_engine_type();
}

MOTOR_STATE Engine::get_motor_state() const {
    return m_motor_state;
}

WEAPON_STATE Engine::get_weapon_state() const {
    return m_weapon_state;
}
