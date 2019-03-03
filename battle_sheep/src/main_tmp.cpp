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
int engine_pm(int i, int j)
{
    if(i<2) {
        switch(j)
        {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 5;
        default :
            return -1;
        }
    }
    else
    {
        switch(j) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 4;
        default :
            return -1;
        }
    }
    return -1;
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
void print_one_line_gride(Square *grid[10][10], int i, bool hide)
{
    cout << i << " ";
    for(int j=0; j<10; j++)
    {
        cout << "|";
        if(grid[j][i]->get_engine_here()==NULL)
        {
            cout << "    ";
        }
        else
        {
            if(!(hide))
            {
                cout << grid[j][i]->get_engine_here()->get_engine_name()
                << "_"
                << grid[j][i]->get_engine_here()->get_current_health_point();
            }
            else if(grid[j][i]->get_engine_here()->get_current_health_point()==0)
            {
                cout << " XX ";
            }
            else
            {
                cout << "    ";
            }
            
        }
    }
}


void print_grid(string engine_name,int player,
                Square *grid[10][10], Square *grid2[10][10], bool hide)
{
    cout << "player : " << player;
    
    cout << '\n';

    cout << "    0    1    2    3    4    5    6    7    8    9         0    1    2    3    4    5    6    7    8    9" << '\n';
    
    for(int i=9; i>=0; i--)
    {
        cout << "  ---------------------------------------------------   ---------------------------------------------------" << '\n';
        
        print_one_line_gride(grid,i,hide);
        
        cout << "| ";
        
        print_one_line_gride(grid2,i,hide);
        
        cout << "|";
        
        cout << " " << i << '\n';
    }
    cout << "  ---------------------------------------------------   ---------------------------------------------------" << '\n';
    
    cout << "    0    1    2    3    4    5    6    7    8    9         0    1    2    3    4    5    6    7    8    9" << '\n';
    
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
        int player_comp=players_companions(player);
        for(int j=0; j<5; j++)
        {
            std::system("clear");

            int health=engine_health(i,j);
            int pm=engine_pm(i,j);
            print_grid(engines_names[((player%2)*5)+j],player+1,grid[player],grid[player_comp],false);

            cin >> horizontal >> x >> y;

            all_engines[(player*5)+j]=new Engine(health,engines_short_names[((player%2)*5)+j],horizontal,
                                                 x,y,all_skill[(player*5)+j],player,pm);
            while(!(all_engines[(player*5)+j]->put_or_remove_engine_on_grid(grid[player],true)))
            {
                delete(all_engines[(player*5)+j]);
                std::system("clear");

                print_grid(engines_names[((player%2)*5)+j],player+1,grid[player],grid[player_comp],false);
                cout << "Le " << engines_names[((player%2)*5)+j] << " a été mal placé !" << '\n';
                cin >> horizontal >> x >> y;
                
                all_engines[(player*5)+j]=new Engine(health,engines_short_names[((player%2)*5)+j],horizontal,
                                                     x,y,all_skill[(player*5)+j],player,pm);
            }
        }
        std::system("clear");
        print_grid("",player+1,grid[player],grid[player_comp],false);
        cout << "passer le tour ?" << '\n';
        cin >> x;
    }

    while(notgameover)
    {
        for(int i=0;i<4;i++)
        {
            int ship;
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
            std::system("clear");
            if(player==0)
                print_grid("",player+1,grid[2],grid[3],true);
            if(player==1)
                print_grid("",player+1,grid[3],grid[2],true);
            if(player==2)
                print_grid("",player+1,grid[0],grid[1],true);
            if(player==3)
                print_grid("",player+1,grid[1],grid[0],true);
            cout << " your health : " << yhealth << " openants health : " << ohealth << '\n';
            
            print_grid("",player+1,grid[player],grid[companion],false);

            cout << "quel machine utilser ? (0=tire normal, 1-5 du 1er placé au dernier)" << '\n';
            
            cin >> ship;
            
            if(ship==0)
            {
                int target_player;
                cout << "sur qui tirer ? où tirer ?" << '\n';

                cin >> target_player >> x >> y;
                while(target_player>4 || target_player<1)
                {
                    cout << "sur qui tirer ? où tirer ?" << '\n';
                    cout << "pas un joueur!" << '\n';

                    cin >> target_player >> x >> y;
                    
                }
                
                while(affichage = all_engines[(player*5)]->normal_shot(grid[target_player-1],x,y)!=0)
                {
                    if(affichage == -1)
                    {
                        cout << "en dehors de la grille" << '\n';
                        cout << "sur qui tirer ? où tirer ?" << '\n';

                        cin >> target_player >> x >> y;
                    }
                    else
                    {
                        
                        cout << "touché ! :)" << '\n';
                        cout << "sur qui tirer ? où tirer ?" << '\n';

                        cin >> target_player >> x >> y;
                    }
                }
                if(affichage==0)
                {
                    cout << "rien n'est touché :(" << '\n';
                    cout << "continuer ?" << '\n';
                    cin >> x;
                }
                
            }
            if (ship>0)
            {
                int tirer;

                cout << "tirer (:0) ? bouger (:1) ? rotation (:2) ?" << '\n';
                
                cin >> tirer;
                
                if(tirer==0)
                {
                    cout << "direction (:bool) ? où tirer ?" << '\n';

                    cin >> horizontal >> x >> y;

                    affichage = all_engines[(player*5)+ship-1]->skill_shot(grid,x,y,horizontal);
                    if(affichage == -2)
                    {
                        cout << "Skill désactivé !" << '\n';
                        cout << "continuer ?" << '\n';
                        cin >> x;
                    }
                    
                    if(affichage == -1)
                    {
                        cout << "en dehors de la grille" << '\n';
                        cout << "continuer ?" << '\n';
                        cin >> x;
                    }
                    else if(affichage==0)
                    {
                        cout << "rien n'est touché :(" << '\n';
                        cout << "continuer ?" << '\n';
                        cin >> x;
                    }
                    else
                    {
                        
                        cout << "touché ! :)" << '\n';
                        cout << "continuer ?" << '\n';
                        cin >> x;
                    }
                }

                if(tirer==1)
                {
                    
                    int direction,mvmt;
                    
                    cout << "direction (:bool) ? point de mouvement ?" << '\n';
                    
                    cin >> direction >> mvmt;
                    
                    while(!(all_engines[(player*5)+ship-1]->move_engine(grid[player],direction,mvmt)))
                    {
                        cout << "direction (:bool) ? point de mouvement ?" << '\n';
                        cout << "déplacement impossible !" << '\n';

                        cin >> direction >> mvmt;

                    }

                }

                if(tirer==2)
                {
                    
                    int direction,mvmt;
                    
                    cout << "direction horraire ou pas (:bool) ? où sur le bateau ? (:1 à taille du bateau)" << '\n';
                    
                    cin >> direction >> mvmt;
                    
                    while(!(all_engines[(player*5)+ship-1]->rotate_engine(grid[player],direction,mvmt-1)))
                    {
                    
                    cout << "direction horraire ou pas (:bool) ? où sur le bateau ? (:1 à taille du bateau)" << '\n';
                    cout << "déplacement impossible !" << '\n';

                    
                    cin >> direction >> mvmt;
                    }
                    
                }

            }
            yhealth=0;
            ohealth=0;
            for(int j=0;j<20;j++)
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
            if( (ohealth<1) || (yhealth<1) )
            {
                cout << "game over" << '\n';
                notgameover=false;
                break;
            }
            std::system("clear");
            if(player==0)
                print_grid("",player+1,grid[2],grid[3],true);
            if(player==1)
                print_grid("",player+1,grid[3],grid[2],true);
            if(player==2)
                print_grid("",player+1,grid[0],grid[1],true);
            if(player==3)
                print_grid("",player+1,grid[1],grid[0],true);

            cout << " your health : " << yhealth << " openants health : " << ohealth << '\n';
            print_grid("",player+1,grid[player],grid[companion],false);

            cout << "passer le tour ?" << '\n';
            cin >> x;
        }
    }
    for(int i=0; i<20; i++)
        delete(all_engines[i]);
    for(int k=0; k<4; k++ )
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                delete(grid[k][i][j]);
}
