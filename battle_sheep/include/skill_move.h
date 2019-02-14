#ifndef DEF_MOVE
#define DEF_MOVE

#include "grid_server.h"
#include "skill.h"

class Move : public Skill
{
    /*Methods*/
  public:
    //Others :
    /* Description : Move the engine in a chosen direction.
    Input : The direction and square's number of the move.
    Output : - 0 the movement is not allowed;
             - 1 movement done. */
    virtual int use(bool reading_direction, int move_value);
};

#endif
