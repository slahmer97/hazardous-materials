#include "game_menu.h"

GameMenu::GameMenu():
	confirm("Confirm",430,420,100,50),
	b1("",280,420,100,50),
	b2("",580,420,100,50),
	grid_self(nullptr, 10,10, 50,50),
	grid_opponent(nullptr, 10,10,590,50),
	currentState(STATE_DISABLED)
{
  if (!grille.loadFromFile("assets/textures/grille_10x10.png"))
  {
    std::cerr<<"Couldn't load assets/textures/grille_10x10.png"<<std::endl;
    std::abort();
  }

  confirm.set_on_click(this);
  b1.set_on_click(this);
  b2.set_on_click(this);
}


void GameMenu::on_action(DisplayGrid* grid, sf::Mouse::Button button, int gridX, int gridY, int options1, int options2){
	switch(this->currentState){
		case STATUS_PLACE:
			//Place ship
			break;
	}
}

void GameMenu::handle_server_message(ServerMessage* m){
	switch(m->get_msg_type()){
		default:
			break;
	}
}

void GameMenu::handleEvent(sf::Window* window, sf::Event* event){
    confirm.handleEvent(window,event);
    b1.handleEvent(window,event);
    b2.handleEvent(window,event);
	grid_self.handleEvent(window, event);
	grid_opponent.handleEvent(window, event);
}

void GameMenu::draw(sf::RenderTarget* drawingBoard){
	grid_self.draw(drawingBoard);
	grid_opponent.draw(drawingBoard);

    sf::Sprite sp_grille;
    sp_grille.setTexture(grille);
    sp_grille.setColor(sf::Color(0,255,0,128));
    sp_grille.setPosition(50,50);
    drawingBoard->draw(sp_grille);

    sf::Sprite sp_grille2;
    sp_grille2.setTexture(grille);
    sp_grille2.setColor(sf::Color(0,255,0,128));
    sp_grille2.setPosition(590,50);
    drawingBoard->draw(sp_grille2);



    confirm.draw(drawingBoard);
    b1.draw(drawingBoard);
    b2.draw(drawingBoard);
}

void GameMenu::on_click(Component* button){
	if((void*)button == (void*)&b1){
		grid_self.displayAir = !b1.is_left();
	} else if((void*)button == (void*)&b2){
		grid_opponent.displayAir = !b2.is_left();
		
	} else if((void*)button == (void*)&confirm){
		printf("Plouf\n");
	}
}

GameMenu::~GameMenu(){
}
