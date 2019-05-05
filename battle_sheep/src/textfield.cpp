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
		case sf::Event::MouseButtonPressed:
			if(this->enabled && event->mouseButton.button == sf::Mouse::Left){
				if(this->x <= event->mouseButton.x && event->mouseButton.x <= this->x+this->width &&
						this->y <= event->mouseButton.y && event->mouseButton.y <= this->y+this->height ){
					this->selected = true;
				}
				else
					this->selected = false;
			}
			break;
		case sf::Event::KeyPressed:
			if(this->enabled && this->selected){
				if(event->key.code == sf::Keyboard::Return){
					std::cout<<"KeyPressed: return"<<std::endl;
					if(this->listener != nullptr){
						this->listener->on_click(this);
					}
				}
			}
			break;
			
		case sf::Event::TextEntered:
			if(this->enabled && this->selected){
				//8 means backspace, so we erase one character
				if(event->text.unicode == 8){
					if(this->text.getSize()>0)
						this->text.erase(this->text.getSize()-1);
				} else if(event->text.unicode != 13){//13 is return
					this->text+=sf::String(event->text.unicode);
				} 
			}
			break;
		default:
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
	content.setCharacterSize(20);

	if(enabled)
		content.setFillColor(sf::Color::Black);
	else
		content.setFillColor(sf::Color(128,128,128));
	
	if(selected)
		box.setFillColor(sf::Color(200,200,200));

	//We correctly center the text
	int text_height= (int)content.getLocalBounds().height;

	content.setPosition(this->x+10, this->y+this->height/2-text_height);

	drawingBoard->draw(box);
	drawingBoard->draw(content);
}


void TextField::setListener(ClickListener* listener){
	this->listener = listener;
}
