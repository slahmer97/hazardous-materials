#include "../include/square.h"
#include <iostream>

/*indentation by uncrustify
   https://github.com/uncrustify/uncrustify */

using namespace std;

Square::Square()
{
        depth = 1;
        hazard = 'n'; //n for neutral
}

/*Engine *get_engine_here()
   {
   cout << "Meh" << '\n';
   } */

int Square::get_depth()
{
        return depth;
}

char Square::get_hazard()
{
        return hazard;
}

/*void set_engine_here(Engine *engine_here_a)
   {
    cout << "Meh" << '\n';
   } */

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


/*int main()
   {
        Square* s1 = new Square();

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
   } */
