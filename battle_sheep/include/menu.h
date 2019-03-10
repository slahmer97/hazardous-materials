#ifndef MENU_H
#define MENU_H


#include <SFML/Graphics.hpp>

class Menu {
	virtual void handleEvent(sf::Event* event) = 0;
	virtual void draw(sf::RenderTarget* drawingBoard) = 0;
};


#endif
