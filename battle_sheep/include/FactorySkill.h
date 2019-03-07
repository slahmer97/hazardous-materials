//
// Created by stevlulz on 3/7/19.
//

#ifndef TMP_PROJ_FACTORYSKILL_H
#define TMP_PROJ_FACTORYSKILL_H
#include "enum.h"
#include "Skill.h"

class Skill;

class FactorySkill {


public:
    static Skill *getSkill(SHOT_TYPE,ENGINE_TYPE);
    static Skill *getSkill(SHOT_TYPE);
};


#endif //TMP_PROJ_FACTORYSKILL_H
