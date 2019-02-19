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
int Skill::skill_normal_shot(Square *grid[2][10][10], int x, int y, int which_grid, bool scaning, bool IEM)
{
    if(!(scaning)&& !(IEM))
    {
        Engine *hited_square=grid[which_grid][x%10][y%10]->get_engine_here();
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
    else
    {
        if(scaning)
        {
            Engine *scanned_square=grid[which_grid][x%10][y%10]->get_engine_here();
            if(&scanned_square!=NULL)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(IEM)
        {
            Skill *iem_square=grid[which_grid][x%10][y%10]->get_engine_here()->get_engine_skill();

            if(&iem_square!=NULL)
            {
                iem_square->set_used(true);
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    
}

int Skill::skill_vertical_shot(Square *grid[2][10][10], int x, int y_starting,
                                    int y_ending, int which_grid, bool scaning, bool IEM)
{
    int res=0;
    int one_shot=0;
    res=skill_normal_shot(grid, x, y_starting, which_grid,scaning,IEM);
    for(int i = y_starting+1 ; i<=y_ending; i++)
    {
        one_shot=skill_normal_shot(grid, x, i, which_grid,scaning,IEM);
        if (!(scaning)&& !(IEM))
        {
            if(res<2)
            {
                res=one_shot;
            }
            else if(one_shot==2)
            {
                res++;
            }
        }
        else
        {
            res+=one_shot;
        }
    }
    return res;
}

int Skill::skill_horizontal_shot(Square *grid[2][10][10], int y, int x_starting,
                                    int x_ending, int which_grid, bool scaning, bool IEM)
{
    int res=0;
    int one_shot=0;
    res=skill_normal_shot(grid, x_starting, y, which_grid,scaning,IEM);
    for(int i = x_starting+1 ; i<=x_ending; i++)
    {
        one_shot=skill_normal_shot(grid, i, y, which_grid,scaning,IEM);
        if (!(scaning)&& !(IEM))
        {
            if(res<2)
            {
                res=one_shot;
            }
            else if(one_shot==2)
            {
                res++;
            }
        }
        else
        {
            res+=one_shot;
        }
    }
    return res;
}
int Skill::skill_line_shot(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location, int which_grid, bool scaning, bool IEM)
{

    if(x_starting_location==x_ending_location)
    {
        return skill_vertical_shot(grid,x_starting_location,y_starting_location,
                                       y_ending_location,which_grid,scaning,IEM);
    }
    if(y_starting_location==y_ending_location)
    {
        
        return skill_horizontal_shot(grid,y_starting_location,x_starting_location,
                                    x_ending_location,which_grid,scaning,IEM);
        
    }
}
int Skill::skill_rectangular_shot(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location, int which_grid, bool scaning, bool IEM)
{
    int res=0;
    int one_line_shot;
    res=skill_horizontal_shot(grid,y_starting_location,x_starting_location,
                              x_ending_location,0,scaning,IEM);
    for(int i=y_starting_location+1; i<=y_ending_location; i++)
    {
        one_line_shot=skill_horizontal_shot(grid,i,x_starting_location,
                                        x_ending_location,0,scaning,IEM);
        if(!(scaning)&& !(IEM))
        {
            if(res<2)
            {
                res=one_line_shot;
            }
            else if(one_line_shot>=2)
            {
                res+=(one_line_shot-1);
            }
        }
        else
        {
            res+=one_line_shot;
        }
        
    }
    return res;
}

int Skill::skill_cross_shot(Square *grid[2][10][10], int x_starting_location,
                            int y_starting_location, int x_ending_location,
                            int y_ending_location, int which_grid, bool scaning, bool IEM)
{
    int res=0;
    int restemp=0;
    res+=skill_horizontal_shot(grid,y_starting_location,
                               x_starting_location+1,x_ending_location,
                               which_grid,scaning,IEM);
    restemp=skill_horizontal_shot(grid,y_starting_location,
                               x_starting_location-1,
                               2*x_starting_location-x_ending_location,
                               which_grid,scaning,IEM);
    if(!(scaning)&& !(IEM))
    {
        if(restemp>=2 && res>=2)
        {
            restemp--;
            res+=restemp;
        }
        else
        {
            res=max(restemp,res);
        }
    }
    else
    {
        res+=restemp;
    }
    restemp=skill_vertical_shot(grid,y_starting_location,
                             2*x_starting_location-x_ending_location,
                             x_ending_location,
                             which_grid,scaning,IEM);
    if(!(scaning)&& !(IEM))
    {
        if(restemp>=2 && res>=2)
        {
            restemp--;
            res+=restemp;
        }
        else
        {
            res=max(restemp,res);
        }
    }
    else
    {
        res+=restemp;
    }
    return res;
}

int Skill::skill_first_to_drawn(Square *grid[2][10][10], int x_starting_location,
                             int y_starting_location, int x_ending_location,
                             int y_ending_location, int which_grid, bool scaning, bool IEM)
{
    int res=0;
    if(x_starting_location==x_ending_location)
    {
        if(y_starting_location==y_ending_location)
        {
            return -1;
        }
        if(y_starting_location<y_ending_location)
        {
            for(int i=0; i<10; i++)
            {
                res=skill_normal_shot(grid,x_starting_location,i,which_grid,scaning,IEM);
                if(res>0)
                {
                    res+=skill_normal_shot(grid,x_starting_location,i+1,which_grid,scaning,IEM);
                    break;
                }
            }
        }
        if(y_starting_location>y_ending_location)
        {
            for(int i=9; i>=0; i--)
            {
                res=skill_normal_shot(grid,x_starting_location,i,which_grid,scaning,IEM);
                if(res>0)
                {
                    res+=skill_normal_shot(grid,x_starting_location,i-1,which_grid,scaning,IEM);
                    break;
                }
            }

        }
    }
    else if(y_starting_location==y_ending_location)
    {
        if(x_starting_location==x_ending_location)
        {
            return -1;
        }
        if(x_starting_location<x_ending_location)
        {
            for(int i=0; i<10; i++)
            {
                res=skill_normal_shot(grid,i,y_starting_location,which_grid,scaning,IEM);
                if(res>0)
                {
                    res+=skill_normal_shot(grid,i+1,y_starting_location,which_grid,scaning,IEM);
                    break;
                }
            }
        }
        if(x_starting_location>x_ending_location)
        {
            for(int i=9; i>=0; i--)
            {
                res=skill_normal_shot(grid,i,y_starting_location,which_grid,scaning,IEM);
                if(res>0)
                {
                    res+=skill_normal_shot(grid,i-1,y_starting_location,which_grid,scaning,IEM);
                    break;
                }
            }

        }
    }
    else
        return -1;
    
    return res;
}

int Skill_porte_avion::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(is_used())
    {
        return -1;
    }
    set_used(true);
    return skill_line_shot(grid,x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,1,false,false);
}
int Skill_croiseur::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(is_used())
    {
        return -1;
    }
    set_used(true);
    return skill_line_shot(grid,x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,0,false,false);

}
int Skill_contre_torpilleur::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(is_used())
    {
        return -1;
    }
    set_used(true);
    return skill_rectangular_shot(grid,x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,0,false,false);
}
int Skill_cuirasse::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(is_used())
    {
        return -1;
    }
    set_used(true);
    return skill_cross_shot(grid,x_starting_location,
               y_starting_location,x_ending_location,
               y_ending_location,0,false,false);
}
int Skill_torpilleur::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(is_used())
    {
        return -1;
    }
    set_used(true);
    return skill_first_to_drawn(grid,x_starting_location,
               y_starting_location,x_ending_location,
               y_ending_location,0,false,false);
}
int Skill_bombardier::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(is_used())
    {
        return -1;
    }
    set_used(true);
    int res=0;
    int restemp=0;
    res=skill_rectangular_shot(grid,x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,0,false,false);
    restemp=skill_rectangular_shot(grid,x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,1,false,false);
    if(restemp>=2 && res>=2)
    {
        restemp--;
        res+=restemp;
    }
    else
    {
        res=max(restemp,res);
    }
    return res;
}
int Skill_intercepteur::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(is_used())
    {
        return -1;
    }
    set_used(true);
    int res=0;
    int restemp=0;
    res=skill_line_shot(grid,x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,0,false,false);
    restemp=skill_line_shot(grid,x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,1,false,false);
    if(restemp>=2 && res>=2)
    {
        restemp--;
        res+=restemp;
    }
    else
    {
        res=max(restemp,res);
    }
    return res;
}
int Skill_brouilleur::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(is_used())
    {
        return -1;
    }
    set_used(true);
    return skill_rectangular_shot(grid,x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,0,false,true);

}
int Skill_patrouille::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(is_used())
    {
        return -1;
    }
    set_used(true);
    int res=0;
    res=skill_rectangular_shot(grid,x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,0,true,false);
    res+=skill_rectangular_shot(grid,x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,1,true,false);

}
int Skill_reconnaissance::use(Square *grid[2][10][10], int x_starting_location,
               int y_starting_location, int x_ending_location,
               int y_ending_location)
{
    if(is_used())
    {
        return -1;
    }
    set_used(true);
    return skill_first_to_drawn(grid,x_starting_location,
               y_starting_location,x_ending_location,
               y_ending_location,1,false,false);

}