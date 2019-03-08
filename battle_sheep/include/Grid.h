//
// Created by stevlulz on 3/7/19.
//

#ifndef TMP_PROJ_GRID_H
#define TMP_PROJ_GRID_H

#include <iostream>

#include <cstdlib>
#include <ctime>
#include "Engine.h"
#include "Square.h"
#include "enum.h"

class Square;
class Engine;
class Grid
{
private:
    Square *grid[10][10];
    Square getSquare(int x, int y);

public:
    Grid();
    ~Grid();

    void add_engine(Engine *engine, bool horizontal, int x, int y);

    int normal_shot(int x, int y, float damage = 1.f);

    int desactivate_square(int x, int y);

    int line_shot(int x, int y, int length, bool IEM, bool horizontal, float damage = 1.f);

    int vertical_line_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    int horizontal_line_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    int rectangular_shot(int x, int y, int large, int length, bool IEM, float damage = 1.f);

    int cross_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    int first_to_drawn(int x, int y, bool direction, bool horizontal, bool IEM, float damage = 1.f);

    int proximity_check(int x, int y, Engine *engine);

    std::string get_my_grid();
    std::string get_enemy_grid();
};

#endif //TMP_PROJ_GRID_H
