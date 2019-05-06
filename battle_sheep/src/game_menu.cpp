#include "game_menu.h"

GameMenu::GameMenu(std::string players[4], int local_player):
	confirm("Confirm",430,420,100,50),
	b1("",280,420,100,50),
	b2("",580,420,100,50),
	grid_self(nullptr, 10,10, 50,50),
	grid_opponent(nullptr, 10,10,590,50),
	currentState(STATE_PLACE),
	textarea(15, 400, 185, 160, 160),
	chatField("", ">", 400, 345, 160, 25),
	local_player(local_player)
{
	if (!grille.loadFromFile("assets/textures/grille_10x10.png"))
	{
		std::cerr<<"Couldn't load assets/textures/grille_10x10.png"<<std::endl;
		std::abort();
	}
	if(!font.loadFromFile("assets/font/LiberationMono-Regular.ttf")){
		//We couldn't load the font
		std::cerr<<"Couldn't load assets/font/LiberationMono-Regular.ttf"<<std::endl;
		std::abort();
	}
	
	for(int i = 0; i < 4; i++){
		this->players[i] = players[i];
		if(this->players[i] == "")
			currentState = STATE_DISABLED;
	}

	for(int i = 0; i < 4; i++){
		this->players_score[i].setFillColor(sf::Color::Green);
		this->players_score[i].setCharacterSize(25);
		this->players_score[i].setFont(font);
		sf::Vector2f vec;
		vec.x=400;
		vec.y=50+(i*30);
		this->players_score[i].setPosition(vec);
		this->players_draw[i].setCharacterSize(20);
		this->players_draw[i].setFont(font);
	}
	if(local_player<2)
	{
		this->players_draw[0].setFillColor(sf::Color::Blue);
		this->players_draw[1].setFillColor(sf::Color::Blue);
		this->players_draw[2].setFillColor(sf::Color::Red);
		this->players_draw[3].setFillColor(sf::Color::Red);
		this->players_draw[0].setPosition(sf::Vector2f(50,30));
		this->players_draw[1].setPosition(sf::Vector2f(50,30));
		this->players_draw[2].setPosition(sf::Vector2f(590,30));
		this->players_draw[3].setPosition(sf::Vector2f(590,30));
	}
	else
	{
		this->players_draw[0].setFillColor(sf::Color::Red);
		this->players_draw[1].setFillColor(sf::Color::Red);
		this->players_draw[2].setFillColor(sf::Color::Blue);
		this->players_draw[3].setFillColor(sf::Color::Blue);
		this->players_draw[0].setPosition(sf::Vector2f(590,30));
		this->players_draw[1].setPosition(sf::Vector2f(590,30));
		this->players_draw[2].setPosition(sf::Vector2f(50,30));
		this->players_draw[3].setPosition(sf::Vector2f(50,30));
  }
	confirm.set_on_click(this);
	b1.set_on_click(this);
	b2.set_on_click(this);
	chatField.setListener(this);
	
	if(this->local_player%2 == 0) {
		ships_to_place.push_back(PORTE_AVION);
		ships_to_place.push_back(CROISEUR);
		ships_to_place.push_back(CONTRE_TORPILLEUR);
		ships_to_place.push_back(CUIRASSE);
		ships_to_place.push_back(TORPILLEUR);
	} else {
		ships_to_place.push_back(BOMBARDIER);
		ships_to_place.push_back(INTERCEPTEUR);
		ships_to_place.push_back(BROUILLEUR);
		ships_to_place.push_back(PATROUILE);
		ships_to_place.push_back(RECONNAISSANCE);
	}

}


void GameMenu::on_action(DisplayGrid* grid, sf::Mouse::Button button, int gridX, int gridY, int options1, int options2){
	
	switch(this->currentState){
		case STATE_PLACE:
			if(button == sf::Mouse::Right)
				vertical = !vertical;
			else if(button == sf::Mouse::Left && !waitingForAnswer)
				shipPlacementAt(gridX, gridY);
			break;
		case STATE_PLAY:
			if(button == sf::Mouse::Left)
				grid->selectCase(gridX, gridY);
			else if(button == sf::Mouse::Right && (void*)grid == (void*)&grid_opponent)
				grid->selectCase(-1, -1);

			if(button == sf::Mouse::Right){
				if((void*)grid == (void*)&grid_self)
					shipMovementAt(gridX, gridY);
			}
			break;
	}
}

void GameMenu::shipMovementAt(int gridX, int gridY){
	int gsX = -1, gsY = -1;

	grid_self.get_selected_cases(&gsX, &gsY);
	
	if(gsX == -1 || gsY == -1)
		return;

	bool air = this->local_player%2 == 1;

	int shipID = grid_self.get_case_at(gsX, gsY, air).id;
	
	bool vertical = false;

	if(gsY+1 <= 10 && grid_self.get_case_at(gsX, gsY+1, air).id == shipID)
		vertical = true;
	if(gsY-1 >= 0 && grid_self.get_case_at(gsX, gsY-1, air).id == shipID)
		vertical = true;
	
	int dX = gridX - gsX;
	int dY = gridY - gsY;
	
	ClientMessageSender::sendMoveEngineRequest(shipID, vertical ? 1 : 0, vertical ? dY : dX);

}

