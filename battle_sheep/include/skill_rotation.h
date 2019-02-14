#ifndef DEF_ROTATION
#define DEF_ROTATION

#include "grid_server.h"
#include "skill.h"

class Rotation : public Skill
{
    /*Methods*/
  public:
    //Others :
    /* Description : Rotate the engine in a chosen direction.
    Input : The direction.
    Output : - 0 the rotation is not allowed;
             - 1 rotation done. */
    virtual int use(bool clockwise);
};

#endif
