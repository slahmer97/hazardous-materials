#ifndef DEF_NORMAL_SHOT
#define DEF_NORMAL_SHOT

#include "grid_server.h"
#include "skill.h"

class Normal_Shot : public Skill
{
    /*Methods*/
  public:
    //Constructor :
    Normal_Shot(bool unlimited_a, bool used_a);

    /* Description : Try to damage one grid's square, if successful can be use
    again.
    Input : x and y location of the grid's square.
    Output : - 0 if missed;
             - 1 if successful. */
    virtual int use(int x_location, int y_location);
};

#endif
