//
// Created by stevlulz on 3/7/19.
//
#include "../include/FactorySkill.h"

//TODO ====================================

Skill *FactorySkill::getSkill(SHOT_TYPE shot_type, ENGINE_TYPE engine_type) {
    if(shot_type == SHOT_TYPE::PORTE_AVION_SKILL){
        return new Skill_porte_avion(engine_type);
    }
    return nullptr;
}
Skill *FactorySkill::getSkill(ENGINE_TYPE engine_type) {
    if(engine_type == ENGINE_TYPE::PORTE_AVION){
        return new Skill_porte_avion(ENGINE_TYPE::PORTE_AVION);
    }
    else if(engine_type == ENGINE_TYPE::RECONNAISSANCE){
        return new Skill_reconnaissance();
    }
    else if(engine_type == ENGINE_TYPE::PATROUILE){
        return new Skill_patrouille();
    }
    else if(engine_type == ENGINE_TYPE::BROUILLEUR){
        return new Skill_brouilleur();
    }
    else if(engine_type == ENGINE_TYPE::INTERCEPTEUR){
        return new Skill_intercepteur();
    }
    else if(engine_type == ENGINE_TYPE::TORPILLEUR){
        return new Skill_torpilleur();
    }
    else if(engine_type == ENGINE_TYPE::CUIRASSE){
        return new Skill_cuirasse();
    }
    else if(engine_type == ENGINE_TYPE::CROISEUR){
        return new Skill_croiseur();
    }
    else if(engine_type == ENGINE_TYPE::BOMBARDIER){
        return new Skill_bombardier();
    }
    else if(engine_type == ENGINE_TYPE::CONTRE_TORPILLEUR){
        return new Skill_contre_torpilleur();
    }
    else
        return nullptr;
}
