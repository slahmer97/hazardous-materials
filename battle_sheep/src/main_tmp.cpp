#include "../include/skill.h"
#include "../include/engine.h"
#include "../include/square.h"
#include <iostream>

#include <string>

using namespace std;

int playing_player(int p)
{
    switch(p) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 1;
    case 3:
        return 3;
    default :
        return -1;
}
}

int players_companions(int p)
{
    switch(p) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    case 3:
        return 2;
    default :
        return -1;
}
}
int engine_health(int i, int j)
{
    if(i<2) {
        switch(j)
{
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 2;
        default :
            return -1;
}
    }
    else
    {
        switch(j) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 2;
        default :
            return -1;
    }
    return -1;
}
}
void print_one_line_gride(Square *grid[10][10], int i)
{
    for(int j=0; j<10; j++)
    {
        cout << "|";
        if(grid[j][i]->get_engine_here()==NULL)
        {
            cout << "    ";
        }
        else
        {
            cout << grid[j][i]->get_engine_here()->get_engine_name()
            << "_"
            << grid[j][i]->get_engine_here()->get_current_health_point();
        }
    }
}


void print_grid(string engine_name, int player, int your_health, int openant_health,
                Square *grid[10][10], Square *grid2[10][10])
{
    cout << "player : " << player;
    if(!((your_health==0)&&(openant_health==0)))
        cout << " your health : " << your_health << " openants health : " << openant_health;
    
    cout << '\n';
    for(int i=9; i>=0; i--)
    {
        cout << "---------------------------------------------------   ---------------------------------------------------" << '\n';
        
        print_one_line_gride(grid,i);
        
        cout << "|   ";
        
        print_one_line_gride(grid2,i);
        
        cout << "|";
        
        cout << '\n';
    }
    cout << "---------------------------------------------------   ---------------------------------------------------" << '\n';
    if(engine_name.compare("") != 0)
        cout << "Où mettre le " << engine_name << " ? (bool horizontal, int x, int y)" << '\n';
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
    string engines_names[10]={"porte avion","croiseur","contre torpilleur","cuirasse",
                              "torpilleur","bombardier","intercepteur","brouilleur",
                              "patrouille","reconnaissance"};
    
    string engines_short_names[10]={"pa","cr","ct","cu","to","bo","in","br","pl","re"};
    Skill *all_skill[20];
    for(int i=0;i<11; i+=10)
    {
        all_skill[i]=new Skill_porte_avion();
        all_skill[i+1]=new Skill_croiseur();
        all_skill[i+2]=new Skill_contre_torpilleur();
        all_skill[i+3]=new Skill_cuirasse();
        all_skill[i+4]=new Skill_torpilleur();
        all_skill[i+5]=new Skill_bombardier();
        all_skill[i+6]=new Skill_intercepteur();
        all_skill[i+7]=new Skill_brouilleur();
        all_skill[i+8]=new Skill_patrouille();
        all_skill[i+9]=new Skill_reconnaissance();
    }
    for(int i=0; i<4; i++)
    {
        int player=playing_player(i);
        int player_comp=players_companions(i);
        for(int j=0; j<5; j++)
        {
            //std::system("clear");

            int health=engine_health(i,j);

            print_grid(engines_names[(i*5)+j],player+1,0,0,grid[player],grid[player_comp]);

            cin >> horizontal >> x >> y;

            all_engines[(player*5)+j]=new Engine(health,engines_short_names[((5*player)+j)%10],horizontal,x,y,all_skill[(player*5)+j]);
            while(!(all_engines[(i*5)+j]->put_or_remove_engine_on_grid(grid[player],true)))
            {
                delete(all_engines[(i*5)+j]);

                print_grid(engines_names[((i*5)+j)%10],player+1,0,0,grid[player],grid[player_comp]);
                cout << "Le " << engines_names[((player*5)+j)%10] << " a été mal placé !" << '\n';
                cin >> horizontal >> x >> y;
                
                all_engines[(i*5)+j]=new Engine(health,engines_short_names[((5*i)+j)%10],horizontal,x,y,all_skill[(i*5)+j]);
            }
        }
    }
    /*for(int i=0;i<2;i++)
    {
        //std::system("clear");

        print_grid((i*2)+1,grid[i*2],grid[(i*2)+1]);
        
        
        cin >> horizontal >> x >> y;
        
        all_engines[0+(i*5)]=new Engine(5,"pa",horizontal,x,y,new Skill_porte_avion());
        all_engines[0+(i*5)]->put_or_remove_engine_on_grid(grid[i*2],true);

        //std::system("clear");

        print_grid((i*2)+1,grid[i*2],grid[(i*2)+1]);
        
        cout << "où mettre le croiseur ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[1+(i*5)]=new Engine(4,"cr",horizontal,x,y,new Skill_croiseur());
        all_engines[1+(i*5)]->put_or_remove_engine_on_grid(grid[i*2],true);

        //std::system("clear");

        print_grid((i*2)+1,grid[i*2],grid[(i*2)+1]);
        
        cout << "où mettre le contre torpilleur ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[2+(i*5)]=new Engine(3,"ct",horizontal,x,y,new Skill_contre_torpilleur());
        all_engines[2+(i*5)]->put_or_remove_engine_on_grid(grid[i*2],true);

        //std::system("clear");

        print_grid((i*2)+1,grid[i*2],grid[(i*2)+1]);
        
        cout << "où mettre le cuirasse ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[3+(i*5)]=new Engine(2,"cu",horizontal,x,y,new Skill_cuirasse());
        all_engines[3+(i*5)]->put_or_remove_engine_on_grid(grid[i*2],true);

        //std::system("clear");

        print_grid((i*2)+1,grid[i*2],grid[(i*2)+1]);
        
        cout << "où mettre le torpilleur ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[4+(i*5)]=new Engine(2,"to",horizontal,x,y,new Skill_torpilleur());
        all_engines[4+(i*5)]->put_or_remove_engine_on_grid(grid[i*2],true);
    
    }

    for(int i=0;i<2;i++)
    {
        //std::system("clear");

        print_grid((i*2)+1,grid[(i*2)+1],grid[i*2]);
        
        cout << "où mettre le bombardier? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[10+(i*5)]=new Engine(4,"bo",horizontal,x,y,new Skill_bombardier());
        all_engines[10+(i*5)]->put_or_remove_engine_on_grid(grid[(i*2)+1],true);

        //std::system("clear");

        print_grid((i*2)+1,grid[(i*2)+1],grid[i*2]);
        
        cout << "où mettre le intercepteur ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[11+(i*5)]=new Engine(3,"in",horizontal,x,y,new Skill_intercepteur());
        all_engines[11+(i*5)]->put_or_remove_engine_on_grid(grid[(i*2)+1],true);

        //std::system("clear");

        print_grid((i*2)+1,grid[(i*2)+1],grid[i*2]);
        
        cout << "où mettre le brouilleur ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[12+(i*5)]=new Engine(3,"br",horizontal,x,y,new Skill_brouilleur());
        all_engines[12+(i*5)]->put_or_remove_engine_on_grid(grid[(i*2)+1],true);

        //std::system("clear");

        print_grid((i*2)+1,grid[(i*2)+1],grid[i*2]);
        
        cout << "où mettre le patrouille ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[13+(i*5)]=new Engine(2,"pl",horizontal,x,y,new Skill_patrouille());
        all_engines[13+(i*5)]->put_or_remove_engine_on_grid(grid[(i*2)+1],true);

        //std::system("clear");

        print_grid((i*2)+1,grid[(i*2)+1],grid[i*2]);
        
        cout << "où mettre le reconnaissance ? (bool horizontal, int x, int y)" << '\n';
        cin >> horizontal >> x >> y;
        
        all_engines[14+(i*5)]=new Engine(2,"re",horizontal,x,y,new Skill_reconnaissance());
        all_engines[14+(i*5)]->put_or_remove_engine_on_grid(grid[(i*2)+1],true);
    
    }*/

    while(notgameover)
    {
        for(int i=0;i<4;i++)
        {
            int ship,x,y;
            int affichage;
            int player=playing_player(i);
            int companion=players_companions(player);
            int yhealth=0;
            int ohealth=0;
            for(int j=0; j<20; j++)
            {
                if(player<2)
                {
                    if(j<10)
                    {
                        yhealth+=all_engines[j]->get_current_health_point();
                    }
                    else
                    {
                        ohealth+=all_engines[j]->get_current_health_point();
                    }
                    
                }
                else
                {
                    if(j<10)
                    {
                        ohealth+=all_engines[j]->get_current_health_point();
                    }
                    else
                    {
                        yhealth+=all_engines[j]->get_current_health_point();
                    }
                }
                
            }
            //std::system("clear");
            switch(player) {
            case 0:
                print_grid("",player,0,0,grid[2],grid[3]);
            case 1:
                print_grid("",player,0,0,grid[3],grid[2]);
            case 2:
                print_grid("",player,0,0,grid[0],grid[1]);
            case 3:
                print_grid("",player,0,0,grid[1],grid[0]);
            default :
                return -1;
}

            print_grid("",player+1,yhealth,ohealth,grid[player],grid[companion]);

            cout << "quel machine utilser ? (0=tire normal, 1-5 du 1er placé au dernier)" << '\n';
            
            cin >> ship;
            
            if(ship==0)
            {
                int target_player;
                
                cout << "sur qui tirer ? où tirer ?" << '\n';

                cin >> target_player >> x >> y;

                affichage = all_engines[(player*5)]->normal_shot(grid[target_player-1],x,y);

                if(affichage == -1)
                {
                    i = ( ( (i-- % 4) + 4) % 4 );

                    cout << "en dehors de la grille" << '\n';
                }
                else if(affichage==0)
                {
                    cout << "rien n'est touché :(" << '\n';
                }
                else
                {
                    i = ( ( (i-- % 4) + 4) % 4 );
                    
                    cout << "touché ! :)" << '\n';
                }
                
            }
            if (ship>0)
            {
                int tirer;

                cout << "tirer (:0) ? bouger (:1) ? rotation (:2) ?" << '\n';
                
                cin >> tirer;
                
                if(tirer==0)
                {
                    cout << "où tirer ?" << '\n';

                    cin >> x >> y;

                    affichage = all_engines[(player*5)+ship]->skill_shot(grid,x,y);

                    if(affichage == -1)
                    {
                        i = ( ( (i-- % 4) + 4) % 4 );

                        cout << "en dehors de la grille" << '\n';
                    }
                    else if(affichage==0)
                    {
                        cout << "rien n'est touché :(" << '\n';
                    }
                    else
                    {
                        i = ( ( (i-- % 4) + 4) % 4 );
                        
                        cout << "touché ! :)" << '\n';
                    }
                }

                if(tirer==1)
                {
                    
                    int direction,mvmt;
                    
                    cout << "direction (:bool) ? point de mouvement ?" << '\n';
                    
                    cin >> direction >> mvmt;
                    
                    all_engines[(player*5)+ship]->move_engine(grid[player],direction,mvmt);

                }

                if(tirer==2)
                {
                    
                    int direction,mvmt;
                    
                    cout << "direction horraire ou pas (:bool) ? où sur le bateau ? (:1 à taille du bateau)" << '\n';
                    
                    cin >> direction >> mvmt;
                    
                    all_engines[(player*5)+ship]->rotate_engine(grid[player],direction,mvmt-1);
                    
                }

            }
            int health_team1=0;
            int health_team2=0;
            for(int j=0;j<10;j++)
            {
                health_team1=all_engines[i]->get_current_health_point();
            }
            for(int j=0;j<10;j++)
            {
                health_team2=all_engines[10+i]->get_current_health_point();
            }
            if( (health_team1<1) || (health_team2<1) )
            {
                notgameover=false;
                break;
            }
        }
    }
    for(int i=0; i<20; i++)
        delete(all_engines[i]);
    for(int k=0; k<4; k++ )
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                delete(grid[k][i][j]);
}
