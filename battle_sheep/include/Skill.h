//
// Created by stevlulz on 3/7/19.
//

#ifndef TMP_PROJ_SKILL_H
#define TMP_PROJ_SKILL_H

#include "Grid.h"

class Grid;
class Engine;
class Skill
{
public:
    virtual int use(Grid* grid, int x,int y,bool horizontal) = 0;
};


class Skill_porte_avion: public Skill
{
public:
    virtual int use(Grid* grid, int x,int y,bool horizontal);
};

class Skill_croiseur: public Skill
{
public:
    virtual int use(Grid* grid, int x,int y,bool horizontal);


};

class Skill_contre_torpilleur: public Skill
{
public:
    virtual int use(Grid* grid, int x,int y,bool horizontal);


};

class Skill_cuirasse: public Skill
{
public:
    virtual int use(Grid* grid, int x,int y,bool horizontal);


};

class Skill_torpilleur: public Skill
{
public:
    virtual int use(Grid* grid, int x,int y,bool horizontal);


};

class Skill_bombardier: public Skill
{
public:
    int use(Grid* grid, int x,int y,bool horizontal) override = 0;
    int use(Grid* grid1,Grid* grid2, int x,int y,bool horizontal);



};

class Skill_intercepteur: public Skill
{
public:
    int use(Grid* grid, int x,int y,bool horizontal) override = 0;
    int use(Grid* grid1,Grid* grid2, int x,int y,bool horizontal);

};

class Skill_brouilleur: public Skill
{
public:
    virtual int use(Grid* grid, int x,int y,bool horizontal);



};

class Skill_patrouille: public Skill
{
public:
    virtual int use(Grid* grid, int x,int y,bool horizontal);


};

class Skill_reconnaissance: public Skill {
public:
    virtual int use(Grid *grid, int x, int y, bool horizontal);
};





#endif //TMP_PROJ_SKILL_H
