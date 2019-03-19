//
// Created by stevlulz on 3/7/19.
//

#ifndef TMP_PROJ_GRID_H
#define TMP_PROJ_GRID_H

#include "Engine.h"
#include "Square.h"
#include "enum.h"
#include <vector>

class Square;
class Engine;
class Grid
{
private:
    Square *grid[10][10];
    Square getSquare(int x, int y);

public:
    
    /*Constructor*/
    Grid();
    ~Grid();
    
    /* Input : int x,y (position in the grid)
    *  Return the engine at the position(x,y) in the grid
    * Ouptut : Engine 
    */
    Engine *get_engine_x_y(int x, int y);
    
    /* Input : Engine, bool horizontal (orientation), int size x,y (position)
    * Return a int, to check if an engine is putable at a place (x,y)
    * Ouput : 1 yes, -1 no or -100 is not an engine
    */
    int check_putable(Engine *engine, bool horizontal, int size, int x, int y);


    /* Input : Engine
    * Remove an engine of the grid
    * Output : 1 yes, -100 is not an engine
    */
    int remove_engine(Engine *engine);

    /* Input : Engine, bool horizontal (orientation), int x,y (position)
    * Add an engine in the grid
    * Output : 1 yes, -100 is not an engine
    */
    int add_engine(Engine *engine, bool horizontal, int x, int y);

    /* Input : int x,y (position), float damage
    * Make a damage to a position (Square) of the grid
    * Output : 1 hit, else 0 (miss or is not a position)
    */
    int normal_shot(int x, int y, float damage = 1.f);

    /*
    int incendiary_shot(int x, int y, float damage = 1.f);
    int burn_square(int x, int y);
    */
    
    /* Input : int x,y (position)
    * Desactivate a weapon or a motor (of an engine) at this position
    * Output : 1 success (something here to desactibvate), else 0
    */
    int desactivate_square(int x, int y);

    /* Input : int length x,y(position), bool IEM,horizontal, float damage
    * Shot or Desactivate (IEM) on a line from the posistion (x,y) for length with the 
    * orientation (horizontal) and make a damage (for each Square in the trajectory)
    * Output : Number of the case hit
    */
    int line_shot(int x, int y, int length, bool IEM, bool horizontal, float damage = 1.f);

    int vertical_line_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    int horizontal_line_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    int rectangular_shot(int x, int y, int large, int length, bool IEM, float damage = 1.f);

    int cross_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    int first_to_drawn(int x, int y, bool horizontal, bool IEM, float damage = 1.f);

    int proximity_check(int x, int y, Engine *engine);

    int check_one_position(int x, int y);

    Square* radar_one_square(int x, int y);

    std::vector<Square*> radar_horizontal(int x, int y, int length);

    std::vector<std::vector<Square*>> radar_rectangular(int x, int y, int large, int length);


    std::string get_my_grid();
    std::string get_enemy_grid();


    void display(int player);
};

#endif //TMP_PROJ_GRID_H
