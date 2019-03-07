#include <iostream>
#include "Square.h"
#include "Engine.h"
#include "Grid.h"
#include "Skill.h"
#include "FactorySkill.h"
int main() {
    Engine *e;
    e = new Engine(3,true,1,2,ENGINE_TYPE::BOMBARDIER);
    std::cout<<e->get_current_health_point();

    return 0;
}