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

SQUARE_TYPE Squer::get_square_type(){
    return m_square_type;
}


float Square::get_health_pr(){
    return m_health_pr;
}

bool Square::squares_equals(Square T){
    return (m_health_pr == T->get_health_pr() && m_engin e== T->get_engine() && m_square_type == T->get_square_type());
}

void Square::desactivate_motor(){
    if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_BURNED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED_PERFORATED;
}
void Square::desactivate_weapon(){
    if(m_square_type == SQUARE_TYPE::ENGINE_WEAPON)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_BURNED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED;
}
void Square::activate_weapon(){
    if(m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_BURNED_PERFORATED;
}
void Square::activate_motor(){
    if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR;
    else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_BURNED_PERFORATED;

}
void Square::burn_square(){
    //MOTOR
    if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_BURNED;
    else if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_BURNED_PERFORATED;
    //WEAPON
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_BURNED_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED;
    //PART
    else if (m_square_type == SQUARE_TYPE::ENGINE_PART)
        m_square_type = SQUARE_TYPE::ENGINE_PART_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_PART_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_PART_BURNED_PERFORATED;
}
void Square::perforate_square()
{
    //MOTOR
    if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_PERFORATED;
    else if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_BURNED_PERFORATED;
    //WEAPON
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_BURNED_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED;
    //PART
    else if (m_square_type == SQUARE_TYPE::ENGINE_PART)
        m_square_type = SQUARE_TYPE::ENGINE_PART_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_PART_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_PART_BURNED_PERFORATED;
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
        if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED ||
        m_square_type == SQUARE_TYPE::ENGINE_MOTOR_BURNED || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_PERFORATED
        || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_BURNED_PERFORATED || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED
        || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_PERFORATED || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED_PERFORATED){
            m_engine->kill_motor();
            m_square_type = SQUARE_TYPE ::ENGINE_MOTOR_DEAD;
        }
        else if(m_square_type == SQUARE_TYPE::ENGINE_WEAPON || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED
        || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_BURNED || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_PERFORATED
        || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_BURNED_PERFORATED || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED
        || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_PERFORATED
        || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED){
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
    m_engine->take_care((m_health_pr+care > 1.0f ? 1.0f : care));
    m_health_pr =(m_health_pr+care > 1.0f ? 1.0f : m_health_pr+care);
    if(m_health_pr > 0.0f){
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
