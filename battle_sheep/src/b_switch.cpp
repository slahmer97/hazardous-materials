#include "../include/b_switch.h"



B_Switch::B_Switch(std::string img, int x, int y,int width, int height):
    img(img),x(x),y(y),width(width),height(height){

    }

void B_Switch::handleEvent(sf::Window* window,sf::Event* event){

    //The switch button don't do anything if deactivated
	if(!this->enabled){
		return;
	}
	// Mouse click
	if(event->type == sf::Event::MouseButtonPressed){
        //LMB check
        if(event->mouseButton.button == sf::Mouse::Left){
            //Zone check
            if(this->x <= event->mouseButton.x && event->mouseButton.x <= this->x+this->width &&
                this->y <= event->mouseButton.y && event->mouseButton.y <= this->y+this->height ){
                    this->left = !left ;
					if(this->listener != nullptr)
						this->listener->on_click(this);
            }
        }

	}


}


void B_Switch::draw(sf::RenderTarget* drawingBoard){

     if(this->img == ""){
        // Si aucune image en entrée
        sf::RectangleShape shape_l;
        sf::RectangleShape shape_r;
        shape_l.setSize(sf::Vector2f(this->width / 2, this->height / 2));
        shape_l.setPosition(this->x, this->y);
        shape_r.setSize(sf::Vector2f(this->width / 2, this->height / 2));
        shape_r.setPosition(this->x + (width / 2), this->y);
        if(enabled){
            if(left){
                // bleu à gauche et gris à droite
                shape_l.setFillColor(sf::Color(172,172,255));
                shape_r.setFillColor(sf::Color(100,100,100));
            }
            else{
                // bleu à droite et gris à gauche
                shape_r.setFillColor(sf::Color(172,172,255));
                shape_l.setFillColor(sf::Color(100,100,100));
            }
        }
        else{
            if(left){
                // bleu à gauche et gris à droite
                shape_l.setFillColor(sf::Color(172,172,172));
                shape_r.setFillColor(sf::Color(100,100,100));
            }
            else{
                // bleu à droite et gris à gauche
                shape_r.setFillColor(sf::Color(172,172,172));
                shape_l.setFillColor(sf::Color(100,100,100));
            }
        }
    drawingBoard->draw(shape_l);
    drawingBoard->draw(shape_r);

    }

}

void B_Switch::set_on_click(ClickListener* listener){
	this->listener = listener;
}

bool B_Switch::is_left(){
    return this->left;
    }
