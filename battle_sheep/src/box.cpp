#include "../include/box.h"

Box::Box(int x, int y, int width, int height):
  x(x), y(y), width(width), height(height){

  }


void Box::handleEvent(sf::Window* window, sf::Event* event){
  for(int i = 0; i < this->compo.length; i++)
  {
    compo[i].handleEvent(window,event);
  }
}

void Box::draw(sf::RenderTarget* drawingBoard){
  this->fond.setSize(sf::Vector2f(this->width, this->height));
  this->fond.setPosition(this->x, this->y);

  this->fond.setFillColor(sf::Color(172,172,172));
  drawingBoard->draw(this->fond);
  for(int i = 0; i < this->compo.length; i++)
  {
    compo[i].draw(drawingBoard);
  }
}

void setPosition(int x, int y){
  this->x = x;
  this->y = y;
}

void setSize(int width, int height){
  this->width = width;
  this->height = heigth;
}
