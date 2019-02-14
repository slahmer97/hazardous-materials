#ifndef DEF_ENGINE
#define DEF_ENGINE

#include <string>
#include "game.h"
#include "skill.h"

class Engine
{
    /*Methods*/
  public:
    //Constructor :
    /* Description : Create an engine.
    Input : Engine's initial health point, name, if the engine is horizontal or not, x coordinate, y coordinate, skill name.
    Output : An engine with equal initial and current health point, a directtion, a (x,y) location and a skill shot. */
    Engine(int initial_health_point_a, std::string engine_name_a, bool horizontal_a, int x_location_a, int y_location_a, std::string skill_name_a);

    //Getters :
    int get_initial_health_point();
    int get_current_health_point();
    std::string get_engine_name();
    bool is_horizontal();
    int get_x_location();
    int get_y_location();
    Skill *get_engine_skill();

    //Setters :
    void set_initial_health_point(int initial_health_point_a);
    void set_current_health_point(int current_health_point_a);
    void set_engine_name(std::string engine_name_a);
    void set_horizontal(bool horizontal_a);
    void set_x_location(int x_location_a);
    void set_y_location(int y_location_a);
    void set_engine_skill(Skill *engine_skill_a);

    //Others :

    /* Description : Lower current_health_point by one.
    Input : None.
    Output : current_health_point. */
    int take_a_hit();

    /* Description : Use engine_skill.
    Input : None.
    Output : - 0 if worked but missed;
             - 1 if worked but successful;
             - (-1) if you cannot use it. */
    int skill_shot();

    /*Attributes*/
  private:
    int initial_health_point;
    int current_health_point;
    std::string engine_name;
    bool horizontal;
    int x_location;
    int y_location;
    Skill *engine_skill;
};

#endif
