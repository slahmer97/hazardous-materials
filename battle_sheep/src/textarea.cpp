#include "../include/textarea.h"

TextArea::TextArea(unsigned int fontHeight, unsigned int x, unsigned int y, unsigned int width, unsigned int height):
	x(x),
	y(y),
	width(width),
	height(height),
	fontHeight(fontHeight),
	line_count(height/fontHeight){//On affiche autand de lignes que posible

	//We try to load the font
	if(!font.loadFromFile("assets/font/LiberationMono-Regular.ttf")){
		//We couldn't load the font
		std::cerr<<"Couldn't load assets/font/LiberationMono-Regular.ttf"<<std::endl;
		std::abort();
	}
	
}

void TextArea::handleEvent(sf::Window* window, sf::Event* event){
	//TODO: implement scrollbar
}

void TextArea::draw(sf::RenderTarget* drawingBoard){
	sf::RectangleShape box;
	box.setSize(sf::Vector2f(this->width, this->height));
	box.setPosition(x, y);

	box.setFillColor(sf::Color::White);
	box.setOutlineColor(sf::Color::Black);
	box.setOutlineThickness(1.0f);

	drawingBoard->draw(box);

	int position = content.size()-std::min(line_count, (unsigned int)content.size());

	for(unsigned int i = 0; i < line_count && i < content.size(); i++) {
		sf::Text text;
		text.setString(content[position + i]);
		text.setFont(font);
		text.setCharacterSize(fontHeight);
		text.setPosition(this->x, this->y+i*text.getLocalBounds().height);
		text.setFillColor(sf::Color::Black);
		
		drawingBoard->draw(text);
	}
}


void TextArea::addTextLine(sf::String line){
	content.push_back(line);
	if(content.size() >= HISTORY_SIZE){
		content.erase(content.begin());
	}
}
