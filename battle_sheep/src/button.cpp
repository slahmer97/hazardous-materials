#include "../include/button.h"




Button::Button(std::string text, int x, int y, int width, int height):
	text(text), x(x), y(y), width(width), height(height){
	//We try to load the font
	if(!font.loadFromFile("assets/font/LiberationMono-Regular.ttf")){
		//We couldn't load the font
		std::cerr<<"Couldn't load assets/font/LiberationMono-Regular.ttf"<<std::endl;
		std::abort();
	}

}

void Button::handleEvent(sf::Window* window,sf::Event* event){
	
	//The button don't do anything if it is deactivated
	if(!this->enabled){
		return;
	}
	
	//Depending on the event, we do something different
	switch(event->type){
		//When the mouse is pressed in the button zone, we make the button change
		case sf::Event::MouseButtonPressed:
			//LMB check
			if(event->mouseButton.button == sf::Mouse::Left){
				//Zone check
				if(this->x <= event->mouseButton.x && event->mouseButton.x <= this->x+this->width &&
						this->y <= event->mouseButton.y && event->mouseButton.y <= this->y+this->height ){
					this->pressed = true;
				}
			
			}

			break;
		case sf::Event::MouseButtonReleased:
			//And when the left mouse button is released, we make the button looks normal
			//Also, we start the button action if the click is released inside the button
			if(this->pressed){
				//LMB check
				if(event->mouseButton.button == sf::Mouse::Left){
					this->pressed = false;
					//Position check
					if(this->x <= event->mouseButton.x && event->mouseButton.x <= this->x+this->width &&
							this->y <= event->mouseButton.y && event->mouseButton.y <= this->y+this->height ){
						//And we call the handler, also passing this button
						if(this->listener != nullptr){
							this->listener->on_click(this);
						}
					}
			
				}
				
			}

			break;
		default:
			break;

	}

}

void Button::draw(sf::RenderTarget* drawingBoard){
	sf::RectangleShape shape;
	//We correctly position the button
	shape.setSize(sf::Vector2f(this->width, this->height));
	shape.setPosition(this->x, this->y);
	
	//We setup the text with it's font
	sf::Text text;

	
	text.setFont(font);
	text.setString(this->text);
	text.setCharacterSize(28);
	text.setFillColor(sf::Color::White);
	
	//We correctly center the text
	int text_width = (int)text.getLocalBounds().width;
	int text_height= (int)text.getLocalBounds().height;
	text.setPosition(this->x+this->width/2-text_width/2, this->y+this->height/2-text_height);
	

	//We set the color depending of the state of the button
	if(enabled){
		if(pressed){
			// darker blue
			shape.setFillColor(sf::Color(0,0,255));
		} else {
			// blue
			shape.setFillColor(sf::Color(128,128,255));
		}
	} else {
		shape.setFillColor(sf::Color(100,100,100));
	}
	
	drawingBoard->draw(shape);
	drawingBoard->draw(text);


}


void Button::set_on_click(ClickListener* listener){
	this->listener = listener;
}


bool Button::is_pressed(){
	return this->pressed;
}
