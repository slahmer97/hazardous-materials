//
// Created by stevlulz on 3/7/19.
//

#include "Grid.h"

Grid::Grid()
{
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
        {
            grid[i][j] = new Square();
        }
}

/*Methods*/

void Grid::add_engine(Engine *engine, int x, int y, ENGINE_TYPE)
{
    int weapon = rand()%(engine->get_size());
    int motor = weapon;
    while(weapon==motor)
    {
        motor=rand()%(engine->get_size());
    }
    //Horizontal
    if (engine->is_horizontal())
    {

        grid[x + weapon][y]->set_square_type(ENGINE_WEAPON);
        grid[x + motor][y]->set_square_type(ENGINE_MOTOR);
        for (int i = 0; i < engine->get_size(); i++)
        {
            if((i!=weapon)&&(i!=motor))
                grid[x + i][y]->set_square_type(ENGINE_PART);
        }
    }
        //Vertical
    else
    {
        grid[x][y + weapon]->set_square_type(ENGINE_WEAPON);
        grid[x][y + motor]->set_square_type(ENGINE_MOTOR);
        for (int j = 0; j < engine->get_size(); j++)
        {
            if((j!=weapon)&&(j!=motor))
                grid[x][y + j]->set_square_type(ENGINE_PART);
        }
    }
}

int Grid::normal_shot(int x, int y, float damage)
{
    if (x < 0 || x > 9 || y < 0 || y > 9)
    {
        return -1;
    }

    if (!(grid[x][y]->get_square_type() == NONE && grid[x][y]->get_square_type() == ENGINE_DEAD))
    {
        grid[x][y]->get_engine()->take_a_hit(damage);
        grid[x][y]->decrease_health(damage);
        if (grid[x][y]->get_health_pr() == 0)
        {
            grid[x][y]->set_square_type(ENGINE_DEAD);
        }
        return 1;
    }
    return grid[x][y]->decrease_health(damage);
}

int Grid::desactivate_square(int x, int y)
{
    if (x < 0 || x > 9 || y < 0 || y > 9)
    {
        return -1;
    }
    if(grid[x][y]->get_square_type()!=NONE)
    {
        grid[x][y]->desactivate_weapon();
        grid[x][y]->desactivate_motor();
        return 1;
    }
    return -1;
}

int Grid::line_shot(int x, int y, int length, bool IEM, bool horizontal, float damage)
{
    int number_case_touch = 0;
    if (horizontal)
    {
        horizontal_line_shot(x,y,length,IEM,damage);
    }
    else
    {
        vertical_line_shot(x,y,length,IEM,damage);

    }
    return number_case_touch;
}

int Grid::vertical_line_shot(int x, int y, int length, bool IEM, float damage)
{
    int number_case_touch = 0;

    for (int i = y; i < y + length; i++)
    {
        if (IEM)
        {
            number_case_touch+=desactivate_square(x, i);
        }
        else
        {
            number_case_touch += normal_shot(x, i, damage);
        }
    }
    return number_case_touch;
}

int Grid::horizontal_line_shot(int x, int y, int length, bool IEM, float damage)
{
    int number_case_touch = 0;
    for (int i = x; i < x + length; i++)
    {
        if (IEM)
        {
            number_case_touch+=desactivate_square(i, y);
        }
        else
        {
            number_case_touch += normal_shot(i, y, damage);
        }
    }
    return number_case_touch;
}

int Grid::rectangular_shot(int x, int y, int large, int length, bool IEM, float damage)
{
    int number_case_touch = 0;
    for (int j = 0; j < large; j++)
    {
        number_case_touch += horizontal_line_shot(x, y + j, length, IEM, damage);
    }
    return number_case_touch;
}

int Grid::cross_shot(int x, int y, int length, bool IEM, float damage)
{
  int number_case_touch = 0;
  grid[x][y]->increase_health(damage);
  number_case_touch+=horizontal_line_shot(x-length,y,2*length+1,IEM,damage);
  number_case_touch+=vertical_line_shot(x,y-length,2*length+1,IEM,damage);
  return number_case_touch;
}
