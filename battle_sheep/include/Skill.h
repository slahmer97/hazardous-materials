//
// Created by stevlulz on 3/7/19.
//

#ifndef TMP_PROJ_SKILL_H
#define TMP_PROJ_SKILL_H

#include "Grid.h"
#include "Square.h"
#include <iostream>
#include <vector>
class Grid;
class Engine;

class Skill
{
  private:
    int m_points;
    ENGINE_TYPE m_engine_type;

  public:
    Skill(ENGINE_TYPE);
    int decrease_points(int dec);
    int increase_points(int inc);
    int get_points();
    virtual int use(Grid *grid, int x, int y, bool horizontal = true) = 0;
    virtual int use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal = true) = 0;
    ENGINE_TYPE get_engine_type();
    ENGINE_TYPE shot_type_to_engine_type(SHOT_TYPE shot);
    SHOT_TYPE engine_type_to_shot_type(ENGINE_TYPE engine);
    int engine_type_is_shot_type(SHOT_TYPE shot);

public:
    static std::string shot_type_to_string(SHOT_TYPE shot);
    static SHOT_TYPE shot_type_to_type(const std::string& shot);
};

class Skill_porte_avion : public Skill
{
  public:
    Skill_porte_avion();
    Skill_porte_avion(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal);
    int use(Grid *grid1, Grid *grid2, int x, int y, bool horizontal);
};

class Skill_croiseur : public Skill
{
  public:
    Skill_croiseur();
    Skill_croiseur(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal);
    int use(Grid *grid, Grid *grid2, int x, int y, bool horizontal);
};

class Skill_contre_torpilleur : public Skill
{
  public:
    Skill_contre_torpilleur();
    Skill_contre_torpilleur(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal);
    int use(Grid *grid, Grid *grid2, int x, int y, bool horizontal);
};

class Skill_cuirasse : public Skill
{
  public:
    Skill_cuirasse();
    Skill_cuirasse(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal);
    int use(Grid *grid, Grid *grid2, int x, int y, bool horizontal);
};

class Skill_torpilleur : public Skill
{
  public:
    Skill_torpilleur();
    Skill_torpilleur(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal);
    int use(Grid *grid, Grid *grid2, int x, int y, bool horizontal);
};

class Skill_bombardier : public Skill
{
  public:
    Skill_bombardier();
    Skill_bombardier(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal = true);
    int use(Grid *grid, Grid *grid2, int x, int y, bool horizontal = true);
};

class Skill_intercepteur : public Skill
{
  public:
    Skill_intercepteur();
    Skill_intercepteur(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal);
    int use(Grid *grid, Grid *grid2, int x, int y, bool horizontal);
};

class Skill_brouilleur : public Skill
{
  public:
    Skill_brouilleur();
    Skill_brouilleur(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal);
    int use(Grid *grid, Grid *grid2, int x, int y, bool horizontal);
};

class Skill_patrouille : public Skill
{
  public:
    Skill_patrouille();
    Skill_patrouille(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal);
    int use(Grid *grid, Grid *grid2, int x, int y, bool horizontal);
    std::vector<std::vector<Square *>> use(Grid *grid, int x, int y);
};

class Skill_reconnaissance : public Skill
{
  public:
    Skill_reconnaissance();
    Skill_reconnaissance(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal);
    int use(Grid *grid, Grid *grid2, int x, int y, bool horizontal);
};

class Skill_incendiary : public Skill
{
    Skill_incendiary();
    /*Skill_incendiary(ENGINE_TYPE);
    int use(Grid *grid, int x, int y, bool horizontal);
    int use(Grid *grid, Grid *grid2, int x, int y, bool horizontal);
*/};
#endif //TMP_PROJ_SKILL_H
