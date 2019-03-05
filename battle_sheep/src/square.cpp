#include "../include/square.h"
#include <iostream>

/*indentation by uncrustify
   https://github.com/uncrustify/uncrustify */

using namespace std;

Square::Square() // no arguments
{
        depth = 1;
        hazard = 'n'; //n for neutral
        engine_here = NULL;
        engine_dead = false;
}

Engine *Square::get_engine_here()
{
	return this->engine_here;
}
bool Square::get_engine_death()
{
	return this->engine_dead;
}

int Square::get_depth()
{
        return depth;
}

char Square::get_hazard()
{
        return hazard;
}

void Square::set_engine_here(Engine *engine_here_a)
{
        this->engine_here = engine_here_a;
}

void Square::set_engine_death(bool engine_dead_a)
{
        this->engine_dead = engine_dead_a;
}

void Square::set_depth(int nv) //nv = newvalue or nouveau
{
        if(nv >= 0 && nv <= 10) //standard range values
                depth = nv;
        else
                nv = 1; //default value
}

void Square::set_hazard(char nv)
{
        switch(nv) {
        case 'n': hazard = 'n'; //neutral
                break;
        case 'c': hazard = 'c'; //cold
                break;
        case 'w': hazard = 'w'; //wind
                break;
        case 't': hazard = 't'; //thunder
                break;

        default: hazard = 'n'; //nothing found -> neutral
                break;
        }

}

void Square::get_infos()
{
        cout << "depth : " << get_depth() << '\n';
        cout << "hazard : " << get_hazard() << '\n';
        //cout << "engine : " << get_engine_here() << '\n';
}

/*
int main()
{
        Square *s1 = new Square();

        cout << s1->get_depth() << '\n';
        cout << s1->get_hazard() << '\n';

        s1->set_depth(52);
        cout << s1->get_depth() << '\n';

        s1->set_depth(10);
        cout << s1->get_depth() << '\n';

        s1->set_hazard('w');

        cout << s1->get_hazard() << '\n';

        cout << "Running fine" << '\n';

        delete(s1);
}
*/