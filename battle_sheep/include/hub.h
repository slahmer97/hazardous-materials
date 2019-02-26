#ifndef DEF_HUB
#define DEF_HUB

#include "engine.h"
#include "skill.h"
#include "square.h"
#include "player.h"

class Hub
{
    /*Methods*/
  public:
    //Constructor :
    Hub();

    //Getters :

    //Setters :
    
    /*Attributes*/
  private:
    Square *square_tab[4][10][10];
};

#endif
