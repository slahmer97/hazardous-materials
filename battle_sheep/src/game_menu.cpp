#include "game_menu.h"

GameMenu::GameMenu(){
  if (!grille.loadFromFile("assets/textures/grille_10x10.png"))
  {
    std::cerr<<"Couldn't load assets/textures/grille_10x10.png"<<std::endl;
    std::abort();
  }
}


void GameMenu::handleEvent(sf::Window* window, sf::Event* event){
    confirm->handleEvent(window,event);
    b1->handleEvent(window,event);
    b2->handleEvent(window,event);
}

void GameMenu::draw(sf::RenderTarget* drawingBoard){
    sf::Sprite sp_grille;
    sp_grille.setTexture(grille);
    sp_grille.setColor(sf::Color(0,255,0,128));
    sp_grille.setPosition(50,50);
    drawingBoard->draw(sp_grille);

    sf::Sprite sp_grille2;
    sp_grille2.setTexture(grille);
    sp_grille2.setColor(sf::Color(0,255,0,128));
    sp_grille2.setPosition(590,50);
    drawingBoard->draw(sp_grille2);

    confirm->draw(drawingBoard);
    b1->draw(drawingBoard);
    b2->draw(drawingBoard);
}

//void ClickListener::on_click(Component* button){
//  if(&button == confirm)
//  {
//    printf("plouf");
//  }
//}

Menu::~Menu(){
  delete this;
}
