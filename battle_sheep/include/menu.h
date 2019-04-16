#ifndef MENU_H
#define MENU_H


#include <SFML/Graphics.hpp>

#include "../include/component.h"

class Menu : Component {
	//Currently a placeholder
	public:
		virtual void handleEvent(sf::Window* window,sf::Event* event) = 0;
		virtual void draw(sf::RenderTarget* drawingBoard) = 0;
		virtual ~Menu();
};


#endif
