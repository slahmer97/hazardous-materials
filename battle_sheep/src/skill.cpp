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

//Methodes de Skill

int Skill::skill_normal_shot(Square *grid[10][10], int x, int y, bool damage, bool IEM)
{
    if(x<0 || x>9 || y<0 || y>9)
    {
        return -1;
    }

    Engine *square=grid[x][y]->get_engine_here();

    if(square==NULL)
    {
        return 0;
    }
    else
    {
        if(damage)
        {
            square->take_a_hit();
        }
        if (IEM)
        {
            square->get_engine_skill()->set_used(true);
        }
        return 1;
    }
}


int Skill::skill_vertical_shot(Square *grid[10][10], int x, int y_starting,
                               int y_ending, bool damage, bool IEM)
{
    
    int res=0;
    
    int one_shot=0;
    
    res=skill_normal_shot(grid, x, y_starting, damage,IEM);
    
    for(int i = y_starting+1 ; i<=y_ending; i++)
    {
        
        one_shot=skill_normal_shot(grid, x, i, damage,IEM);
        
        if (damage||IEM)
        {
            if(res<=0)
            {
                res=max(res,one_shot);
            }
        }
        else
        {
            if((res>=0)&&(one_shot>=0))
            {
                res+=one_shot;
            }
            else
            {
                res=max(res,one_shot);
            }
        }
    }
    return res;
}


int Skill::skill_horizontal_shot(Square *grid[10][10], int y, int x_starting,
                                 int x_ending, bool damage, bool IEM)
{
    
    int res=0;
    
    int one_shot=0;
    
    res=skill_normal_shot(grid, x_starting, y,damage,IEM);
    
    for(int i = x_starting+1 ; i<=x_ending; i++)
    {
    
        one_shot=skill_normal_shot(grid, i, y,damage,IEM);

        if (damage||IEM)
        {
            if(res<=0)
            {
                res=max(res,one_shot);
            }
        }
        else
        {
            if((res>=0)&&(one_shot>=0))
            {
                res+=one_shot;
            }
            else
            {
                res=max(res,one_shot);
            }
        }

    }
    return res;
}


int Skill::skill_line_shot(Square *grid[10][10], int x_starting_location,
                           int y_starting_location, int x_ending_location,
                           int y_ending_location, bool damage, bool IEM)
{

    if(x_starting_location==x_ending_location)
    {
        
        return skill_vertical_shot(grid,x_starting_location,y_starting_location,
                                   y_ending_location,damage,IEM);
    
    }
    
    if(y_starting_location==y_ending_location)
    {
        
        return skill_horizontal_shot(grid,y_starting_location,x_starting_location,
                                     x_ending_location,damage,IEM);
        
    }
}


int Skill::skill_rectangular_shot(Square *grid[10][10], int x_starting_location,
                                  int y_starting_location, int x_ending_location,
                                  int y_ending_location, bool damage, bool IEM)
{

    int res=0;

    int one_line_shot;

    res=skill_horizontal_shot(grid,y_starting_location,x_starting_location,
                              x_ending_location,damage,IEM);

    for(int i=y_starting_location+1; i<=y_ending_location; i++)
    {

        one_line_shot=skill_horizontal_shot(grid,i,x_starting_location,
                                            x_ending_location,damage,IEM);
        
        if (damage||IEM)
        {
            if(res<=0)
            {
                res=max(res,one_line_shot);
            }
        }
        else
        {
            if((res>=0)&&(one_line_shot>=0))
            {
                res+=one_line_shot;
            }
            else
            {
                res=max(res,one_line_shot);
            }
        }
    }
    return res;
}


int Skill::skill_cross_shot(Square *grid[10][10], int x_starting_location,
                            int y_starting_location, int x_ending_location,
                            int y_ending_location,bool damage, bool IEM)
{

    int res=0;

    int restemp=0;

    res+=skill_horizontal_shot(grid,y_starting_location,
                               x_starting_location+1,x_ending_location,
                               damage,IEM);

    restemp=skill_horizontal_shot(grid,y_starting_location,
                                  x_starting_location-1,
                                  2*x_starting_location-x_ending_location,
                                  damage,IEM);
    
    if (damage||IEM)
    {
        if(res<=0)
        {
            res=max(res,restemp);
        }
    }
    else
    {
        if((res>=0)&&(restemp>=0))
        {
            res+=restemp;
        }
        else
        {
            res=max(res,restemp);
        }
    }

    restemp=skill_vertical_shot(grid,y_starting_location,
                                2*x_starting_location-x_ending_location,
                                x_ending_location,
                                damage,IEM);
     
    if (damage||IEM)
    {
        if(res<=0)
        {
            res=max(res,restemp);
        }
    }
    else
    {
        if((res>=0)&&(restemp>=0))
        {
            res+=restemp;
        }
        else
        {
            res=max(res,restemp);
        }
    }

    return res;
}


