#include "../include/display_grid.h"

DisplayGrid::DisplayGrid(void* placeHolder, int gridWidth, int gridHeight, int x, int y): gridWidth(gridWidth), gridHeight(gridHeight), x(x), y(y) {
	
	//We load the texture :
	if(!backgroundAtlas.loadFromFile("assets/textures/basic_atlas.png")){
		std::cerr<<"Coulnd't load assets/textures/basic_atlas.png, aborting"<<std::endl;
		std::abort();
	}

	//We create the array containing all the background sprites
	this->spritesBackground = new sf::Sprite*[gridWidth];

	//Then we populate it
	for(int i = 0; i < gridWidth; i++){
		this->spritesBackground[i] = new sf::Sprite[gridHeight];
		for(int j = 0; j < gridHeight; i++){
			spritesBackground[i][j].setTexture(backgroundAtlas);
			spritesBackground[i][j].setPosition(x+i*32, y+j*32);
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
			spritesBackground[i][j].setTextureRect(sf::IntRect(32,32,32,32));
		}
	}
}

void DisplayGrid::setListener(ClickListener* listener){
	this->listener = listener;
}

DisplayGrid::~DisplayGrid(){
	for(int i = 0; i < gridWidth; i++){
		delete[] this->spritesBackground[i];
	}
	delete[] this->spritesBackground;
}

void DisplayGrid::handleEvent(sf::Window* window,sf::Event* event){
	
}


void DisplayGrid::draw(sf::RenderTarget* drawingBoard){
	
}


