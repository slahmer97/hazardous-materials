//
// Created by stevlulz on 3/6/19.
//

#ifndef HAZARDOUS_FACTOYSKILL_H
#define HAZARDOUS_FACTOYSKILL_H

#include "enum.h"
#include "Skill.h"
class FactorySkill {

    private:
        int m_points;
        ENGINE_TYPE m_engine_type;
    public:
    /*
     * Calling on this method will decrease the m_points by certain point...don't call it if you're not sure !
     */
    Skill getSkill(SHOT_TYPE );

};


#endif //HAZARDOUS_FACTOYSKILL_H