int Skill::skill_first_to_drawn(Square *grid[10][10], int x_starting_location,
                                int y_starting_location, int x_ending_location,
                                int y_ending_location, bool damage, bool IEM)
{

    int res=0;
    int restemp=0;
    if(x_starting_location==x_ending_location)
    {
        if(y_starting_location==y_ending_location)
        {
            return -1;
        }
        bool ltr = y_starting_location<y_ending_location;
        for(int i = (ltr?0:9); (ltr?i<10:i>=0); (ltr?i++:i--))
        {
            res=skill_normal_shot(grid,x_starting_location,
                                  i,damage,IEM);
            if(res==1)
            {
                restemp=skill_normal_shot(grid,x_starting_location,
                                          (ltr?i+1:i-1),damage,IEM);
                if (damage||IEM)
                {
                    res=max(res,restemp);
                }
                else
                {
                    if(restemp>=0)
                    {
                        res+=restemp;
                    }
                    else
                    {
                        res=max(res,restemp);
                    }
                }
                break;
            }
        }
    }
    else if(y_starting_location==y_ending_location)
    {
        if(x_starting_location==x_ending_location)
        {
            return -1;
        }
        bool btt = x_starting_location<x_ending_location;
        for(int i = (btt?0:9); (btt?i<10:i>=0); (btt?i++:i--))
        {
            res=skill_normal_shot(grid,i,y_starting_location,
                                  damage,IEM);
            
            if(res==1)
            {
                restemp=skill_normal_shot(grid,(btt?i+1:i-1),
                                          y_starting_location,
                                          damage,IEM);
                if (damage||IEM)
                {
                    res=max(res,restemp);
                }
                else
                {
                    if(restemp>=0)
                    {
                        res+=restemp;
                    }
                    else
                    {
                        res=max(res,restemp);
                    }
                }
                break;
            }
        }
    }
    else
    {
        return -1;
    }

    return res;
}

//Methode use de chaque skill

int Skill_porte_avion::use(Square *grid[4][10][10], int x_starting_location,
                           int y_starting_location, int x_ending_location,
                           int y_ending_location, int player)
{

    if(is_used())
    {
        return -1;
    }

    set_used(true);

    int which_gride;
    
    if(player<2)
    {
        which_gride=3;
    }
    else
    {
        which_gride=1;
    }
    
    return skill_line_shot(grid[which_gride],x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,true,false);

}


int Skill_croiseur::use(Square *grid[4][10][10], int x_starting_location,
                        int y_starting_location, int x_ending_location,
                        int y_ending_location, int player)
{

    if(is_used())
    {
        return -1;
    }

    set_used(true);

    int which_gride;
    
    if(player<2)
    {
        which_gride=2;
    }
    else
    {
        which_gride=0;
    }

    return skill_line_shot(grid[which_gride],x_starting_location,
                           y_starting_location,x_ending_location,
                           y_ending_location,true,false);

}


int Skill_contre_torpilleur::use(Square *grid[4][10][10], int x_starting_location,
                                 int y_starting_location, int x_ending_location,
                                 int y_ending_location, int player)
{

    if(is_used())
    {
        return -1;
    }

    set_used(true);

    int which_gride;
    
    if(player<2)
    {
        which_gride=2;
    }
    else
    {
        which_gride=0;
    }

    return skill_rectangular_shot(grid[which_gride],x_starting_location,
                                  y_starting_location,x_ending_location,
                                  y_ending_location,true,false);

}


int Skill_cuirasse::use(Square *grid[4][10][10], int x_starting_location,
                        int y_starting_location, int x_ending_location,
                        int y_ending_location, int player)
{

    if(is_used())
    {
        return -1;
    }

    set_used(true);

    int which_gride;
    
    if(player<2)
    {
        which_gride=2;
    }
    else
    {
        which_gride=0;
    }

    return skill_cross_shot(grid[which_gride],x_starting_location,
                            y_starting_location,x_ending_location,
                            y_ending_location,true,false);

}


