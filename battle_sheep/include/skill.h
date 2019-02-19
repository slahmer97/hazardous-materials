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

    /*
    Input : (x,y) location to test
    Output : boolean if it's out of range or not;
    */
    bool out_of_range(int x, int y);

    /*
    Description: a normal shot
    Input : Square pointer [2][10][10], (x,y) location of the shot.
    Output : - 0 missed;
             - 1 successful;
             - 2 successful and drawn
             - (-1) cannot use it.
    */
    int skill_normal_shot(Square *grid[2][10][10], int x, int y, int which_grid, bool scaning, bool IEM);
    /*
    Description: n sub function.
    Input : Square pointer [2][10][10], (x,y) location of the begining and ending
            of the skill.
    Output : - 0 missed;
             - 1 successful;
             - 2 or higher successful and drawn 1up for each drawn engine
             - (-1) cannot use it.
    */
    int skill_vertical_shot(Square *grid[2][10][10], int x, int y_starting,
                            int y_ending, int which_grid, bool scaning, bool IEM);
    int skill_horizontal_shot(Square *grid[2][10][10], int y, int x_starting,
                              int x_ending, int which_grid, bool scaning, bool IEM);
    int skill_line_shot(Square *grid[2][10][10], int x_starting_location,
                        int y_starting_location, int x_ending_location,
                        int y_ending_location, int which_grid, bool scaning, bool IEM);
    int skill_rectangular_shot(Square *grid[2][10][10], int x_starting_location,
                               int y_starting_location, int x_ending_location,
                               int y_ending_location, int which_grid, bool scaning, bool IEM);
    int skill_cross_shot(Square *grid[2][10][10], int x_starting_location,
                         int y_starting_location, int x_ending_location,
                         int y_ending_location, int which_grid, bool scaning, bool IEM);
    int skill_first_to_drawn(Square *grid[2][10][10], int x_starting_location,
                             int y_starting_location, int x_ending_location,
                             int y_ending_location, int which_grid, bool scaning, bool IEM);
    /*
    Description: Generique function for each skill.
    Input : Square pointer [2][10][10], (x,y) location of the begining and ending
            of the skill.
    Output : - 0 missed;
             - 1 successful;
             - 2 or higher successful and drawn 1up for each drawn engine
             - (-1) cannot use it.
    */
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location) = 0;

    /*Attributes*/
  protected:
    bool unlimited;
    bool used;
};

class Skill_porte_avion: public Skill
{
  public:
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location);


};

class Skill_croiseur: public Skill
{
  public:
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location);


};

class Skill_contre_torpilleur: public Skill
{
  public:
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location);


};

class Skill_cuirasse: public Skill
{
  public:
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location);


};

class Skill_torpilleur: public Skill
{
  public:
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location);


};

class Skill_bombardier: public Skill
{
  public:
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location);


};

class Skill_intercepteur: public Skill
{
  public:
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location);


};

class Skill_brouilleur: public Skill
{
  public:
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location);


};

class Skill_patrouille: public Skill
{
  public:
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location);


};

class Skill_reconnaissance: public Skill
{
  public:
    virtual int use(Square *grid[2][10][10], int x_starting_location,
                 int y_starting_location, int x_endind_location,
                 int y_ending_location);


};

#endif
