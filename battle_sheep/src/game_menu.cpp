#include "game_menu.h"

GameMenu::GameMenu(){

}


void GameMenu::handleEvent(sf::Window* window, sf::Event* event){
    confirm->handleEvent(window,event);
    b1->handleEvent(window,event);
    b2->handleEvent(window,event);
}

void GameMenu::draw(sf::RenderTarget* drawingBoard){
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
