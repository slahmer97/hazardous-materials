//
// Created by sidahmed on 23.04.19.
//

#include "FactoryEngine.h"

Engine *FactoryEngine::getPorteAvionSkill() {
    //TODO check size
    auto* ret = new Engine(4,PORTE_AVION);
    return ret;
}

Engine *FactoryEngine::getCroiseurSkill() {
    auto* ret = new Engine(3,CROISEUR);
    return ret;
}

Engine *FactoryEngine::getContreTorpilleurSkill() {
    auto* ret = new Engine(3,CONTRE_TORPILLEUR);
    return ret;
}

Engine *FactoryEngine::getBombardierSkill() {
    auto* ret = new Engine(3,BOMBARDIER);
    return ret;
}

Engine *FactoryEngine::getIntercepteurSkill() {
    auto* ret = new Engine(3,INTERCEPTEUR);
    return ret;
}

Engine *FactoryEngine::getBrouilleurSkill() {
    auto* ret = new Engine(3,BROUILLEUR);
    return ret;
}

Engine *FactoryEngine::getReconnaissanceSkill() {
    auto* ret = new Engine(3,RECONNAISSANCE);
    return ret;
}

Engine *FactoryEngine::getNormalShot() {
    auto* ret = new Engine(3);
    return ret;
}

Engine *FactoryEngine::getEngine(ENGINE_TYPE type){
    if(type == RECONNAISSANCE)
        return getReconnaissanceSkill();
    else if(type == BROUILLEUR)
        return getBrouilleurSkill();
    else if(type == INTERCEPTEUR)
        return getIntercepteurSkill();
    else if(type == BOMBARDIER)
        return getBombardierSkill();
    else if(type == CONTRE_TORPILLEUR)
        return getContreTorpilleurSkill();
    else if(type == CROISEUR)
        return getCroiseurSkill();
    else if(type == PORTE_AVION)
        return getPorteAvionSkill();


    return getNormalShot();
}

