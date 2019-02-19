#include "../include/skill.h"

using namespace std;

Skill::Skill(bool unlimited_a, bool used_a)
    : unlimited(unlimited_a),
      used(used_a)
{
}
bool Skill::is_unlimited()
{
    return unlimited;
}
bool Skill::is_used()
{
    return used;
}

//Setters :
void Skill::set_unlimited(bool unlimited_a)
{
    unlimited=unlimited_a;
}
void Skill::set_used(bool used_a)
{
    used=used_a;
}
bool Skill::out_of_range(int x, int y)
{
    if(x<0 || x>9 || y<0 || y>9)
        return true;
    else
        return false;
}
int Skill::skill_normal_shot(Square *grid[2][10][10], int x, int y, int which_grid)
{
    Engine *hited_square=grid[which_grid][x][y]->get_engine_here;
    if(&hited_square!=NULL)
    {
        hited_square->take_a_hit();
        if(hited_square->get_current_health_point()==0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
        //same players turn
    }
    else
    {
        return 0;
        //next players turn
    }
    
}

int Skill::skill_vertical_shot(Square *grid[2][10][10], int x, int y_starting,
                                    int y_ending, int which_grid)
{
    int res=0;
    int one_shot=0;
    res=skill_normal_shot(grid, x, y_starting, which_grid);
    for(int i = y_starting+1 ; i<=y_ending; i++)
    {
        one_shot=skill_normal_shot(grid, x, i, which_grid);
        if(res<2)
        {
            res=one_shot;
        }
        else if(one_shot==2)
        {
            res++;
        }
    }
    return res;
}

int Skill::skill_horizontal_shot(Square *grid[2][10][10], int y, int x_starting,
                                    int x_ending, int which_grid)
{
    int res=0;
    int one_shot=0;
    res=skill_normal_shot(grid, x_starting, y, which_grid);
    for(int i = x_starting+1 ; i<=x_ending; i++)
    {
        one_shot=skill_normal_shot(grid, i, y, which_grid);
        if(res<2)
        {
            res=one_shot;
        }
        else if(one_shot==2)
        {
            res++;
        }
    }
    return res;
}
int Skill_porte_avion::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(x_starting_location==x_ending_location)
    {
        if( !(out_of_range(x_starting_location,y_starting_location)) &&
            !(out_of_range(x_ending_location,y_ending_location)))
        {
            return skill_vertical_shot(grid,x_starting_location,y_starting_location,
                                       y_ending_location,1);
        }
        else if(out_of_range(x_starting_location,y_starting_location)&&
                out_of_range(x_ending_location,y_ending_location))
        {
            return -1;
        }
        else if(out_of_range(x_starting_location,y_starting_location))
        {
            while(out_of_range(x_starting_location,y_starting_location))
            {
                y_starting_location++;
            }
            return skill_vertical_shot(grid,x_starting_location,y_starting_location,
                                       y_ending_location,1);
        }
        else if(out_of_range(x_ending_location,y_ending_location))
        {
            while(out_of_range(x_ending_location,y_ending_location))
            {
                y_ending_location--;
            }
            return skill_vertical_shot(grid,x_starting_location,y_starting_location,
                                       y_ending_location,1);
        }
    }
    if(y_starting_location==y_ending_location)
    {
        if( !(out_of_range(x_starting_location,y_starting_location)) &&
            !(out_of_range(x_ending_location,y_ending_location)))
        {
            return skill_horizontal_shot(grid,y_starting_location,x_starting_location,
                                         x_ending_location,1);
        }
        else if(out_of_range(x_starting_location,y_starting_location)&&
                out_of_range(x_ending_location,y_ending_location))
        {
            return -1;
        }
        else if(out_of_range(x_starting_location,y_starting_location))
        {
            while(out_of_range(x_starting_location,y_starting_location))
            {
                x_starting_location++;
            }
            return skill_horizontal_shot(grid,y_starting_location,x_starting_location,
                                       x_ending_location,1);
        }
        else if(out_of_range(x_ending_location,y_ending_location))
        {
            while(out_of_range(x_ending_location,y_ending_location))
            {
                x_ending_location--;
            }
            return skill_horizontal_shot(grid,y_starting_location,x_starting_location,
                                       x_ending_location,1);
        }
    }
}
int Skill_croiseur::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_endind_location,
               int y_ending_location)
{

}
int Skill_contre_torpilleur::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_endind_location,
               int y_ending_location)
{

}
int Skill_cuirasse::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_endind_location,
               int y_ending_location)
{

}
int Skill_torpilleur::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_endind_location,
               int y_ending_location)
{

}
int Skill_bombardier::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_endind_location,
               int y_ending_location)
{

}
int Skill_intercepteur::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_endind_location,
               int y_ending_location)
{

}
int Skill_brouilleur::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_endind_location,
               int y_ending_location)
{

}
int Skill_patrouille::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_endind_location,
               int y_ending_location)
{

}
int Skill_reconnaissance::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_endind_location,
               int y_ending_location)
{

}