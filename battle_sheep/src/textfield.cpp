#include "../include/textfield.h"

TextField::TextField(sf::String defaultText, sf::String prompt): text(defaultText), prompt(prompt){
	
}


void TextField::handleEvent(sf::Window* window,sf::Event* event){
	switch(event->type){
		case sf::Event::KeyPressed:
			if(this->enabled){
				if(event->key == sf::Keyboard::Return){
					if(this->listener != nullptr){
						this->listener->on_click(this);
					}
				}
			}
			break;
			
		case sf::Event::TextEntered:
			if(this->enabled){
				if(event->text != '\n'){
					this->text+=sf::String(event->text.unicode);
				}
			}
			break;
	}
}
