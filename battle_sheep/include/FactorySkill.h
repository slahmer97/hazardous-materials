//
// Created by stevlulz on 3/7/19.
//

#ifndef TMP_PROJ_FACTORYSKILL_H
#define TMP_PROJ_FACTORYSKILL_H
#include "enum.h"
#include "Skill.h"

class Skill;

class FactorySkill {

private:
    int m_points;
    ENGINE_TYPE m_engine_type;
public:
    FactorySkill(ENGINE_TYPE engine_type);
    FactorySkill(ENGINE_TYPE engine_type,int number_pts);
    /*
     * Calling on this method will decrease the m_points by certain point...don't call it if you're not sure !
     */
    Skill *getSkill(SHOT_TYPE );
    ENGINE_TYPE get_engine_type();

};


#endif //TMP_PROJ_FACTORYSKILL_H
