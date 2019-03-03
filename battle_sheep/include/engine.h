#ifndef DEF_ENGINE
#define DEF_ENGINE

#include <string>
#include "skill.h"
#include "square.h"

class Skill;
class Square;

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
           Skill *engine_skill_a, int engine_grid_number);

    //Getters :
    int get_initial_health_point();
    int get_current_health_point();
    std::string get_engine_name();
    bool is_horizontal();
    int get_x_location();
    int get_y_location();
    Skill *get_engine_skill();
    int get_engine_grid_number();

    //Setters :
    void set_initial_health_point(int initial_health_point_a);
    void set_current_health_point(int current_health_point_a);
    void set_engine_name(std::string engine_name_a);
    void set_horizontal(bool horizontal_a);
    void set_x_location(int x_location_a);
    void set_y_location(int y_location_a);
    void set_engine_skill(Skill *engine_skill_a);
    void set_engine_grid_number(int engine_grid_number_a);

    //Others :

    /* Description : Lower current_health_point by one.
    Input : None.
    Output : current_health_point. */
    int take_a_hit();

    /* Description : Use engine_skill.
    Input : Square pointer [4][10][10], (x,y) location of the begining and 
            ending of the skill.
    Output : - 0 missed;
             - 1 successful;
             - 2 or higher successful and drawn 1up for each drawn engine
             - (-1) cannot use it. */
    int skill_shot(Square *grid[4][10][10], int x_starting_location,
                   int y_starting_location, bool horiz);

    /* Description : Move the engine.
    Input : The grid and direction and the number of square moved.
    Output : None. */
    bool move_engine(Square *grid[10][10], bool reading_direction, int movement_value);

    /* Description :
    Input : The grid and direction of the rotation.
    Output : None. */
    bool rotate_engine(Square *grid[10][10], bool clockwise,
                       int node_distance);

    /* Description : Damage a location.
    Input : The square that is focus.
    Output : - 0 nothing damaged;
             - 1 something damaged but still alive;
             - 2 something damaged and drawn.*/
    int normal_shot(Square *grid[10][10], int x_location, int y_location);

    /* Description : Put or remove this engine of the grid.
    Input : A bool to know if we must put it or remove it.
    Output : None. */
    bool put_or_remove_engine_on_grid(Square *grid[10][10], bool put);

    //Others :
    /* Description : Check that all the squares around a segment are ok.
    Input : a grid number to "fire" it, (x,y) where skill begin and (x,y) where
            it end.
    Output : - true, there is something around;
             - false, nothing is around. */
    bool proximity_check(Square *grid[10][10]);

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
    int engine_grid_number;
};

#endif
