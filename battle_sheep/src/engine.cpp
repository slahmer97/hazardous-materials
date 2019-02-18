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

// Getters :
int Engine::get_initial_health_point()
{
    return initial_health_point;
}
int Engine::get_current_health_point()
{
    return current_health_point;
}
std::string Engine::get_engine_name()
{
    return engine_name;
}
bool Engine::is_horizontal()
{
    return horizontal;
}
int Engine::get_x_location()
{
    return x_location;
}
int Engine::get_y_location()
{
    return y_location;
}
Skill *Engine::get_engine_skill()
{
    return engine_skill;
}

// Setters :
void Engine::set_initial_health_point(int initial_health_point_a)
{
    initial_health_point = initial_health_point_a;
}
void Engine::set_current_health_point(int current_health_point_a)
{
    current_health_point = current_health_point_a;
}
void Engine::set_engine_name(std::string engine_name_a)
{
    engine_name = engine_name_a;
}
void Engine::set_horizontal(bool horizontal_a)
{
    horizontal = horizontal_a;
}
void Engine::set_x_location(int x_location_a)
{
    x_location = x_location_a;
}
void Engine::set_y_location(int y_location_a)
{
    y_location = y_location_a;
}
void Engine::set_engine_skill(Skill *engine_skill_a)
{
    engine_skill = engine_skill_a;
}