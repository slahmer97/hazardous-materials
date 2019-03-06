//
// Created by stevlulz on 3/6/19.
//
#include <square.h>

#include "../include/square.h"



Square::Square(){
    m_engine = nullptr;
    m_health_pr = .0f;
    m_square_type = SQUARE_TYPE::NONE;
}

Engine *Square::get_engine(){
    return m_engine;
}
float Square::get_health_pr(){
    return m_health_pr;
}
void Square::desactivate_motor(){
    if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED;
}
void Square::desactivate_weapon(){
    if(m_square_type == SQUARE_TYPE::ENGINE_WEAPON)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED;
}
void Square::activate_weapon(){
    if(m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON;
}
void Square::activate_motor(){
    if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR;

}
SQUARE_TYPE Square::get_square_type(){
    return m_square_type;
}
void Square::set_engine(Engine *engine_a){
    m_engine = engine_a;
}
void Square::set_health_pr(float pr){
    if(pr < 0.f)
        m_health_pr = 0;
    else
        m_health_pr = pr;
}
void Square::set_square_type(SQUARE_TYPE square_type){
    m_square_type = square_type;
}

void Square::decrease_health(float _point) {
    m_health_pr = (_point > m_health_pr)?0:m_health_pr-_point;
}
