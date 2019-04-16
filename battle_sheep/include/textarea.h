#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "../include/component.h"
#include <vector>
#include <algorithm>

class TextArea : Component {

	public:
		TextArea(int fontHeight = 20, int x = 0, int y = 0, int width = 0, int height = 0);
		

		virtual void handleEvent(sf::Window* window,sf::Event* event);

		virtual void draw(sf::RenderTarget* drawingBoard);

		void addTextLine(sf::String line);

	private:
		int x,y,width,height, fontHeight, line_count;
		static const HISTORY_SIZE = 40;
		

		sf::Font;
		std::vector<sf::String> content;
		

};


#endif
