#include "grid.h"

Grid::Grid()
    :
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
    grid[x][y]->set_square_type(ENGINE_WEAPON);
    //Horizontal
    if (engine->is_horizontal())
    {
        grid[x + 1][y]->set_square_type(ENGINE_MOTOR);
        for (int i = x + 2; i <= x + engine->get_size(); i++)
        {
            grid[i][y]->set_square_type(ENGINE_PART);
        }
    }
    //Vertical
    else
    {
        grid[x][y + 1]->set_square_type(ENGINE_MOTOR);
        for (int j = y + 2; j <= y + engine->get_size(); j++)
        {
            grid[x][j]->set_square_type(ENGINE_PART);
        }
    }
}

int Grid::normal_shot(int x, int y, float dammage = 1.f)
{
    if (x < 0 || x > 9 || y < 0 || y > 9)
    {
        return -1;
    }

    if (!(grid[x][y].get_square_type() == NONE && grid[x][y].get_square_type() == ENGINE_DEAD))
    {
        engine.take_a_hit(dammage);
        grid[x][y].decrease_health(dammage);
        if (grid[x][y].get_health_pr() == 0)
        {
            grid[x][y].set_square_type(ENGINE_DEAD);
            return 1;
        }
        return 2;
    }
    return 0;
}

int Grid::desactivate_square(int x, int y)
{
    if (x < 0 || x > 9 || y < 0 || y > 9)
    {
        return -1;
    }

    if (grid[x][y].get_square_type() == ENGINE_WEAPON)
    {
        grid[x][y].set_square_type(ENGINE_WEAPON_DESACTIVATED);
        return 1;
    }
    if (grid[x][y].get_square_type() == ENGINE_MOTOR)
    {
        grid[x][y].set_square_type(ENGINE_MOTOR_DESACTIVATED);
        return 1;
    }
    return 0;
}

int Grid::line_shot(int x, int y, int length, bool IEM, bool horizontal, float dammage = 1.f)
{
    int number_case_touch = 0;
    if (horizontal)
    {
        for (int j = y; j <= y + length; j++)
        {
            if (IEM)
            {
                grid.desactivitae_square(x, j);
            }
            else
            {
                number_case_touch += grid.normal_shot(x, j);
            }
        }
    }
    else
    {
        for (int i = x; i <= x + length; i++)
        {
            if (IEM)
            {
                grid.desactivitae_square(i, y);
            }
            else
            {
                number_case_touch += grid.normal_shot(i, y);
            }
        }
    }
    return number_case_touch;
}

int Grid::vertical_line_shot(int x, int y, int length, bool IEM, float dammage = 1.f)
{
    int number_case_touch = 0;
    for (int i = x; i <= x + length; i++)
    {
        if (IEM)
        {
            grid.desactivitae_square(i, y);
        }
        else
        {
            number_case_touch += grid.normal_shot(i, y);
        }
    }
    return number_case_touch;
}

int Grid::horizontal_line_shot(int x, int y, int length, bool IEM, float dammage = 1.f)
{
    int number_case_touch = 0;
    for (int j = y; j <= y + length; j++)
    {
        if (IEM)
        {
            grid.desactivitae_square(x, j);
        }
        else
        {
            number_case_touch += grid.normal_shot(x, j);
        }
    }
    return number_case_touch;
}

int Grid::rectangular_shot(int x, int y, int large, int length, bool IEM, float damage = 1.f)
{
    int number_case_touch = 0;
    for (int j = 0; j < large; j++)
    {
        number_case_touch += grid.horizontal_line_shot(x, y + j, length, IEM, damage);
    }
    return number_case_touch;
}
