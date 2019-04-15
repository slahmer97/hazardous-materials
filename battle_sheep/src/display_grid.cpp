#include "../include/display_grid.h"

DisplayGrid::DisplayGrid(void* placeHolder, int gridWidth, int gridHeight, int x, int y): 
	x(x),
	y(y),
	gridWidth(gridWidth),
	gridHeight(gridHeight),
	spritesBackground(gridWidth, std::vector<sf::Sprite>(gridHeight) ),//creating the 2d vector of sprites representing the background
	spritesShip(gridWidth, std::vector<sf::Sprite>(gridHeight) ) {//Creating the 2d vector of sprites representing the ships (or lack)


		//We fill the 2d array displaying everything
		for(int i = 0; i < gridWidth; i++){
			for(int j = 0; j < gridHeight; j++){
				//The background sprites
				spritesBackground[i][j].setTexture(TextureManager::Background::Atlas);
				spritesBackground[i][j].setPosition(x+i*32, y+j*32);

				//The ship sprites
				spritesShip[i][j].setTexture(TextureManager::Ship::Atlas);
				spritesShip[i][j].setPosition(x+i*32, y+j*32);
				//We initialize with the empty square
				spritesShip[i][j].setTextureRect(TextureManager::Ship::Empty);
			}
		}


		//Then we call calculate_sprites to assign the right texture

		calculate_sprites();

	}

void DisplayGrid::calculate_sprites(){
	//TODO: implement that when we know how are the client-side classes defined
	//Meanwhile, we implement a default texture
	for(int i = 0; i < gridWidth; i++){
		for(int j = 0; j < gridHeight; j++){
			//We use the center texture
			spritesBackground[i][j].setTextureRect(TextureManager::Background::Water);
		}
	}
}

void DisplayGrid::setListener(ClickListener* listener){
	this->listener = listener;
}

DisplayGrid::~DisplayGrid(){

}

void DisplayGrid::handleEvent(sf::Window* window,sf::Event* event){
	//For testing purpose only, we create boat of varying size on click
	//TODO: implement attack
	switch(event->type){
		case sf::Event::MouseButtonPressed:
			{
				int mx = event->mouseButton.x,
					my = event->mouseButton.y;
				if(x <= mx && mx < x+(gridWidth*32) &&
						y <= my && my < y+(gridHeight*32)){
					//We are in this component
					int gridX = (mx-x)/32,
						gridY = (my-y)/32;
					sf::IntRect texture = this->spritesShip[gridX][gridY].getTextureRect();
					if(event->mouseButton.button == sf::Mouse::Left){
						if(texture.top == 0 && texture.left == 0){
							texture.top = 32;
							texture.left = 32;
						} else if(texture.top == 32 && texture.left == 32) {
							texture.top = 0;
							texture.left = 0;
						}
					} else if (event->mouseButton.button == sf::Mouse::Right) {
						if(texture != TextureManager::Ship::Empty){
							texture = TextureManager::Ship::Empty;
						} else {
							texture.top = 0;
							texture.left = 32;
						}

					}
					this->spritesShip[gridX][gridY].setTextureRect(texture);
				}
				break;
			}

		default:

			break;
	}
}


void DisplayGrid::draw(sf::RenderTarget* drawingBoard){
	for(int i = 0; i < gridWidth; i++) {
		for(int j = 0; j < gridHeight; j++){
			drawingBoard->draw(this->spritesBackground[i][j]);
		}
	}

	for(int i = 0; i < gridWidth; i++){
		for(int j = 0; j < gridHeight; j++){
			drawingBoard->draw(this->spritesShip[i][j]);
		}
	}
}


