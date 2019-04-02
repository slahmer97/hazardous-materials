#include "../include/textfield.h"

TextField::TextField(sf::String defaultText, sf::String prompt, int x, int y, int width, int height) : text(defaultText), prompt(prompt), x(x), y(y), width(width), height(height){
	//We try to load the font
	if(!font.loadFromFile("assets/font/LiberationMono-Regular.ttf")){
		//We couldn't load the font
		std::cerr<<"Couldn't load assets/font/LiberationMono-Regular.ttf"<<std::endl;
		std::abort();
	}
}


void TextField::handleEvent(sf::Window* window,sf::Event* event){
	switch(event->type){
		case sf::Event::KeyPressed:
			if(this->enabled){
				if(event->key.code == sf::Keyboard::Return){
					if(this->listener != nullptr){
						this->listener->on_click(this);
					}
				}
			}
			break;
			
		case sf::Event::TextEntered:
			if(this->enabled){
				if(event->text.unicode != '\n'){
					this->text+=sf::String(event->text.unicode);
				}
			}
			break;
	}
}

void TextField::draw(sf::RenderTarget* drawingBoard){
	sf::RectangleShape box;
	sf::Text content;

	box.setSize(sf::Vector2f(this->width, this->height));
	box.setPosition(x, y);

	box.setFillColor(sf::Color::White);
	box.setOutlineColor(sf::Color::Black);
	box.setOutlineThickness(1.0f);

	content.setFont(font);
	content.setString(this->prompt+" "+this->text);
	content.setCharacterSize(this->width*3/4);

	if(enabled)
		content.setFillColor(sf::Color::Black);
	else
		content.setFillColor(sf::Color(128,128,128));

	//We correctly center the text
	int text_width = (int)content.getLocalBounds().width;
	int text_height= (int)content.getLocalBounds().height;

	content.setPosition(this->x+this->width/2-text_width/2, this->y+this->height/2-text_height);

	drawingBoard->draw(box);
	drawingBoard->draw(content);
}


void TextField::setListener(ClickListener* listener){
	this->listener = listener;
}
