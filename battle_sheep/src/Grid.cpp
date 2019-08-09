//
// Created by stevlulz on 3/7/19.
//
#include <iostream>
#include <boost/lexical_cast.hpp>
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
int Grid::proximity_check(int x, int y, Engine *engine)
{
    if(engine==nullptr)
        return -100;
    if(check_one_position(x,y)==-1)
    {
        return -1;
    }
    if(grid[x][y]->get_engine()!=nullptr || grid[x][y]->get_square_type()!=NONE)
    {
        if(grid[x][y]->get_engine()!=engine){
            return -1;
        }
    }
    return 1;
}

Engine *Grid::get_engine_x_y(int x, int y)
{
    if(check_one_position(x,y)==-1)
    {
        return nullptr;
    }
    return grid[x][y]->get_engine();
}
int Grid::check_putable(Engine *engine, bool horizontal, int x, int y)
{
    if(engine==nullptr)
        return -100;
    for(int i=0 ; i < engine->get_size() ; i++)
    {
        if(horizontal)
        {
            if(proximity_check(x+i, y, engine)<=-1)
                return -1;
        }
        else
        {
            if(proximity_check(x, y+i, engine)<=-1)
                return -1;
        }
    }
    return 1;
}
int Grid::remove_engine(Engine *engine)
{
    if(engine==nullptr)
        return -100;
    if(engine->get_is_on_grid()==false)
        return -1;
    for (int i = 0; i < engine->get_size(); i++)
    {
        //Horizontal
        if (engine->is_horizontal())
        {

            grid[engine->get_x() + i][engine->get_y()]->set_engine(nullptr);
            grid[engine->get_x() + i][engine->get_y()]->set_square_type(NONE);
        }
            //Vertical
        else
        {
            grid[engine->get_x()][engine->get_y() + i]->set_engine(nullptr);
            grid[engine->get_x()][engine->get_y() + i]->set_square_type(NONE);
        }
    }
    engine->set_is_on_grid(false);
    return 1;
}
int Grid::add_engine(Engine *engine, bool horizontal, int x, int y)
{
    if(engine==nullptr)
        return -100;
    if(engine->get_is_on_grid()==true)
        return -1;
    if(check_putable(engine,horizontal,x, y)!=1)
        return -1;
    float engine_square_health[engine->get_size()];
    for(int i=0; i<engine->get_size(); i++)
        engine_square_health[i]=1.f;
    if(engine->get_is_on_grid())
    {
        for(int i=0; i<engine->get_size();i++)
        {
            if(engine->is_horizontal())
            {
                engine_square_health[i]=grid[engine->get_x() + i][engine->get_y()]->get_health_pr();
                grid[engine->get_x() + i][engine->get_y()]->set_health_pr(0.f);
            }
            else
            {
                engine_square_health[i]=grid[engine->get_x()][engine->get_y() + i]->get_health_pr();
                grid[engine->get_x()][engine->get_y() + i]->set_health_pr(0.f);
            }
        }
    }
    engine->set_x(x);
    engine->set_y(y);
    engine->set_horizontal(horizontal);
    engine->set_is_on_grid(true);
    //Horizontal
    if (horizontal)
    {
        grid[x + engine->get_weapon_place()][y]->set_square_type(ENGINE_WEAPON);
        grid[x + engine->get_motor_place()][y]->set_square_type(ENGINE_MOTOR);
        for (int i = 0; i < engine->get_size(); i++)
        {
            grid[x + i][y]->set_health_pr(engine_square_health[i]);
            grid[x + i][y]->set_engine(engine);
            if((i!=engine->get_weapon_place())&&(i!=engine->get_motor_place()))
                grid[x + i][y]->set_square_type(ENGINE_PART);
        }
    }
        //Vertical
    else
    {
        grid[x][y + engine->get_weapon_place()]->set_square_type(ENGINE_WEAPON);
        grid[x][y + engine->get_motor_place()]->set_square_type(ENGINE_MOTOR);
        for (int j = 0; j < engine->get_size(); j++)
        {
            grid[x][y + j]->set_health_pr(engine_square_health[j]);
            grid[x][y + j]->set_engine(engine);
            if((j!=engine->get_weapon_place())&&(j!=engine->get_motor_place()))
                grid[x][y + j]->set_square_type(ENGINE_PART);
        }
    }
    return 1;
}

