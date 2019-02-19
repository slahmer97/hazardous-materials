#ifndef DEF_ENGINE
#define DEF_ENGINE

#include <string>
#include "skill.h"

class Engine
{
    /*Methods*/
  public:
    //Constructor :
    /* Description : Create an engine.
    Input : Engine's initial health point, name, if the engine is horizontal or
            not, grid to find it, x coordinate, y coordinate, skill name.
    Output : An engine with equal initial and current health point,
             a directtion, a grid, a (x,y) location and a skill shot. */
    Engine(int initial_health_point_a, std::string engine_name_a,
           bool horizontal_a, int x_location_a, int y_location_a,
           Skill *engine_skill_a);

    //Getters :
    int get_initial_health_point();
    int get_current_health_point();
    std::string get_engine_name();
    bool is_horizontal();
    int get_x_location();
    int get_y_location();
    Skill *get_engine_skill();
    Square *get_engine_grid();

    //Setters :
    void set_initial_health_point(int initial_health_point_a);
    void set_current_health_point(int current_health_point_a);
    void set_engine_name(std::string engine_name_a);
    void set_horizontal(bool horizontal_a);
    void set_x_location(int x_location_a);
    void set_y_location(int y_location_a);
    void set_engine_skill(Skill *engine_skill_a);
    void set_engine_grid(Square *engine_grid_a);

    //Others :

    /* Description : Lower current_health_point by one.
    Input : None.
    Output : current_health_point. */
    int take_a_hit();

    /* Description : Use engine_skill.
    Input : Square pointer [2][10][10], (x,y) location of the begining and ending
            of the skill.
    Output : - 0 missed;
             - 1 successful;
             - 2 or higher successful and drawn 1up for each drawn engine
             - (-1) cannot use it. */
    int skill_shot(Square *grid[2][10][10], int x_starting_location,
                   int y_starting_location, int x_endind_location,
                   int y_ending_location);

    /* Description : Move the engine.
    Input : The direction and the number of square moved.
    Output : None. */
    void move_engine(bool reading_direction, int movement_value);

    /* Description :
    Input : The direction of the rotation.
    Output : None. */
    void rotate_engine(bool clockwise);

    /* Description : Damage a location.
    Input : The square that is focus.
    Output : - 0 nothing damaged;
             - 1 something damaged but still alive;
             - 2 something damaged and drawn.*/
    int normal_shot(Square *grid[2][10][10], int x, int y, int which_grid);

    /*Attributes*/
  private:
    int initial_health_point;
    int current_health_point;
    std::string engine_name;
    bool horizontal;
    int grid_number;
    int x_location;
    int y_location;
    Skill *engine_skill;
    Square *engine_grid;
};

#endif
