#include "../include/engine.h"

Engine::Engine(int size_a, bool horizontal_a, int x_a, int y_a, SkillFactory *engine_skill)
{
    m_size=size_a;
    m_horizontal=horizontal_a;
    m_x=x_a;
    m_y=y_a;
    m_engine_skill=engine_skill;
    m_current_health_point=size_a;
}

//Getters

int Engine::get_size()
{
    return m_size;
}

int Engine::get_current_health_point()
{
    return m_current_health_point;
}

bool Engine::is_horizontal()
{
    return m_horizontal;
}

int Engine::get_x()
{
    return m_x;
}

int Engine::get_y()
{
    return m_y;
}

/*
int Engine::get_grid()
{

}
*/

//Setters
void Engine::set_horizontal(bool horizontal_a)
{
    m_horizontal = horizontal_a;
}
void Engine::set_x(int x_a)
{
    m_x = x_a;
}
void Engine::set_y(int y_a)
{
    m_y=y_a;
}

/*
void Engine::set_grid(int grid_number_a)
{

}
*/

//Methodes
int Engine::take_a_hit(float dammage)
{
    m_current_health_point-=dammage;
    return m_current_health_point;
}


int Engine::normal_shot(Grid *grid, int x, int y)
{
    return grid->normal_shot(x, y);
}

int Engine::Skill_shot(Grid *grid, int x, int y, bool horizontal, SHOT_TYPE type_of_shot)
{

}

int Engine::Skill_shot(Grid *grid1, Grid *grid2, int x, int y, bool horizontal, SHOT_TYPE type_of_shot)
{

}
int Engine::move_engine(Grid *grid, bool reading_direction, int movement_value)
{
    int new_x=m_x;
    int new_y=m_y;

    if(m_horizontal)
    {
        new_x+=( reading_direction ? movement_value : (-movement_value) );
    }
    else
    {
        new_y+=( reading_direction ? movement_value : (-movement_value) );
    }
    

    //if(grid->check_putable())
    {
        //grid->remove_engine();
        grid->add_engine(this,new_x,new_y,m_engine_skill->get_engine_type());
        m_x=new_x;
        m_y=new_y;
        return 1;
    }
    return -1;
}

int Engine::rotate_engine(Grid *grid ,bool clockwise, int node_distance)
{
    
}