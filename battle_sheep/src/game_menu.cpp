#include "game_menu.h"

GameMenu::GameMenu(std::string players[4], int local_player):
	confirm("Confirm",430,420,100,50),
	b1("",280,420,100,50),
	b2("",580,420,100,50),
	grid_self(nullptr, 10,10, 50,50),
	grid_opponent(nullptr, 10,10,590,50),
	currentState(STATE_DISABLED),
	textarea(15, 400, 185, 160, 160),
	chatField("", ">", 400, 345, 160, 25),
	local_player(local_player)
{
	if (!grille.loadFromFile("assets/textures/grille_10x10.png"))
	{
		std::cerr<<"Couldn't load assets/textures/grille_10x10.png"<<std::endl;
		std::abort();
	}
	
	for(int i = 0; i < 4; i++){
		this->players[i] = players[i];
	}

	confirm.set_on_click(this);
	b1.set_on_click(this);
	b2.set_on_click(this);
	chatField.setListener(this);
}


void GameMenu::on_action(DisplayGrid* grid, sf::Mouse::Button button, int gridX, int gridY, int options1, int options2){
	switch(this->currentState){
		case STATE_PLACE:
			//Place ship
			break;
	}
}

void GameMenu::handle_server_message(ServerMessage* m){
	switch(m->get_msg_type()){
		case ServerMessage::GRIDS_ASSIGNEMENT:
			players[m->get_id()-1] = m->get_username();
			break;
		case ServerMessage::GRID:
			switch(m->get_id()){
				case 1:
					grid_self.set_grid_ship(m->get_grid());
					break;
				case 2:
					grid_self.set_grid_planes(m->get_grid());
					break;
				case 3:
					grid_opponent.set_grid_ship(m->get_grid());
					break;
				case 4:
					grid_opponent.set_grid_planes(m->get_grid());
					break;
			}
			break;
		case ServerMessage::CHAT_S:
			this->textarea.addTextLine(players[m->get_id()-1]+m->get_chat_msg());
			break;
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
	textarea.handleEvent(window,event);
	chatField.handleEvent(window,event);
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

		textarea.draw(drawingBoard);
		chatField.draw(drawingBoard);
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
	} else if((void*)button == (void*)&chatField){
		ClientMessageSender::sendChatRequest(chatField.text);
		this->textarea.addTextLine(this->chatField.text);
		chatField.text = "";
	}
}

GameMenu::~GameMenu(){
}
