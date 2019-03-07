//
// Created by stevlulz on 3/7/19.
//


#include <FactorySkill.h>

#include "FactorySkill.h"

//TODO ====================================

Skill *FactorySkill::getSkill(SHOT_TYPE shot_type, ENGINE_TYPE engine_type) {
    if(shot_type == SHOT_TYPE::PORTE_AVION_SKILL){
        return new Skill_porte_avion(engine_type);
    }
    return nullptr;
}

Skill *FactorySkill::getSkill(SHOT_TYPE shot_type) {
    if(shot_type == SHOT_TYPE::PORTE_AVION_SKILL){
        return new Skill_porte_avion(ENGINE_TYPE::PORTE_AVION);
    }
    return nullptr;
}
