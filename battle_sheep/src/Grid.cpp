//
// Created by stevlulz on 3/7/19.
//

#include "../include/Grid.h"

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
        return 0;
    }
    return grid[x][y]->decrease_health(damage);
}

int Grid::desactivate_square(int x, int y)
{
    if (x < 0 || x > 9 || y < 0 || y > 9)
    {
        return 0;
    }
    if(grid[x][y]->get_square_type()!=NONE)
    {
        grid[x][y]->desactivate_weapon();
        grid[x][y]->desactivate_motor();
        return 1;
    }
    return 0;
}

int Grid::line_shot(int x, int y, int length, bool IEM, bool horizontal, float damage)
{
    int number_case_touch = 0;
    if (horizontal)
    {
        number_case_touch+=horizontal_line_shot(x,y,length,IEM,damage);
    }
    else
    {
        number_case_touch+=vertical_line_shot(x,y,length,IEM,damage);

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

int Grid::first_to_drawn(int x, int y, bool direction, bool horizontal, bool IEM, float damage )
{
    int number_case_touch = 0;
    int i;
    int v_i=(direction ? 1 : -1);
    if(horizontal){
        if(IEM){
            for(i=x; (i<10 && i>-1) || !(number_case_touch+=desactivate_square(i,y)); i+=v_i );
            if(i<9 && i>0){
                number_case_touch+=desactivate_square(i+v_i,y);
            }}
        else{
            for(i=x; (i<10 && i>-1) || !(number_case_touch+=normal_shot(i,y,damage)); i+=v_i );
            if(i<9 && i>0){
                number_case_touch+=normal_shot(i+v_i,y,damage);
            }}}
    else{
        if(IEM){
            for(i=y; (i<10 && i>-1) || !(number_case_touch+=desactivate_square(x,i)); i+=v_i );
            if(i<9 && i>0){
                number_case_touch+=desactivate_square(x,i+v_i);
            }}
        else{
            for(i=y; (i<10 && i>-1) || !(number_case_touch+=normal_shot(x,i,damage)); i+=v_i );
            if(i<9 && i>0){
                number_case_touch+=normal_shot(x,i+v_i,damage);
            }}}
    return number_case_touch;
}