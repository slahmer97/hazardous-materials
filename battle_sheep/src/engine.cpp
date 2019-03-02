#include "../include/engine.h"

using namespace std;

Engine::Engine(int initial_health_point_a, string engine_name_a,
               bool horizontal_a, int x_location_a, int y_location_a,
               Skill *engine_skill_a)
    : initial_health_point(initial_health_point_a),
      current_health_point(initial_health_point_a),
      engine_name(engine_name_a), horizontal(horizontal_a),
      engine_skill(engine_skill_a)
{
    x_location = (x_location_a < 0 ? 0 : x_location_a);
    y_location = (y_location_a > 9 ? 9 : y_location_a);
    if ((x_location_a + ((initial_health_point_a - 1) *
                         (horizontal ? 1 : 0))) > 9)
    {
        x_location = 9 - ((initial_health_point_a - 1) * (horizontal ? 1 : 0));
    }
    if (((y_location_a - ((initial_health_point_a - 1) *
                          (horizontal ? 0 : 1))) < 0))
    {
        y_location = 0 + ((initial_health_point_a - 1) * (horizontal ? 0 : 1));
    }
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

bool Engine::put_or_remove_engine_on_grid(Square *grid[10][10], bool put)
{
    if (proximity_check(grid))
    {
        Engine *pointer = (put ? this : NULL);
        int location = (horizontal ? x_location : y_location);
        for (int i = location; i < (location + initial_health_point); i++)
        {
            grid[(horizontal ? i : x_location)][(horizontal ? y_location : 1)]
                ->set_engine_here(pointer);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Engine::proximity_check(Square *grid[10][10])
{
    int x_min = x_location - 1;
    int x_max = x_location + 1 + ((initial_health_point - 1) * (horizontal ? 1 : 0));
    int y_min = y_location - 1 - ((initial_health_point - 1) * (horizontal ? 0 : 1));
    int y_max = y_location + 1;

    x_min = (x_min < 0 ? 0 : x_min);
    x_min = (x_min > 9 ? 9 : x_min);
    x_max = (x_max < 0 ? 0 : x_max);
    x_max = (x_max > 9 ? 9 : x_max);
    y_min = (y_min < 0 ? 0 : y_min);
    y_min = (y_min > 9 ? 0 : y_min);
    y_max = (y_max < 0 ? 0 : y_max);
    y_max = (y_max > 9 ? 9 : y_max);

    for (int i = x_min; i < x_max; i++)
    {
        for (int j = y_min; j < y_max; j++)
        {
            if (grid[i][j]->get_engine_here() != NULL)
            {
                return false;
            }
        }
    }
    return true;
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