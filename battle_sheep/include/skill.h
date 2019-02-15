#ifndef DEF_SKILL
#define DEF_SKILL

#include "square.h"

class Skill
{
    /*Methods*/
  public:
    //Constructor :
    Skill(bool unlimited_a, bool used_a);

    //Getters :
    bool is_unlimited();
    bool is_used();

    //Setters :
    void set_unlimited(bool unlimited_a);
    void set_used(bool used_a);

    //Others :
    /* Description :
    Input :
    Output : . */
    virtual int use() = 0;

    /*Attributes*/
  protected:
    bool unlimited;
    bool used;
};

#endif
