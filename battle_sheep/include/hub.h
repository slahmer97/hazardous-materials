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

    //Others :
    /* Description : Check that all the squares around a segment are ok.
    Input : a grid number to "fire" it, (x,y) where skill begin and (x,y) where
            it end.
    Output : - true, there is something around;
             - false, nothing is around. */
    bool proximity_check(Square *grid[10][10], int x_starting_location,
                         int y_starting_location, int x_endind_location,
                         int y_ending_location);

    /*Attributes*/
  private:
    Square *square_tab[4][10][10];
};

#endif
