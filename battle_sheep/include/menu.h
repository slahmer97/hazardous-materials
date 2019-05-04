#ifndef MENU_H
#define MENU_H


#include <SFML/Graphics.hpp>

#include "../include/component.h"
#include "../include/enum.h"

class Menu : public Component {
	//Currently a placeholder
	public:
		virtual void handleEvent(sf::Window* window,sf::Event* event) = 0;
		virtual void draw(sf::RenderTarget* drawingBoard) = 0;
	 	GameMenuState currentState;
};


#endif
