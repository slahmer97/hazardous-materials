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

int Engine::skill_shot(Square *grid[4][10][10], int x_starting_location,
                       int y_starting_location)
{
    return engine_skill->use(grid, x_starting_location, y_starting_location,
                             engine_grid_number, horizontal);
}

void Engine::move_engine(Square *grid[10][10], bool reading_direction, int movement_value)
{
    put_or_remove_engine_on_grid(grid, false);
    int *location = (horizontal ? &x_location : &y_location);
    *location += (reading_direction ? movement_value : (-movement_value));
    // Si ca marche pas j'ai l'ancienne version
    /*
    if (horizontal)
    {
        x_location = x_location +
                     (reading_direction ? movement_value : (-movement_value));
    }
    else
    {
        y_location = y_location +
                     (reading_direction ? movement_value : (-movement_value));
    }
    */
    put_or_remove_engine_on_grid(grid, true);
}

void Engine::rotate_engine(Square *grid[10][10], bool clockwise,
                           int node_distance)
{
    put_or_remove_engine_on_grid(grid, false);

    int normal_add = node_distance * (horizontal ? 1 : (-1));
    int spec_add = (initial_health_point - 1 - node_distance) *
                   (horizontal ? 1 : (-1));

    x_location += ((!horizontal && clockwise) ? spec_add : normal_add);
    y_location += ((horizontal && !clockwise) ? spec_add : normal_add);

    horizontal = !horizontal;

    put_or_remove_engine_on_grid(grid, true);
}

int Engine::normal_shot(Square *grid[10][10], int x_location, int y_location)
{
    return engine_skill->skill_normal_shot(grid, x_location, y_location, 1, false);
}

void Engine::put_or_remove_engine_on_grid(Square *grid[10][10], bool put)
{
    Engine *pointer = (put ? this : NULL);
    int location = (horizontal ? x_location : y_location);
    for (int i = location; i < (location + initial_health_point); i++)
    {
        grid[(horizontal ? i : x_location)][(horizontal ? y_location : i)]
            ->set_engine_here(pointer);
    }
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
int Engine::get_engine_grid_number()
{
    return engine_grid_number;
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
void Engine::set_engine_grid_number(int engine_grid_number_a)
{
    engine_grid_number = engine_grid_number_a;
}