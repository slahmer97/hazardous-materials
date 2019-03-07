#include <iostream>
#include "../include/Square.h"
#include "../include/Engine.h"
#include "../include/Grid.h"
#include "../include/Skill.h"
#include "../include/FactorySkill.h"
int main() {
    Engine *e;
    e = new Engine(3,true,1,2);
    std::cout<<e->get_current_health_point();

    return 0;
}