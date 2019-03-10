//
// Created by stevlulz on 3/7/19.
//

#ifndef TMP_PROJ_ENGINE_H
#define TMP_PROJ_ENGINE_H


#include "enum.h"
#include "Grid.h"
#include "FactorySkill.h"

class Grid;
class Skill;

srand(time(nullptr));

class Engine {

public:

    Engine(int size_a);
    Engine(int size_a,ENGINE_TYPE engine_type);


    int get_size();
    float get_current_health_point();
    bool is_horizontal();
    int get_x();
    int get_y();
    int get_motor_place();
    int get_weapon_place();

    //Setters :
    void set_horizontal(bool horizontal_a);
    void set_x(int x_a);
    void set_y(int y_a);

    void add_skill(ENGINE_TYPE engine_type,SHOT_TYPE shot_type);

    float take_a_hit(float dammage);
    float take_care(float care);

    int normal_shot(Grid *grid, int x, int y);

    int Skill_shot(Grid *grid, int x, int y, bool horizontal, SHOT_TYPE type_of_shot);
    int Skill_shot(Grid *grid1, Grid *grid2, int x, int y, bool horizontal, SHOT_TYPE type_of_shot);


    int move_engine(Grid *grid, bool reading_direction, int movement_value);


    int rotate_engine(Grid *grid ,bool clockwise, int node_distance);


    void desactivate_motor();
    void desactivate_weapon();
    void activate_motor();
    void activate_weapon();
    void kill_weapon();
    void kill_motor();

    ENGINE_TYPE get_engine_type();


private:
    int m_size;
    float m_current_health_point;
    bool m_horizontal;
    int m_movement_point;
    int m_motor_place;
    int m_weapon_place;
    int m_x;
    int m_y;
    Skill *m_skill;
    MOTOR_STATE m_motor_state;
    WEAPON_STATE m_weapon_state;
};


#endif //TMP_PROJ_ENGINE_H