void GameMenu::shipPlacementAt(int gridX, int gridY){
	ENGINE_TYPE ship_to_place = ships_to_place[shipPlacementStep];
	
	ClientMessageSender::sendAddEngineRequest(ship_to_place, this->local_player, gridX, gridY);

	waitingForAnswer = true;
}



void GameMenu::handle_server_message(ServerMessage* m){
	switch(m->get_msg_type()){
		case ServerMessage::ENGINE_ADDED:
			shipPlacementStep++;
			waitingForAnswer = false;
			break;
		case ServerMessage::SHOT_SUCCESS:
			currentState = STATE_TURN_OTHER;
			break;
		case ServerMessage::MOVE_SUCCESS:
			currentState = STATE_TURN_OTHER;
			break;
		case ServerMessage::ROTATE_SUCCESS:
			currentState = STATE_TURN_OTHER;
			break;
		case ServerMessage::START:
			if(currentState != STATE_PLAY)
				currentState = STATE_TURN_OTHER;
			break;
		case ServerMessage::GRIDS_ASSIGNEMENT:
		{
			players[m->get_id()-1] = m->get_username();
			currentState = STATE_PLACE;
			for(int i=0;i<4;i++)
			{
				players_draw[i].setString("player :"+players[i]);
				if(this->players[i] == "")
					currentState = STATE_DISABLED;
			}
		}
		break;
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
		case ServerMessage::SCORE_BROADCAST:
		{
				std::string s[4];
				s[0]=std::to_string(m->get_score().get_s1());
				s[1]=std::to_string(m->get_score().get_s2());
				s[2]=std::to_string(m->get_score().get_s3());
				s[3]=std::to_string(m->get_score().get_s4());

				for(int i=0;i<4;i++)
				{
					std::string ret="joueur "+std::to_string(i+1)+" : "+s[i];
					players_score[i].setString(ret);
				}
		}
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
	for(int i = 0; i < 4; i++){
		drawingBoard->draw(players_score[i]);
	}
	for(int i=0;i<4;i++)
	{
		players_draw[i].setString("player "+std::to_string(i+1)+":"+players[i]);
	}
	if(local_player<2)
	{
		if(b1.is_left()==true)
		{
			drawingBoard->draw(players_draw[0]);
		}
		if(b1.is_left()!=true)
		{
			drawingBoard->draw(players_draw[1]);
		}
		if(b2.is_left()==true)
		{
			drawingBoard->draw(players_draw[2]);
		}
		if(b2.is_left()!=true)
		{
			drawingBoard->draw(players_draw[3]);
		}
	}
	else
	{
		if(b1.is_left()==true)
		{
			drawingBoard->draw(players_draw[2]);
		}
		if(b1.is_left()!=true)
		{
			drawingBoard->draw(players_draw[3]);
		}
		if(b2.is_left()==true)
		{
			drawingBoard->draw(players_draw[0]);
		}
		if(b2.is_left()!=true)
		{
			drawingBoard->draw(players_draw[1]);
		}
	}
	
}

void GameMenu::on_click(Component* button){
	if((void*)button == (void*)&b1){
		grid_self.displayAir = !b1.is_left();
	} else if((void*)button == (void*)&b2){
		grid_opponent.displayAir = !b2.is_left();
		
	} else if((void*)button == (void*)&confirm && this->currentState == STATE_PLAY){

		int self_grid_x = 0, self_grid_y = 0, other_grid_x = 0, other_grid_y = 0;
		//We get the selected cases coordinates
		grid_self.get_selected_cases(&self_grid_x, &self_grid_y);
		grid_opponent.get_selected_cases(&self_grid_x, &self_grid_y);
		
		if(other_grid_x != -1 && other_grid_y != -1 && self_grid_x != -1 && self_grid_y != -1){
			//We get the cases that will be the launcher
			GridCase launcherCase = grid_self.get_case_at(self_grid_x, self_grid_y, (this->local_player%2 == 1));
			//We find the target grid
			int targetGrid = this->local_player - (this->local_player%2);//First we get our team
			targetGrid = (targetGrid + 2)%4; //Next we take the opposite team
			targetGrid += (grid_opponent.displayAir ? 1 : 0);//Then if we choose to target the planes or the ships

			ClientMessageSender::sendShotRequest(launcherCase.id, targetGrid+1, 1, other_grid_x, other_grid_y);
		}

	} else if((void*)button == (void*)&chatField){
		ClientMessageSender::sendChatRequest(chatField.text);
		this->textarea.addTextLine(this->chatField.text);
		chatField.text = "";
	}
}

GameMenu::~GameMenu(){
}
