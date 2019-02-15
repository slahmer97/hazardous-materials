#include "../include/engine.h"

using namespace std;

Engine::Engine(int initial_health_point_a, string engine_name_a,
               bool horizontal_a, int x_location_a, int y_location_a,
               Skill *engine_skill_a)
    : initial_health_point(initial_health_point_a),
      current_health_point(initial_health_point_a),
      engine_name(engine_name_a), horizontal(horizontal_a),
      x_location(x_location_a), y_location(y_location_a),
      engine_skill(engine_skill_a)
{
}

int Engine::take_a_hit()
{
    return (--current_health_point);
}

int Engine::skill_shot()
{
    return engine_skill->use();
}