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
    //~Grid();
    
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

    /* Input : int x,y (position), float damage
    * Make a damage to a position (Square) of the grid and burns it
    * Output : 1 hit, else 0 (miss or is not a position)
    */
    //int incendiary_shot(int x, int y, float damage = 1.f);
    
    /* Input : int x,y (position)
    * Burns the square at this position
    * Output : 1 success (something here to desactibvate), else 0
    */
    //int burn_square(int x, int y);

        /* Input : int x,y (position), float damage
    * Make a damage to a position (Square) of the grid and perforates it
    * Output : 1 hit, else 0 (miss or is not a position)
    */
    //int perforating_shot(int x, int y, float damage = 1.f);

    /* Input : int x,y (position)
    * Perforates the square at this position
    * Output : 1 success (something here to desactibvate), else 0
    */
    //int perforate_square(int x, int y);
    
    /* Input : int x,y (position)
    * Desactivate a weapon or a motor (of an engine) at this position
    * Output : 1 success (something here to desactibvate), else 0
    */
    int desactivate_square(int x, int y);

    /* Input : int length x,y(position), bool IEM,horizontal, float damage
    * Shot or Desactivate (IEM) on a line from the posistion (x,y) for length with the 
    * orientation (horizontal) and make a damage (for each Square in the trajectory)
    * Output : Number of cases hit
    */
    int line_shot(int x, int y, int length, bool IEM, bool horizontal, float damage = 1.f);

    /* Input : int length x,y(position), bool IEM, float damage
    * Shot or Desactivate (IEM) on a vertical line from the posistion (x,y) for 
    * length and make a damage (for each Square in the trajectory)
    * Output : Number of cases hit
    */
    int vertical_line_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    /* Input : int length x,y(position), bool IEM, float damage
    * Shot or Desactivate (IEM) on a horizontal line from the posistion (x,y) for 
    * length and make a damage (for each Square in the trajectory)
    * Output : Number of cases hit
    */
    int horizontal_line_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    /* Input : int length,large x,y(position), bool IEM, float damage
    * Shot or Desactivate (IEM) on a recantgular area of dimension large (vertical) 
    * and length (horizontal) from the posistion (x,y) and make a damage (for 
    * each Square in the trajectory)
    * Output : Number of cases hit
    */
    int rectangular_shot(int x, int y, int large, int length, bool IEM, float damage = 1.f);

    /* Input : int length x,y(position), bool IEM, float damage
    * Shot or Desactivate (IEM) a Square at the position (x,y) and make the same
    * for each neighbor (in the 4 directions), number of neighbor in one 
    * direction (length)
    * Output : Number of cases hit
    */
    int cross_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    /* Input : int length x,y(position), bool IEM,horizontal float damage
    * Shot or Desactivate (IEM) each Square meet from the position(x,y) in the
    * direction horizontal until find an engine (or end of the line) and after 
    * hit the next Square (no matter if there is something or not)
    * Output : Number of cases hit (0, 1 or 2)
    */
    int first_to_drawn(int x, int y, bool horizontal, bool IEM, float damage = 1.f);

    /* Input : int x,y (position)
    * Check if the position (x,y) is in the grid
    * Ouput : 1 yes, -1 no
    */
    int check_one_position(int x, int y);
    
    /* Input : Engine, int x,y (position)
    * Return the Square at this position(x,y)
    * Ouput : Square
    */
    Square* radar_one_square(int x, int y);


    /* Input : int length, x,y (position)
    *
    * Output :
    */
    std::vector<Square*> radar_horizontal(int x, int y, int length);

    
    /* Input : int large,length,  x,y (position)
    *
    * Output :
    */
    std::vector<std::vector<Square*>> radar_rectangular(int x, int y, int large, int length);


    /* Input : int player
    * Print grid of the player
    * Output : nothing (print)
    */
    int proximity_check(int x, int y, Engine *engine);
    void display(int player);


    Square* get(int,int);
};

#endif //TMP_PROJ_GRID_H
