#ifndef DEF_SKILL
#define DEF_SKILL

#include "square.h"

class Skill
{
    /*Methods*/
  public:
    //Constructor :
    Skill(bool unlimited_a, bool used_a, int x_a, int y_a, int a_a, int b_a);

    //Getters :
    bool is_unlimited();
    bool is_used();
    int get_x_location();
    int get_y_location();
    int get_a_location();
    int get_b_location();

    //Setters :
    void set_unlimited(bool unlimited_a);
    void set_used(bool used_a);
    void set_x_location(int x_a);
    void set_y_location(int y_a);
    void set_a_location(int a_a);
    void set_b_location(int b_a);

    //Others :
    /* Description :
    Input :
    Output : . */
    virtual int use() = 0;

    /*Attributes*/
  protected:
    bool unlimited;
    bool used;
    int x;
    int y;
    int a;
    int b;
    Square *destination_grid[10][10];
};

#endif
