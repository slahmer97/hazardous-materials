//
// Created by stevlulz on 3/7/19.
//
#include <boost/lexical_cast.hpp>
#include <Square.h>


Square::Square(){
    m_engine = nullptr;
    m_health_pr = .0f;
    m_square_type = SQUARE_TYPE::NONE;
}

Engine *Square::get_engine(){
    return m_engine;
}

bool Square::squares_equals(Square *T){
    if(T==nullptr)
        return false;
    if(m_engine!=nullptr && T->get_engine()!=nullptr)
        return (m_engine->get_engine_type() == T->get_engine()->get_engine_type() && m_health_pr== T->m_health_pr && m_square_type == T->m_square_type);
    else
        return (m_engine == T->get_engine() && m_health_pr== T->m_health_pr && m_square_type == T->m_square_type);
}

float Square::get_health_pr(){
    return m_health_pr;
}
void Square::desactivate_motor(){
    if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED;
    /*else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_BURNED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED_PERFORATED;*/
}
void Square::desactivate_weapon(){
    if(m_square_type == SQUARE_TYPE::ENGINE_WEAPON)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED;
    /*else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_BURNED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED;*/
}
void Square::activate_weapon(){
    if(m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON;
    /*else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_BURNED_PERFORATED;*/
}
void Square::activate_motor(){
    if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR;
    /*else if (m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED)
        m_square_type = SQUARE_TYPE::ENGINE_MOTOR_BURNED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_PERFORATED;
    else if (m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED)
        m_square_type = SQUARE_TYPE::ENGINE_WEAPON_BURNED_PERFORATED;*/

}
/*
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
*/
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
       m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DEAD || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DEAD)
        return 0;

    if(dammage<0.0f )
        return 0;
    
    m_engine->take_a_hit(dammage);
    if(m_health_pr > dammage){
        m_health_pr -=dammage;
    }
    else{
        m_health_pr = 0;
        if(m_square_type == SQUARE_TYPE::ENGINE_MOTOR || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED /*||
        m_square_type == SQUARE_TYPE::ENGINE_MOTOR_BURNED || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_PERFORATED
        || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_BURNED_PERFORATED || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED
        || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_PERFORATED || m_square_type == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED_BURNED_PERFORATED*/){
            m_engine->kill_motor();
            m_square_type = SQUARE_TYPE ::ENGINE_MOTOR_DEAD;
        }
        else if(m_square_type == SQUARE_TYPE::ENGINE_WEAPON || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED
        /*|| m_square_type == SQUARE_TYPE::ENGINE_WEAPON_BURNED || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_PERFORATED
        || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_BURNED_PERFORATED || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED
        || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_PERFORATED
        || m_square_type == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED_BURNED_PERFORATED*/){
            m_engine->kill_weapon();
            m_square_type = SQUARE_TYPE::ENGINE_WEAPON_DEAD;
        }else{
            m_square_type = SQUARE_TYPE ::ENGINE_PART_DEAD;
        }
    }
    return 1;
}

int Square::increase_health(float care){
    if(m_engine == nullptr || m_square_type == SQUARE_TYPE::NONE)
        return 0;
    if(care<0.0f)
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

std::string Square::to_pri_string(){
    std::string engine = std::string("Eng : ")+std::string((m_engine == nullptr) ? "null" : std::to_string(m_engine->get_id()));
    std::string ret = std::string("SQ_H:")+boost::lexical_cast<std::string>(m_health_pr)+","
            +std::string("SQ_T:")+square_type_to_string(m_square_type)+","+engine;
    return ret;
}

std::string Square::to_pub_string() {
    return std::__cxx11::string();
}

std::string Square::square_type_to_string(SQUARE_TYPE s) {
    if(s == SQUARE_TYPE::ENGINE_MOTOR)
        return "em";
    if(s == SQUARE_TYPE::ENGINE_MOTOR_DEAD)
        return "emd";
    if(s == SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED)
        return "emds";
    if(s == SQUARE_TYPE::ENGINE_PART)
        return "ep";
    if(s == SQUARE_TYPE::ENGINE_PART_DEAD)
        return "epd";
    if(s == SQUARE_TYPE::ENGINE_WEAPON)
        return "ew";
    if(s == SQUARE_TYPE::ENGINE_WEAPON_DEAD)
        return "ewd";
    if(s == SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED)
        return "ewds";

    return "n";
}
SQUARE_TYPE Square::square_type_to_enum(const std::string &s){
    if(s == "em")
        return SQUARE_TYPE::ENGINE_MOTOR;
    if(s == "emd")
        return SQUARE_TYPE::ENGINE_MOTOR_DEAD;
    if(s == "emds")
        return  SQUARE_TYPE::ENGINE_MOTOR_DESACTIVATED;
    if(s == "ep")
        return SQUARE_TYPE::ENGINE_PART;
    if(s == "epd")
        return SQUARE_TYPE::ENGINE_PART_DEAD;
    if(s == "ew")
        return SQUARE_TYPE::ENGINE_WEAPON;
    if(s == "ewd")
        return SQUARE_TYPE::ENGINE_WEAPON_DEAD;
    if(s == "ewds")
        return SQUARE_TYPE::ENGINE_WEAPON_DESACTIVATED;


    return NONE;
}
