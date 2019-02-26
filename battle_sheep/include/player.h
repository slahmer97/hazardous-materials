#ifndef DEF_PLAYER
#define DEF_PLAYER

#include <string>

class Player
{
    /*Methods*/
  public:
    //Constructor :
    Player();

    //Getters :

    //Setters :

    /*Attributes*/
  private:
    int player_id;
    std::string nickname;
    bool alive;
    int numbrer_successful_shots;
    int number_missed_shot;
    bool playing;
};

#endif
