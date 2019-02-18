#ifndef DEF_SQUARE
#define DEF_SQUARE

#include "engine.h"

class Square
{
    /*Methods*/
  public:
    //Constructor :
    Square();

    //Getters :
    Engine *get_engine_here();
    int get_depth();
    char get_hazard();

    //Setters :
    void set_engine_here(Engine *engine_here_a);
    void set_depth(int nv);
    void set_hazard(char nv);

    /*Attributes*/
  private:

    Engine *engine_here;
    int depth;
    char hazard; //climate changes (c : cold, t : tempest, n : none ... ?)

};

#endif
