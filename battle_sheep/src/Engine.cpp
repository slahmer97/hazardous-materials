//
// Created by stevlulz on 3/7/19.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Engine.h>
#include <iostream>

Engine::Engine(int size_a){

    if(size_a < 2 || size_a > 5)
        size_a = 3;
    m_size=size_a;
    m_movement_point=6-size_a;
    m_current_health_point=size_a;
    m_motor_state=MOTOR;
    m_motor_place = 0;
    m_weapon_state = WEAPON_NOT_INTRODUCED;
    m_weapon_place = m_size-1;
    //m_shell_state = SHELL;
    m_is_on_grid=false;
    m_x = -1;
    m_y = -1;
    m_skill = nullptr;
}


Engine::Engine(int size_a, ENGINE_TYPE engine_type):Engine(size_a) {
    m_skill = FactorySkill::getSkill(engine_type);
    m_weapon_state = WEAPON_STATE::WEAPON;
    m_weapon_place = m_size-1;

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

int Engine::is_horizontal()
{
    if(!(m_is_on_grid))
        return -1;
    return m_horizontal;
}

int Engine::get_x()
{
    if(!(m_is_on_grid))
        return -1;
    return m_x;
}

int Engine::get_y()
{
    if(!(m_is_on_grid))
        return -1;
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
void Engine::increment_points()
{
    m_skill->increase_points(5);
}
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

//TODO
float Engine::take_a_hit(float dammage)
{
    if(!(m_is_on_grid))
        return -1.0f;

    m_current_health_point = (m_current_health_point < dammage ? 0.f : m_current_health_point-dammage);
    return m_current_health_point;
}


int Engine::normal_shot(Grid *grid, int x, int y){
    if(grid==nullptr)
        return -100;
    if(!(m_is_on_grid))
        return -1;
    if(grid->get_engine_x_y(m_x,m_y)==this)
        return -1;
    if(m_weapon_state!=WEAPON_STATE::WEAPON)
        return -1;
    return grid->normal_shot(x, y);
}
int Engine::Skill_shot(Grid *grid, int x, int y, bool horizontal, SHOT_TYPE type_of_shot){
    if(grid==nullptr)
        return -100;
    if(!(m_is_on_grid))
        return -2;
    if(m_skill != nullptr)
        if(m_skill->engine_type_is_shot_type(type_of_shot)!=1)
            return -4;
    if(grid->get_engine_x_y(m_x,m_y)==this)
        return -3;
    if(m_weapon_state!=WEAPON_STATE::WEAPON)
        return -1;
    switch (type_of_shot){

        case PORTE_AVION_SKILL:
            return ((Skill_porte_avion*)m_skill)->use(grid, x, y, horizontal);
        case CROISEUR_SKILL:
            return ((Skill_croiseur*)m_skill)->use(grid, x, y, horizontal);
        case CONTRE_TORPILLEUR_SKILL:
            return ((Skill_contre_torpilleur*)m_skill)->use(grid, x, y, horizontal);
        case CUIRASSE_SKILL:
            return ((Skill_cuirasse*)m_skill)->use(grid, x, y, horizontal);
        case TORPILLEUR_SKILL:
            return ((Skill_torpilleur*)m_skill)->use(grid, x, y, horizontal);
        case BROUILLEUR_SKILL:
            return ((Skill_brouilleur*)m_skill)->use(grid, x, y, horizontal);
        case RECONNAISSANCE_SKILL:
            return ((Skill_reconnaissance*)m_skill)->use(grid, x, y, horizontal);
        case NORMAL_SHOT:
            return  normal_shot(grid,x,y);
        default:
            return -1000;//this function can't call other skills :/
    }
}

int Engine::Skill_shot(Grid *grid1, Grid *grid2, int x, int y, bool horizontal, SHOT_TYPE type_of_shot){
    if(grid1==nullptr || grid2 == nullptr)
        return -100;
    if(!(m_is_on_grid))
        return -2;
    if(m_skill->engine_type_is_shot_type(type_of_shot)!=1)
        return -4;
    if(grid1->get_engine_x_y(m_x,m_y)==this)
        return -3;
    if(grid2->get_engine_x_y(m_x,m_y)==this)
        return -3;
    if(m_weapon_state!=WEAPON_STATE::WEAPON)
        return -1;
    switch (type_of_shot){
        case BOMBARDIER_SKILL:
            return ((Skill_bombardier*)m_skill)->use(grid1,grid2,x,y,horizontal);
        case INTERCEPTEUR_SKILL:
            return ((Skill_intercepteur*)m_skill)->use(grid1,grid2,x,y,horizontal);
        default:
            return -1000;
    }

}
Grid *Engine::Skill_shot(Grid *grid, int x, int y, SHOT_TYPE type_of_shot){

    if(grid==nullptr)
        return nullptr;
    if(!(m_is_on_grid))
        return nullptr;
    if(m_skill->engine_type_is_shot_type(type_of_shot)!=1)
        return nullptr;
    if(grid->get_engine_x_y(m_x,m_y)==this)
        return nullptr;
    if(m_weapon_state!=WEAPON_STATE::WEAPON)
        return nullptr;
    if(type_of_shot==PATROUILE_SKILL)
        return ((Skill_patrouille*)m_skill)->use(grid,x,y);
    else
        return nullptr;
}
    
int Engine::move_engine(Grid *grid, bool reading_direction, int movement_value){
    if(grid==nullptr)
        return -100;
    if(!(m_is_on_grid))
        return -2;
    if(grid->get_engine_x_y(m_x,m_y)!=this)
        return -3;
    if(m_motor_state!=MOTOR)
        return -4;
    if(m_movement_point<movement_value || movement_value<1)
        return -5;

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


    if(grid->check_putable(this,m_horizontal,new_x, new_y)==1)
    {
        grid->remove_engine(this);
        grid->add_engine(this,m_horizontal,new_x,new_y);
        return 1;
    }
    return -1;
}

int Engine::rotate_engine(Grid *grid ,bool clockwise, int node_distance){
    if(grid==nullptr)
        return -100;
    if(!(m_is_on_grid))
        return -2;
    if(grid->get_engine_x_y(m_x,m_y)!=this)
        return -3;
    if(m_motor_state!=MOTOR)
        return -4;
    if(node_distance < 0 || node_distance > m_size-1)
        return -5;
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

    if(grid->check_putable(this,!m_horizontal,new_x, new_y)==1)
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
    if(!(m_is_on_grid))
        return -1.0f;
    m_current_health_point=(m_size < (m_current_health_point+care)? m_size : m_current_health_point+care) ;
    return m_current_health_point;
}

ENGINE_TYPE Engine::get_engine_type() {
    if(m_skill == nullptr)
        return ENGINE_TYPE::NOT_INTRODUCED;
    return m_skill->get_engine_type();
}

MOTOR_STATE Engine::get_motor_state() const {
    return m_motor_state;
}
WEAPON_STATE Engine::get_weapon_state() const {
    return m_weapon_state;
}

ENGINE_TYPE Engine::engine_type_to_type(const std::string &type) {
    if(type == "porte_avion")
        return PORTE_AVION;
    else if(type == "croiseur")
        return CROISEUR;
    else if(type =="contre_torpilleur" )
        return CONTRE_TORPILLEUR ;
    else if(type == "cuirasse")
        return CUIRASSE;
    else if(type == "torpilleur")
        return TORPILLEUR;
    else if(type == "bombardier")
        return BOMBARDIER;
    else if(type =="intercepteur" )
        return INTERCEPTEUR;
    else if(type == "brouilleur")
        return BROUILLEUR;
    else if(type == "patrouile")
        return PATROUILE;
    else if(type == "reconnaissance")
        return RECONNAISSANCE;
    else if(type == "not_introduced")
        return NOT_INTRODUCED ;
    else if(type == "incendiary")
        return INCENDIARY ;

    return NOT_INTRODUCED ;
}

std::string Engine::engine_type_to_string(ENGINE_TYPE type) {
    if(type == PORTE_AVION)
        return "porte_avion";
    else if(type == CROISEUR)
        return "croiseur";
    else if(type == CONTRE_TORPILLEUR)
        return "contre_torpilleur";
    else if(type == CUIRASSE)
        return "cuirasse";
    else if(type == TORPILLEUR)
        return "torpilleur";
    else if(type == BOMBARDIER)
        return "bombardier";
    else if(type ==INTERCEPTEUR )
        return "intercepteur";
    else if(type == BROUILLEUR)
        return "brouilleur";
    else if(type == PATROUILE)
        return "patrouile";
    else if(type == RECONNAISSANCE)
        return "reconnaissance";
    else if(type == NOT_INTRODUCED)
        return "not_introduced";
    else if(type == INCENDIARY)
        return  "incendiary";

    return std::string("not_introduced");
}

void Engine::set_id(int i){
    this->id = i;
}
int Engine::get_id(){
    return this->id;
}

SHOT_TYPE Engine::get_shot_type() {
    if(m_skill == nullptr)
        return NORMAL_SHOT;
    if(m_skill->get_points() < POINT_COST)
     return NORMAL_SHOT;
    else
        return m_skill->engine_type_to_shot_type(m_skill->get_engine_type());
}

bool Engine::has_skill() {
    return m_skill != nullptr;
}

int Engine::get_remain_points(){
    if(m_skill == nullptr)
        return 0;
    return m_skill->get_points();
}
