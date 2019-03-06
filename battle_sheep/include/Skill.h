//
// Created by stevlulz on 3/6/19.
//

#ifndef HAZARDOUS_SKILL_H
#define HAZARDOUS_SKILL_H

#include "grid.h"

class Skill {
    virtual void use() = 0;
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
    virtual int use(Grid* grid, int x,int y,bool horizontal);


};

class Skill_intercepteur: public Skill
{
public:
    virtual int use(Grid* grid, int x,int y,bool horizontal);


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




#endif //HAZARDOUS_SKILL_H
