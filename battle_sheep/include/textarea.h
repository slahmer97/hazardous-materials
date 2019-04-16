#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "../include/component.h"
#include <vector>
#include <iostream>
#include <algorithm>

class TextArea : Component {

	public:
		TextArea(unsigned int fontHeight = 20, unsigned int x = 0, unsigned int y = 0, unsigned int width = 0, unsigned int height = 0);
		

		virtual void handleEvent(sf::Window* window,sf::Event* event);

		virtual void draw(sf::RenderTarget* drawingBoard);

		void addTextLine(sf::String line);

	private:
		unsigned int x,y,width,height, fontHeight, line_count;
		static const unsigned int HISTORY_SIZE = 40;
		

		sf::Font font;
		std::vector<sf::String> content;
		

};


#endif
