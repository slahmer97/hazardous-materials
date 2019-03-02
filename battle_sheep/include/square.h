#ifndef SQUARE
#define SQUARE

#include "engine.h"

class Engine;

class Square
{

private:

Engine *engine_here;
int depth;
char hazard;     //climate changes (c : cold, t : tempest, n : none ... ?)

public:

Square();
//Square(Engine engine_here_nv, int depth_nv, char hazard_nv);

Engine *get_engine_here();
int get_depth();
char get_hazard();

void set_engine_here(Engine *engine_here_a);
void set_depth(int nv);
void set_hazard(char nv);

void get_infos();

};

#endif
