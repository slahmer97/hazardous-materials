#ifndef DEF_ENGINE
#define DEF_ENGINE

#include <string>
#include "skill.h"
#include "square.h"
#include "enum.h"

class Skill;
class Square;

class Engine
{

public:
  //Constructor :
  /* Description : Create an engine.
    Input : Engine's initial health point, name, if the engine is horizontal or
            not, grid to find it, x coordinate, y coordinate, skill name.
    Output : An engine with equal initial and current health point,
             a directtion, a grid, a (x,y) location and a skill shot. */
  Engine(int size_a, std::string engine_name_a,
         bool horizontal_a, int x_location_a, int y_location_a,
         ENGINE_TYPE engine_type);

  //Getters :
  int get_size();
  int get_current_health_point();
  std::string get_engine_name();
  bool is_horizontal();
  int get_x_location();
  int get_y_location();
  //add a get_Squares();
  Skill *get_engine_skill();
  int get_grid();

  //Setters :
  void set_horizontal(bool horizontal_a);
  void set_x_location(int x_location_a);
  void set_y_location(int y_location_a);
  void set_grid(int grid_number_a);

  /*Methods*/

  /* Description : Lower current_health_point by a dammage.
    Input : None.
    Output : current_health_point. */
  int take_a_hit(float dammage);

  //Do a normal shot
  int normal_shot(Grid grid, int x, int y);
  //return 0 missing, -1 coodinate false, 1 successed

  //Do a skill shot
  int Skill_shot(Grid grid, int x, int y, bool horizontal, SHOT_TYPE type_of_shot);
  int Skill_shot(Grid grid1, Grid grid2, int x, int y, bool horizontal, SHOT_TYPE type_of_shot);
  //return <-1 the coordante are false, -1 can't do this skill, 0 missing, >0 hit

  /* Description : Move the engine.
    Input : The grid and direction and the number of square moved.
    Output : None. */
  int move_engine(bool reading_direction, bool right, int movement_value);
  // return 1 -> success, minus 1 not possible

  /* Description :
    Input : The grid and direction of the rotation.
    Output : None. */
  int rotate_engine(bool clockwise, int node_distance);
  // return 1 -> success, minus 1 not possible

  /*Attributes*/
private:
  int m_size;
  float m_current_health_point;
  std::string m_engine_name;
  bool m_horizontal;
  int m_movement_point;
  int m_x_location;
  int m_y_location;
  SkillFactory *m_engine_skill;
  ENGINE_TYPE m_engine_type;
};

#endif
