#include <iostream>
#include "../include/Square.h"
#include "../include/Engine.h"
#include "../include/Grid.h"
#include "../include/Skill.h"
#include "../include/FactorySkill.h"
int main() {
   Grid* grid = new Grid();
    auto *e = new Engine(3,true,0,0,ENGINE_TYPE::PORTE_AVION);
   grid->add_engine(e,0,0,PORTE_AVION);

    return 0;
}