int Skill_torpilleur::use(Square *grid[4][10][10], int x_starting_location,
                          int y_starting_location, int x_ending_location,
                          int y_ending_location, int player)
{

    if(is_used())
    {
        return -1;
    }

    set_used(true);

    int which_gride;
    
    if(player<2)
    {
        which_gride=2;
    }
    else
    {
        which_gride=0;
    }

    return skill_first_to_drawn(grid[which_gride],x_starting_location,
                                y_starting_location,x_ending_location,
                                y_ending_location,true,false);

}


int Skill_bombardier::use(Square *grid[4][10][10], int x_starting_location,
                          int y_starting_location, int x_ending_location,
                          int y_ending_location, int player)
{

    if(is_used())
    {
        return -1;
    }

    set_used(true);

    int which_gride;

    int which_gride2;
    
    if(player<2)
    {
        which_gride=2;
        which_gride2=3;
    }
    else
    {
        which_gride=0;
        which_gride2=1;
    }

    int res=0;

    int restemp=0;

    res=skill_rectangular_shot(grid[which_gride],x_starting_location,
                               y_starting_location,x_ending_location,
                               y_ending_location,true,false);

    restemp=skill_rectangular_shot(grid[which_gride2],x_starting_location,
                                   y_starting_location,x_ending_location,
                                   y_ending_location,true,false);

    if(restemp>=0 && res>=0)
    {
        res+=restemp;
    }
    else
    {
        res=max(restemp,res);
    }

    return res;
}


int Skill_intercepteur::use(Square *grid[4][10][10], int x_starting_location,
                            int y_starting_location, int x_ending_location,
                            int y_ending_location, int player)
{

    if(is_used())
    {
        return -1;
    }

    set_used(true);

    int which_gride;

    int which_gride2;
    
    if(player<2)
    {
        which_gride=2;
        which_gride2=3;
    }
    else
    {
        which_gride=0;
        which_gride2=1;
    }


    int res=0;

    int restemp=0;

    res=skill_line_shot(grid[which_gride],x_starting_location,
                        y_starting_location,x_ending_location,
                        y_ending_location,true,false);

    restemp=skill_line_shot(grid[which_gride2],x_starting_location,
                            y_starting_location,x_ending_location,
                            y_ending_location,true,false);
    
    if(restemp>=0 && res>=0)
    {
        res+=restemp;
    }
    else
    {
        res=max(restemp,res);
    }

    return res;
}


int Skill_brouilleur::use(Square *grid[4][10][10], int x_starting_location,
                          int y_starting_location, int x_ending_location,
                          int y_ending_location, int player)
{

    if(is_used())
    {
        return -1;
    }

    set_used(true);

    int which_gride;
    
    if(player<2)
    {
        which_gride=2;
    }
    else
    {
        which_gride=0;
    }

    return skill_rectangular_shot(grid[which_gride],x_starting_location,
                                  y_starting_location,x_ending_location,
                                  y_ending_location,false,true);

}


int Skill_patrouille::use(Square *grid[4][10][10], int x_starting_location,
                          int y_starting_location, int x_ending_location,
                          int y_ending_location, int player)
{

    if(is_used())
    {
        return -1;
    }

    set_used(true);

    int which_gride;

    int which_gride2;
    
    if(player<2)
    {
        which_gride=2;
        which_gride2=3;
    }
    else
    {
        which_gride=0;
        which_gride2=1;
    }

    int res=0;
    int restemp=0;
    res=skill_rectangular_shot(grid[which_gride],x_starting_location,
                               y_starting_location,x_ending_location,
                               y_ending_location,false,false);

    restemp=skill_rectangular_shot(grid[which_gride2],x_starting_location,
                                y_starting_location,x_ending_location,
                                y_ending_location,false,false);
    
    if(restemp>=0 && res>=0)
    {
        res+=restemp;
    }
    else
    {
        res=max(restemp,res);
    }

}


int Skill_reconnaissance::use(Square *grid[4][10][10], int x_starting_location,
                              int y_starting_location, int x_ending_location,
                              int y_ending_location, int player)
{

    if(is_used())
    {
        return -1;
    }

    set_used(true);

    int which_gride;
    
    if(player<2)
    {
        which_gride=3;
    }
    else
    {
        which_gride=1;
    }

    return skill_first_to_drawn(grid[which_gride],x_starting_location,
                                y_starting_location,x_ending_location,
                                y_ending_location,true,false);

}