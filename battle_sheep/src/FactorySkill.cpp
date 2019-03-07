//
// Created by stevlulz on 3/7/19.
//


#include "FactorySkill.h"

Skill *FactorySkill::getSkill(SHOT_TYPE) {
    return nullptr;
}

ENGINE_TYPE FactorySkill::get_engine_type() {
    return m_engine_type;
}

FactorySkill::FactorySkill(ENGINE_TYPE engine_type) {
    m_engine_type = engine_type;
    m_points = 30;
}

FactorySkill::FactorySkill(ENGINE_TYPE engine_type, int number_pts) {
    m_points = number_pts;
    m_engine_type = engine_type;
}

