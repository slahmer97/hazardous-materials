#ifndef COMPONENT_H
#define COMPONENT_H


#include <SFML/Graphics.hpp>

class Component {
	public:
		/**
		 * Method to which all event are passed
		 */
		virtual void handleEvent(sf::Window* window,sf::Event* event) = 0;
		/**
		 * Method drawing the Component
		 */
		virtual void draw(sf::RenderTarget* drawingBoard) = 0;
};


#endif
