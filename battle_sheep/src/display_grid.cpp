#include "../include/display_grid.h"

DisplayGrid::DisplayGrid(void* placeHolder, int gridWidth, int gridHeight, int x, int y): 
	x(x),
	y(y),
	gridWidth(gridWidth),
	gridHeight(gridHeight),
	spritesBackground(gridWidth, std::vector<sf::Sprite>(gridHeight) ),//creating the 2d vector of sprites representing the background
	spritesBackgroundAir(gridWidth, std::vector<sf::Sprite>(gridHeight) ),
	spritesShip(gridWidth, std::vector<sf::Sprite>(gridHeight) ),//Creating the 2d vector of sprites representing the ships (or lack)
	spritesPlanes(gridWidth, std::vector<sf::Sprite>(gridHeight) ){


		//We fill the 2d arrays displaying everything
		for(int i = 0; i < gridWidth; i++){
			for(int j = 0; j < gridHeight; j++){
				//The background sprites
				spritesBackground[i][j].setTexture(TextureManager::Background::Atlas);
				spritesBackgroundAir[i][j].setTexture(TextureManager::Background::Atlas);
				spritesBackground[i][j].setPosition(x+i*32, y+j*32);
				spritesBackgroundAir[i][j].setPosition(x+i*32, y+j*32);

				//The ship sprites
				spritesShip[i][j].setTexture(TextureManager::Ship::Atlas);
				spritesShip[i][j].setPosition(x+i*32, y+j*32);
				//We initialize with the empty square
				spritesShip[i][j].setTextureRect(TextureManager::Ship::Empty);
				//The Plane sprites
				spritesPlanes[i][j].setTexture(TextureManager::Plane::Atlas);
				spritesPlanes[i][j].setPosition(x+i*32, y+j*32);
				//We initialize with the empty square
				spritesPlanes[i][j].setTextureRect(sf::IntRect(0,0,32,32));
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
			spritesBackgroundAir[i][j].setTextureRect(TextureManager::Background::Air);
		}
	}
}

void DisplayGrid::setListener(GridActionListener* listener){
	this->listener = listener;
}

DisplayGrid::~DisplayGrid(){

}

void DisplayGrid::handleEvent(sf::Window* window,sf::Event* event){

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
					if(this->listener != nullptr){
						this->listener->on_action(this, event->mouseButton.button, gridX, gridY);
					}
				}
				break;
			}

		default:

			break;
	}
}


void DisplayGrid::selectCase(int x, int y, bool force){
	//We check if the value is different from before
	if(this->selectedX == x && this->selectedY == y && !force){
		//No need to change anything
		return;
	}
	//We create a new vector
	std::vector<sf::Sprite> new_vect;
	
	//Check if there is a know ship at (x,y)
	
	//Else juste a simple highlight
	int absX=this->x+x*32, absY=this->y+y*32;

	new_vect.resize(4);

	new_vect[0].setTexture(TextureManager::Background::Atlas);
	new_vect[1].setTexture(TextureManager::Background::Atlas);
	new_vect[2].setTexture(TextureManager::Background::Atlas);
	new_vect[3].setTexture(TextureManager::Background::Atlas);
	
	new_vect[0].setTextureRect(TextureManager::Background::HighlightUpLeft);
	new_vect[1].setTextureRect(TextureManager::Background::HighlightUpRight);
	new_vect[2].setTextureRect(TextureManager::Background::HighlightDownLeft);
	new_vect[3].setTextureRect(TextureManager::Background::HighlightDownRight);

	new_vect[0].setPosition(absX, absY);
	new_vect[1].setPosition(absX+16, absY);
	new_vect[2].setPosition(absX, absY+16);
	new_vect[3].setPosition(absX+16, absY+16);
	
	highlight_sprites.swap(new_vect);
}



void DisplayGrid::draw(sf::RenderTarget* drawingBoard){
	if(this->displayAir) {
		//We start by drawing the background
		for(int i = 0; i < gridWidth; i++) {
			for(int j = 0; j < gridHeight; j++){
				drawingBoard->draw(this->spritesBackgroundAir[i][j]);
			}
		}
		//We draw the higlight in-between
		for(int i = 0; i < highlight_sprites.size(); i++){
			drawingBoard->draw(this->highlight_sprites[i]);
		}
		
		//And we finish with the planes
		for(int i = 0; i < gridWidth; i++){
			for(int j = 0; j < gridHeight; j++){
				drawingBoard->draw(this->spritesPlanes[i][j]);
			}
		}
	} else {
		//We start by drawing the background
		for(int i = 0; i < gridWidth; i++) {
			for(int j = 0; j < gridHeight; j++){
				drawingBoard->draw(this->spritesBackground[i][j]);
			}
		}
		
		//We draw the highligh in-between
		for(int i = 0; i < highlight_sprites.size(); i++){
			drawingBoard->draw(this->highlight_sprites[i]);
		}
	
		//We finish by drawing all the ships
		for(int i = 0; i < gridWidth; i++){
			for(int j = 0; j < gridHeight; j++){
				drawingBoard->draw(this->spritesShip[i][j]);
			}
		}
	}
}