int Grid::normal_shot(int x, int y, float damage)
{
    if(check_one_position(x,y)==-1)
    {
        return 0;
    }
    return grid[x][y]->decrease_health(damage);
}

/*
int Grid::incendiary_shot(int x, int y, float damage)
{
    if(!(check_one_position(x,y)))
    {
        return 0;
    }
    grid[x][y]->burn_square();
    return grid[x][y]->decrease_health(damage);
}

int Grid::perforating_shot(int x, int y, float damage)
{
    if(!(check_one_position(x,y)))
    {
        return 0;
    }
    grid[x][y]->perforate_square();
    return grid[x][y]->decrease_health(damage);
}
*/

int Grid::desactivate_square(int x, int y)
{
    if(!(check_one_position(x,y)))
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
/*
int Grid::burn_square(int x, int y)
{
    if(!(check_one_position(x,y)))
    {
        return 0;
    }
    if(grid[x][y]->get_square_type()!=NONE)
    {
        grid[x][y]->burn_square();
        return 1;
    }
    return 0;
}

int Grid::perforate_square(int x, int y)
{
    if(!(check_one_position(x,y)))
    {
        return 0;
    }
    if(grid[x][y]->get_square_type()!=NONE)
    {
        grid[x][y]->perforate_square();
        return 1;
    }
    return 0;
}
*/
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
    number_case_touch+=horizontal_line_shot(x-length,y,2*length+1,IEM,damage);
    number_case_touch+=vertical_line_shot(x,y-length,length,IEM,damage);
    number_case_touch+=vertical_line_shot(x,y+1,length,IEM,damage);
    return number_case_touch;
}

int Grid::first_to_drawn(int x, int y, bool horizontal, bool IEM, float damage )
{
    bool direction;
    if(horizontal){
        if(x<5)
        {
            x=0;
            direction=true;
        }
        else
        {
            x=9;
            direction=false;
        }
    }
    else
    {
        if(y<5)
        {
            y=0;
            direction=true;
        }
        else
        {
            y=9;
            direction=false;
        }
    }

    int number_case_touch = 0;
    int i;
    int v_i=(direction ? 1 : -1);
    if(horizontal){
        if(IEM){
            for(i=x; i<10 && i>-1; i+=v_i ){
                number_case_touch+=desactivate_square(i,y);
                if(number_case_touch==1)
                    break;
            }
            if(i<9 && i>0){
                number_case_touch+=desactivate_square(i+v_i,y);
            }}
        else{
            for(i=x; i<10 && i>-1; i+=v_i ){
                number_case_touch+=normal_shot(i,y,damage);
                if(number_case_touch==1)
                    break;
            }
            if(i<9 && i>0){
                number_case_touch+=normal_shot(i+v_i,y,damage);
            }}}
    else{
        if(IEM){
            for(i=y; i<10 && i>-1; i+=v_i ){
                number_case_touch+=desactivate_square(x,i);
                if(number_case_touch==1)
                    break;
            }
            if(i<9 && i>0){
                number_case_touch+=desactivate_square(x,i+v_i);
            }}
        else{
            for(i=y; i<10 && i>-1; i+=v_i ){
                number_case_touch+=normal_shot(x,i,damage);
                if(number_case_touch==1)
                    break;
            }
            if(i<9 && i>0){
                number_case_touch+=normal_shot(x,i+v_i,damage);
            }}}
    return number_case_touch;
}

int Grid::check_one_position(int x, int y)
{
    if (x < 0 || x > 9 || y < 0 || y > 9)
    {
        return -1;
    }
    return 1;
}


