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

    //Setters :
    void set_engine_here(Engine *engine_here_a);

    /*Attributes*/
  private:
    Engine *engine_here;
};

#endif
