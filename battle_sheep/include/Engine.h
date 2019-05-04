//
// Created by stevlulz on 3/7/19.
//

#ifndef TMP_PROJ_ENGINE_H
#define TMP_PROJ_ENGINE_H


#include "enum.h"
#include "Grid.h"
#include "Square.h"
#include "FactorySkill.h"
#include <iostream>
#include <vector>

class Grid;
class Skill;


class Engine {

public:

/* Input : size engine-type
     * Constructors
     * Output : pointer on engine
     */
    Engine(int size_a);
    Engine(int size_a,ENGINE_TYPE engine_type);


    /* Input :/
     * get the size
     * Output : size
     */
    int get_size();

    /* Input : /
     * get the current health point 
     * Output : current health
     */
    float get_current_health_point();

    /* Input : /
     * get the orientation
     * Output : orientation
     */
    int is_horizontal();

    /* Input : /
     * get the x position
     * Output : x position
     */
    int get_x();

    /* Input : /
     * get the y position
     * Output : y position
     */
    int get_y();

    /* Input : /
     * get the motor place in function of the ship size
     * Output : motor place
     */
    int get_motor_place();

    /* Input : /
     * get the weapon place in function of the ship size
     * Output : weapon place
     */
    int get_weapon_place();

    /* Input : /
     * get the boolean that say if the engine is on the gride or not
     * Output : is on the grid ?
     */
    bool get_is_on_grid();

    /* Input : /
     * get the curent motor state
     * Output : motor state
     */
    MOTOR_STATE get_motor_state()const;

    /* Input :
     * get the curent weapon state
     * Output : weapon state
     */
    WEAPON_STATE get_weapon_state()const;
    //PART_STATE get_shell_state()const;
    //Setters :

    /* Input : orientation
     * set the engines orientation
     * Output : /
     */
    void set_horizontal(bool horizontal_a);

    /* Input : x position
     * set the x direction
     * Output : /
     */
    void set_x(int x_a);

    /* Input : y position
     * set the y direction
     * Output : /
     */
    void set_y(int y_a);

    /* Input : is on the grid ?
     * set the boolean that say if the engine is on the gride or not
     * Output : /
     */
    void set_is_on_grid(bool is_on_grid_a);

    /* Input : engine type shot_type
     * associat an engine to a skill
     * Output : /
     */
    void add_skill(ENGINE_TYPE engine_type,SHOT_TYPE shot_type);

    /* Input : dammage
     * the engine take a hit
     * Output : engines curent health points
     */
    float take_a_hit(float dammage);

    /* Input : care
     * the engine is healed
     * Output : engines curent health points
     */
    float take_care(float care);

    /* Input : the grid targeted x and y position
     * a normal shot on the targeted player
     * Output : the number of succesfull hit
     */
    int normal_shot(Grid *grid, int x, int y);

    /* Input : the grid targeted x and y position the direction and the shot type
     * a skill shot on one grid
     * Output : the number of succesfull hit or the number of successful IEM
     */
    int Skill_shot(Grid *grid, int x, int y, bool horizontal, SHOT_TYPE type_of_shot);

    std::vector<std::vector<Square*>> Skill_shot(Grid *grid, int x, int y, SHOT_TYPE type_of_shot);

    /* Input : the grid1 the grid2 targeted x and y position the direction and the shot type
     * a skill shot on two grids
     * Output : hited engines
     */
    int Skill_shot(Grid *grid1, Grid *grid2, int x, int y, bool horizontal, SHOT_TYPE type_of_shot);


    /* Input : the grid the direction the movement value in function of the size
     * move the engine
     * Output : negatif if unsuccessful 1 if successful
     */
    int move_engine(Grid *grid, bool reading_direction, int movement_value);


    /* Input : the grid the orientation the distance in function of the size
     * rotate the engine
     * Output : negatif if unsuccessful 1 if successful
     */
    int rotate_engine(Grid *grid ,bool clockwise, int node_distance);


    /* Input : /
     * desactivate the motor
     * Output : /
     */
    void desactivate_motor();

    /* Input : /
     * desactivate the weapon
     * Output : /
     */
    void desactivate_weapon();

    /* Input : /
     * activate the motor
     * Output : /
     */
    void activate_motor();

    /* Input : /
     * activate the weapon
     * Output : /
     */
    void activate_weapon();

    /* Input : /
     * kill the weapon
     * Output : /
     */
    void kill_weapon();

    /* Input : /
     * kill the motor
     * Output : /
     */
    void kill_motor();

    /* Input : /
     * get the engine type
     * Output : Engine type
     */
    ENGINE_TYPE get_engine_type();

    void set_id(int i);
    int get_id();

private:
    int id;
    int m_size;
    float m_current_health_point;
    bool m_horizontal;
    int m_movement_point;
    int m_motor_place;
    int m_weapon_place;
    int m_x;
    int m_y;
    bool m_is_on_grid;
    Skill *m_skill;
    MOTOR_STATE m_motor_state;
    WEAPON_STATE m_weapon_state;
    /*
    PART_STATE m_shell_state;
    */

public:
    static ENGINE_TYPE engine_type_to_type(const std::string& type);
    static std::string  engine_type_to_string(ENGINE_TYPE type);


};


#endif //TMP_PROJ_ENGINE_H