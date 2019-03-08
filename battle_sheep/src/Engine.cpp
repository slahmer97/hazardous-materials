//
// Created by stevlulz on 3/7/19.
//

#include "../include/Engine.h"


Engine::Engine(int size_a, bool horizontal_a, int x_a, int y_a){
    m_size=size_a;
    m_horizontal=horizontal_a;
    m_x=x_a;
    m_y=y_a;
    m_current_health_point=size_a;
    m_motor_state=MOTOR;
}


Engine::Engine(int size_a, bool horizontal_a, int x_a, int y_a, ENGINE_TYPE engine_type):Engine(size_a,horizontal_a,x_a,y_a) {
        m_skill = FactorySkill::getSkill(engine_type);
        m_weapon_state = WEAPON_STATE::WEAPON;

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

/*
int Engine::get_grid()
{

}
*/

//Setters
void Engine::set_horizontal(bool horizontal_a)
{
    m_horizontal = horizontal_a;
}
void Engine::set_x(int x_a)
{
    m_x = x_a;
}
void Engine::set_y(int y_a)
{
    m_y=y_a;
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
    return grid->normal_shot(x, y);
}

int Engine::Skill_shot(Grid *grid, int x, int y, bool horizontal, SHOT_TYPE type_of_shot)
{
    return m_skill->use(grid, x, y, horizontal);
}

int Engine::Skill_shot(Grid *grid1, Grid *grid2, int x, int y, bool horizontal, SHOT_TYPE type_of_shot)
{
    return 0;//((Skill_bombardier*)m_engine_skill->getSkill(type_of_shot))->use(grid1,grid2, x, y, horizontal);
}
int Engine::move_engine(Grid *grid, bool reading_direction, int movement_value)
{
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


    //if(grid->check_putable(m_size,new_x,new_y))
    {
        //grid->remove_engine(m_size,m_x, m_y);
        grid->add_engine(this,new_x,new_y,m_skill->get_engine_type());

        m_x=new_x;
        m_y=new_y;
        return 1;
    }
    return -1;
}

int Engine::rotate_engine(Grid *grid ,bool clockwise, int node_distance)
{
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

    m_horizontal = !m_horizontal;

    //if(grid->check_putable(m_size,new_x,new_y))
    {
        //grid->remove_engine(m_size,m_x, m_y);
        grid->add_engine(this,new_x,new_y,m_skill->get_engine_type());
        m_x=new_x;
        m_y=new_y;
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
