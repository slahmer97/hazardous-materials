//
// Created by stevlulz on 3/7/19.
//
#include "../include/Square.h"



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

//TODO check if this function can modify the engine health also
int Square::decrease_health(float dammage) {
    if(m_engine == nullptr || m_square_type == SQUARE_TYPE::NONE || m_square_type == SQUARE_TYPE::ENGINE_PART_DEAD ||
       m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DEAD || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DEAD )
        return 0;

    m_engine->take_a_hit(dammage);
    if(m_health_pr > dammage){
        m_health_pr -=dammage;
    }
    else{
        m_health_pr = 0;
        if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED){
            m_engine->kill_motor();
            m_square_type = SQUARE_TYPE ::ENGINE_MOTOR_DEAD;
        }
        else if(m_square_type == SQUARE_TYPE::ENGINE_WEAPON || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED){
            m_engine->kill_weapon();
            m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DEAD;
        }else{
            m_square_type = SQUARE_TYPE ::ENGINE_PART_DEAD;
        }
    }
    return 1;
}

//TODO
int Square::increase_health(float care){
    if(m_engine == nullptr || m_square_type == SQUARE_TYPE::NONE)
        return 0;
    m_engine->take_care(care);
    m_health_pr +=care;
    if(m_health_pr == 0){
        if(m_square_type == SQUARE_TYPE::ENGINE_PART_DEAD)
            m_square_type = SQUARE_TYPE::ENGINE_PART;
        else if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DEAD){
            m_square_type = SQUARE_TYPE ::ENGINE_MOTOR;
            m_engine->activate_motor();
        }
        else if(m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DEAD){
            m_square_type = SQUARE_TYPE::ENGINE_WEAPON;
            m_engine->activate_weapon();
        }
    }

    return 1;
}

void Square::set_engine(Engine *m_engine) {
    Square::m_engine = m_engine;
}
