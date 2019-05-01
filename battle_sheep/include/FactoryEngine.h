//
// Created by sidahmed on 23.04.19.
//

#ifndef HAZARDOUS_MATERIALS_FACTORYENGINE_H
#define HAZARDOUS_MATERIALS_FACTORYENGINE_H


#include "Engine.h"

class Engine;
class FactoryEngine {

public:
    static Engine* getEngine(ENGINE_TYPE);
    static Engine* getPorteAvionSkill();
    static Engine* getCroiseurSkill();
    static Engine* getContreTorpilleurSkill();
    static Engine* getCuirasseSkill();
    static Engine* getTorpilleurSkill();
    static Engine* getBombardierSkill();
    static Engine* getIntercepteurSkill();
    static Engine* getBrouilleurSkill();
    static Engine* getPatrouileSkill();
    static Engine* getReconnaissanceSkill();
    static Engine* getNormalShot();
};


#endif //HAZARDOUS_MATERIALS_FACTORYENGINE_H
