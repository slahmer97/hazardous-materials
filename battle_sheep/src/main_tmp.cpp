#include "./skill.cpp"
#include "./engine.cpp"
#include "./square.cpp"

using namespace std;

void print_grid(int player, Square *grid[10][10], Square *grid2[10][10])
{
    cout << "player :" << player << '\n';
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            cout << "|";
            if(grid[i][j]->get_engine_here()==NULL)
            {
                cout << "00";
            }
            else
            {
                cout << grid[i][j]->get_engine_here()->get_engine_name();
            }
        }
        cout << "|          ";
        for(int j=0; j<10; j++)
        {
            cout << "|";
            if(grid2[i][j]->get_engine_here()==NULL)
            {
                cout << "00";
            }
            else
            {
                cout << grid2[i][j]->get_engine_here()->get_engine_name();
            }
        }
        cout << "|";
        cout << '\n';
        cout << "-------------------------------          -------------------------------" << '\n';
    }
}

int main()
{
    bool horizontal, notgameover=true;
    int x,y;
    Square* grid[4][10][10];

    for(int i=0; i<4; i++)
        for(int j=0; j<10; j++)
            for(int k=0; k<10; k++)
                grid[i][j][k]=new Square();
    
    Engine *all_engines[20];

    for(int i=0;i<2;i++)
    {
        std::system("clear");

        print_grid((i*2)+1,grid[i*2],grid[(i*2)+1]);
        
        cout << "où mêtre le porte avion ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[0+(i*5)]=new Engine(5,"pa",horizontal,x,y,new Skill_porte_avion());
        all_engines[0+(i*5)]->put_or_remove_engine_on_grid(grid[i*2],true);

        std::system("clear");

        print_grid((i*2)+1,grid[i*2],grid[(i*2)+1]);
        
        cout << "où mêtre le croiseur ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[1+(i*5)]=new Engine(4,"cr",horizontal,x,y,new Skill_croiseur());
        all_engines[1+(i*5)]->put_or_remove_engine_on_grid(grid[i*2],true);

        std::system("clear");

        print_grid((i*2)+1,grid[i*2],grid[(i*2)+1]);
        
        cout << "où mêtre le contre torpilleur ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[2+(i*5)]=new Engine(3,"ct",horizontal,x,y,new Skill_contre_torpilleur());
        all_engines[2+(i*5)]->put_or_remove_engine_on_grid(grid[i*2],true);

        std::system("clear");

        print_grid((i*2)+1,grid[i*2],grid[(i*2)+1]);
        
        cout << "où mêtre le cuirasse ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[3+(i*5)]=new Engine(2,"cu",horizontal,x,y,new Skill_cuirasse());
        all_engines[3+(i*5)]->put_or_remove_engine_on_grid(grid[i*2],true);

        std::system("clear");

        print_grid((i*2)+1,grid[i*2],grid[(i*2)+1]);
        
        cout << "où mêtre le torpilleur ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[4+(i*5)]=new Engine(2,"to",horizontal,x,y,new Skill_torpilleur());
        all_engines[4+(i*5)]->put_or_remove_engine_on_grid(grid[i*2],true);
    
    }

    for(int i=0;i<2;i++)
    {
        std::system("clear");

        print_grid((i*2)+1,grid[(i*2)+1],grid[i*2]);
        
        cout << "où mêtre le bombardier? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[10+(i*5)]=new Engine(4,"bo",horizontal,x,y,new Skill_bombardier());
        all_engines[10+(i*5)]->put_or_remove_engine_on_grid(grid[(i*2)+1],true);

        std::system("clear");

        print_grid((i*2)+1,grid[(i*2)+1],grid[i*2]);
        
        cout << "où mêtre le intercepteur ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[11+(i*5)]=new Engine(3,"in",horizontal,x,y,new Skill_intercepteur());
        all_engines[11+(i*5)]->put_or_remove_engine_on_grid(grid[(i*2)+1],true);

        std::system("clear");

        print_grid((i*2)+1,grid[(i*2)+1],grid[i*2]);
        
        cout << "où mêtre le brouilleur ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[12+(i*5)]=new Engine(3,"br",horizontal,x,y,new Skill_brouilleur());
        all_engines[12+(i*5)]->put_or_remove_engine_on_grid(grid[(i*2)+1],true);

        std::system("clear");

        print_grid((i*2)+1,grid[(i*2)+1],grid[i*2]);
        
        cout << "où mêtre le patrouille ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[13+(i*5)]=new Engine(2,"pl",horizontal,x,y,new Skill_patrouille());
        all_engines[13+(i*5)]->put_or_remove_engine_on_grid(grid[(i*2)+1],true);

        std::system("clear");

        print_grid((i*2)+1,grid[(i*2)+1],grid[i*2]);
        
        cout << "où mêtre le reconnaissance ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[14+(i*5)]=new Engine(2,"re",horizontal,x,y,new Skill_reconnaissance());
        all_engines[14+(i*5)]->put_or_remove_engine_on_grid(grid[(i*2)+1],true);
    
    }

    while(notgameover)
    {
        for(int i=0;i<4;i++)
        {
            cout << "quel machine utilser ? (0=tire normal, 1-5 du 1er placé au dernier)" << '\n';
            //à finir
        }
    }
    for(int i=0; i<20; i++)
        delete(all_engines[i]);
    for(int k=0; k<4; k++ )
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                delete(grid[k][i][j]);
}