/*
int Grid::proximity_check(int x, int y, Engine *engine)
{
    if(engine==nullptr)
        return -100;
    if(!(check_one_position(x,y)))
    {
        return -1;
    }
    int i=x-1;
    int j=y-1;
    int i_end=x+1;
    int j_end=y+1;

    if(x-1<0)i=x;
    if(x+1>9)i_end=x; 
    if(y-1<0)j=y;
    if(y+1>9)j_end=y;
    
    for(i;i<(i_end+1);i++)
    {
        for(j;j<(j_end+1);j++)
        {
            if(grid[i][j]->get_engine()!=nullptr || grid[i][j]->get_square_type()!=NONE)
            {
                if(grid[i][j]->get_engine()->get_engine_type()!=engine->get_engine_type())
                    return -1;
            }
        }
    }
    return 1;
}*/
/*
Square* Grid::radar_one_square(int x, int y)
{
    return grid[x][y];
}

std::vector<Square*> Grid::radar_horizontal(int x, int y, int length)
{
    std::vector<Square*> result;
    for(int i=0;i<length;i++)
    {
        result.push_back(radar_one_square(x+i,y));
    }
    return result;
}
*/
Grid *Grid::radar_rectangular(int x, int y, int large, int length)
{
    Grid * bigresult=new Grid();
    SQUARE_TYPE type;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            type=grid[i][j]->get_square_type();
            if(type==ENGINE_WEAPON_DEAD||type==ENGINE_PART_DEAD||type==ENGINE_MOTOR_DEAD)
                bigresult->grid[i][j]->set_square_type(type);
        }
    }

    for(int i=0;i<length;i++)
    {
        for(int j=0;j<large;j++)
        {
            if(check_one_position(x,y)!=-1)
            {
                bigresult->grid[x + i][y + j]->set_square_type(grid[x + i][y + j]->get_square_type());
            }
        }
    }
    return bigresult;
}

void static print_one_line_gride(int i,Square *grid[10][10], bool hide)
{
    std::cout << i << " ";
    for (int j = 0; j < 10; j++)
    {
        std::cout << "│";
        if (grid[j][i]->get_engine() == nullptr)
        {
            std::cout << "    ";
        }
        else
        {
            if (!(hide))
            {
                std:: cout << grid[j][i]->get_engine()->get_size()
                           << "_"
                           << grid[j][i]->get_health_pr();
                SQUARE_TYPE type = grid[j][i]->get_square_type();
                if(type==ENGINE_MOTOR || type ==ENGINE_MOTOR_DEAD || type == ENGINE_MOTOR_DESACTIVATED)
                    std:: cout << 'M';
                if(type==ENGINE_WEAPON || type ==ENGINE_WEAPON_DEAD || type == ENGINE_WEAPON_DESACTIVATED)
                    std:: cout << 'W';
                if(type==ENGINE_PART || type ==ENGINE_PART_DEAD)
                    std:: cout << 'P';

            }
            else if (grid[j][i]->get_engine()->get_current_health_point()==0.f)
            {
                std::cout << " XX ";
            }
            else
            {
                std::cout << "    ";
            }
        }
    }
}

void static print_grid(int player, Square *grid[10][10], bool hide)
{
    std::cout << "player : " << player;

    std::cout << '\n';

    std::cout << "    0    1    2    3    4    5    6    7    8    9     " << '\n';

    for (int i = 9; i >= 0; i--)
    {
        std::cout << "  ┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼ " << '\n';

        print_one_line_gride(i, grid,  hide);

        std::cout << "│ ";

        std::cout << " " << i << '\n';
    }
    std::cout << "  ┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼ " << '\n';

    std::cout << "    0    1    2    3    4    5    6    7    8    9     " << '\n';


}

void Grid::display(int player) {

    print_grid(player,grid,false);

}

Square *Grid::get(int x,int y) {
    return grid[x][y];
}

std::string Grid::to_priv(){

    std::string ret;
    for (int i = 0; i < 10 ; ++i) {
        for (int j = 0; j < 10; ++j){
            int id = (get(i,j)->get_engine() != nullptr) ? get(i,j)->get_engine()->get_id() : 0;
            float health = get(i,j)->get_health_pr();
            SQUARE_TYPE  squareType = get(i,j)->get_square_type();
            std::string square_str = std::to_string(id)+std::string(";")+std::to_string(health)+std::string(";")+Square::square_type_to_string(squareType);
            ret +=square_str;
            if(j != 9)
                ret += std::string("\t");
        }
        ret += std::string("\n");

    }

    return ret;
}

std::string Grid::to_pub(){
    std::string ret;
    for (int i = 0; i < 10 ; ++i) {
        for (int j = 0; j < 10; ++j){
            SQUARE_TYPE  squareType;
            if( get(i,j)->get_square_type() == ENGINE_WEAPON_DEAD ||  get(i,j)->get_square_type() == ENGINE_MOTOR_DEAD ||  get(i,j)->get_square_type()== ENGINE_PART_DEAD)
                squareType =  get(i,j)->get_square_type();
            else
                squareType = NONE;


            std::string square_str = std::to_string(0)+std::string(";")+std::to_string(0)+std::string(";")+Square::square_type_to_string(squareType);
            ret +=square_str;
            if(j != 9)
                ret += std::string("\t");
        }
        ret += std::string("\n");

    }

    return ret;}
