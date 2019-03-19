#include "../include/button.h"



Button::Button(std::string text, int x, int y, int width, int height):
	text(text), x(x), y(y), width(width), height(height){
	//Nothing else to do

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

	}

}

void Button::draw(sf::RenderTarget* drawingBoard){
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(this->width, this->height));
	shape.setPosition(this->x, this->y);

	if(enabled){
		if(pressed){
			// darker blue
			shape.setFillColor(sf::Color(0,255,0));
		} else {
			// blue
			shape.setFillColor(sf::Color(128,255,128));
		}
	} else {
		shape.setFillColor(sf::Color(100,100,100));
	}
	
	drawingBoard->draw(shape);

}


void Button::set_on_click(ClickListener* listener){
	this->listener = listener;
}


bool Button::is_pressed(){
	return this->pressed;
}
