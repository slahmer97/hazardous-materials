#ifndef SQUARE
#define SQUARE

#include "engine.h"
#include "enum.h"

class Engine;

class Square
{

private:
  Engine *m_engine;
  SQUARE_TYPE m_square_type;
  float m_health_pr;
  //int depth;
  //char hazard; //climate changes (c : cold, t : tempest, n : none ... ?)

public:
  Square();
  //Square(Engine engine_here_nv, int depth_nv, char hazard_nv);

  Engine *get_engine();
  float get_health_pr();
  void desactivate_motor();
  void desactivate_weapon();
  void activate_weapon();
  void activate_motor();
  SQUARE_TYPE get_square_type();
  // int get_depth();
  // char get_hazard();

  void set_engine(Engine *engine_a);
  void set_health_pr(float pr);
  void set_square_type(SQUARE_TYPE square_type);
  //void set_depth(int nv);
  //void set_hazard(char nv);
  //void get_infos();
};

#endif
