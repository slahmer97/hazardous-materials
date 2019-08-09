//
// Created by sidahmed on 23.04.19.
//

#include "FactoryEngine.h"

Engine *FactoryEngine::getPorteAvionSkill() {
    auto* ret = new Engine(5,PORTE_AVION);
    return ret;
}

Engine *FactoryEngine::getCroiseurSkill() {
    auto* ret = new Engine(4,CROISEUR);
    return ret;
}

Engine *FactoryEngine::getContreTorpilleurSkill() {
    auto* ret = new Engine(3,CONTRE_TORPILLEUR);
    return ret;
}

Engine *FactoryEngine::getCuirasseSkill() {
    auto* ret = new Engine(2,CUIRASSE);
    return ret;
}

Engine *FactoryEngine::getTorpilleurSkill() {
    auto* ret = new Engine(2,TORPILLEUR);
    return ret;
}

Engine *FactoryEngine::getBombardierSkill() {
    auto* ret = new Engine(4,BOMBARDIER);
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

Engine *FactoryEngine::getPatrouileSkill() {
    auto* ret = new Engine(2,PATROUILE);
    return ret;
}

Engine *FactoryEngine::getReconnaissanceSkill() {
    auto* ret = new Engine(2,RECONNAISSANCE);
    return ret;
}

Engine *FactoryEngine::getNormalShot() {
    auto* ret = new Engine(3);
    return ret;
}

Engine *FactoryEngine::getEngine(ENGINE_TYPE type){
    if(type == PORTE_AVION)
        return getPorteAvionSkill();
    else if(type == CROISEUR)
        return getCroiseurSkill();
    else if(type == CONTRE_TORPILLEUR)
        return getContreTorpilleurSkill();
    else if(type == CUIRASSE)
        return getCuirasseSkill();
    else if(type == TORPILLEUR)
        return getTorpilleurSkill();
    else if(type == BOMBARDIER)
        return getBombardierSkill();
    else if(type == INTERCEPTEUR)
        return getIntercepteurSkill();
    else if(type == BROUILLEUR)
        return getBrouilleurSkill();
    else if(type == PATROUILE)
        return getPatrouileSkill();
    else if(type == RECONNAISSANCE)
        return getReconnaissanceSkill();
    else
        return getNormalShot();
}

