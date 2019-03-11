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
    Grid();
    ~Grid();

    int check_putable(Engine *engine, bool horizontal, int size, int x, int y);

    int remove_engine(Engine *engine);

    int add_engine(Engine *engine, bool horizontal, int x, int y);

    int normal_shot(int x, int y, float damage = 1.f);

    int desactivate_square(int x, int y);

    int line_shot(int x, int y, int length, bool IEM, bool horizontal, float damage = 1.f);

    int vertical_line_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    int horizontal_line_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    int rectangular_shot(int x, int y, int large, int length, bool IEM, float damage = 1.f);

    int cross_shot(int x, int y, int length, bool IEM, float damage = 1.f);

    int first_to_drawn(int x, int y, bool direction, bool horizontal, bool IEM, float damage = 1.f);

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
