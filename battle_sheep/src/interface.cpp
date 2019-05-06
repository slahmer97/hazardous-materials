#include <utility>

#include "../include/interface.h"
#include "../include/b_switch.h"
#include "../include/display_grid.h"
#include "../include/textarea.h"
#include "../include/textfield.h"
#include <iostream>



Interface::Interface(WssClient * connection, std::string username, std::string password):
	player(std::move(username)),
	password(std::move(password)),
	window(sf::VideoMode(960,540), "Battle Sheep"),
	co(connection)

{

	//We pass the method dedicated to receive messages via a lambda function
	co->on_message = [this] (std::shared_ptr<WssClient::Connection> connection, std::shared_ptr<WssClient::InMessage> in_message) {
		this->on_server_message_received(connection, in_message);
	};

	//We pass the method dedicated to detect the connection opening via a lambda function

    co->on_open = [this](std::shared_ptr<WssClient::Connection> connection) {
		this->on_server_connection_open(connection);
	};

	//Same for the method dedicated to the closing
	co->on_close = [this](std::shared_ptr<WssClient::Connection> connection, int status, const std::string &reason){
		this->on_server_connection_closed(connection, status, reason);
	};

	//And the method dedicated to errors from the connection
	co->on_error = [this](std::shared_ptr<WssClient::Connection> connection, const SimpleWeb::error_code &ec) {
		this->on_server_connection_error(connection, ec);
	};
}

TextArea txt(10, 0, 0, 300, 100);

void Interface::start() {

    this->change_current_menu(new MainMenu());


	std::cout<<"Starting loop"<<std::endl;
	while(this->window.isOpen()){
		//We check all event generated since the last loop
		sf::Event event;
		while(window.pollEvent(event)){
			//We then do things depending on which was detected
			if(event.type == sf::Event::Closed){
				window.close();
				break;
			}
			if(event.type == sf::Event::Resized ){
				if(event.size.width != 960 || event.size.height != 540)
					window.setSize(sf::Vector2u(960, 540));
				break;
			}


			//Then we pass any other to the current Menu
			if(this->currentMenu != nullptr)
				this->currentMenu->handleEvent(&window,&event);

			for(size_t i = 0; i < (this->boite).size();i++)
				boite[i]->handleEvent(&window,&event);
		}

		//We clear the window of any previous drawing
		window.clear(sf::Color(128,128,128));
		//We draw the current menu in a buffer
		if(this->currentMenu != nullptr)
			this->currentMenu->draw(&window);

		for(size_t i = 0; i < (this->boite).size();i++)
			boite[i]->draw(&window);

		//We then display the buffer on the window
		window.display();


	}
	std::cout<<"Cleaning up"<<std::endl;

}

void Interface::change_current_menu(Menu* newMenu){
	//If the previous menu is not null, delete it
	if(this->currentMenu != nullptr)
		delete this->currentMenu;
	//Then set the new one
	this->currentMenu = newMenu;
}



void Interface::on_server_message_received( const std::shared_ptr<WssClient::Connection>& connection, std::shared_ptr<WssClient::InMessage> in_message  ){
	ServerMessage *m = ServerMessage::getServerMessage(in_message->string());

	//Les messages normaux
	ServerMessage::SERVER_MESSAGE_TYPE msg_type = m->get_msg_type();
    JoinMenu *joinmenu=new JoinMenu();
	//We pre-cast into a gamemenu and a mainmenu for simplicity in the different cases
	GameMenu* gm = dynamic_cast<GameMenu*>(this->currentMenu);
	MainMenu* mm = dynamic_cast<MainMenu*>(this->currentMenu);
	switch(msg_type){
        case ServerMessage::KILL_PLAYER:
            {
				if(gm != nullptr){
					gm->currentState = STATE_DISABLED;
				}
            }
            break;
        case ServerMessage::GRIDS_ASSIGNEMENT:	//choisir grille
            {
				//this->change_current_menu(new ChooseMenu());
							//boite.push_back(new Box(220.f,133.f,480.f,270.f));
							//boite.back()->compo.push_back(new Button("Select 1",300,195,140,35));
							//boite.back()->compo.push_back(new Button("Select 2",300,315,140,35));
							//boite.back()->compo.push_back(new Button("Select 3",490,195,140,35));
							//boite.back()->compo.push_back(new Button("Select 4",490,315,140,35));

            }
            break;
        case ServerMessage::ERROR:
            {
				this->handle_errror_message(m);
            }
            break;
        case ServerMessage::CHAT_S:
            {

            }
            break;
        case ServerMessage::CURRENT_TURN:
            {
				if(gm != nullptr){
					gm->currentState = STATE_PLAY;
				}
            }
            break;
        case ServerMessage::SCORE_BROADCAST:
            {

            }
            break;
        case ServerMessage::LOGIN_SUCCESS:
            {
				/*boite.push_back(new Box(220.f,133.f,480.f,270.f));
				boite.back()->compo.push_back(new TextField("","Create>",250,163,200,50));
				boite.back()->compo.push_back(new Button("Create",505,163,140,50));
				boite.back()->compo.push_back(new TextField("","Join>",250,323,200,50));
				boite.back()->compo.push_back(new Button("Join",505,323,140,50));
				*/
				if(mm != nullptr) {
					std::cout<<"Succefully logged in as "<<m->get_username()<<std::endl;
					this->player = mm->getLogin();
					this->change_current_menu(joinmenu);

					//std::cout<<"Requestion to join 'default' game"<<std::endl;
					//ClientMessageSender::sendJoinGameRequest("default");
				}
            }
            break;
        case ServerMessage::CREATED_SUCCESS:
            {
				std::cout<<"Succefully created game 'default'"<<std::endl;
				//TODO: Not sure if this is required -Alex
				std::string join=joinmenu->createtxt.text;
				ClientMessageSender::sendJoinGameRequest(join);

            }
            break;
        case ServerMessage::JOIN_SUCCESS:
            {
				std::cout<<"Succefully joined game 'default'"<<std::endl;
				this->change_current_menu(new ChooseMenu());
            }
            break;
        case ServerMessage::START:
            {
            }
            break;
        case ServerMessage::GRID:
            {

            }
            break;
        case ServerMessage::ENGINE_ADDED:
            {

            }
            break;
        case ServerMessage::MOVE_SUCCESS:
            {

            }
            break;
        case ServerMessage::ROTATE_SUCCESS:
            {

            }
            break;
        case ServerMessage::GRID_ASSIGN_SUCCESS:
            {

				this->change_current_menu(new GameMenu());
            }
            break;


	}
	}

void Interface::handle_errror_message(ServerMessage* m){
    ServerMessage::ERRORS error = m->get_err_type();
	switch(error){
		case ServerMessage::GAME_DOES_NOT_EXIST:
			{
				std::cout<<"'default' game inexistant, requesting creation"<<std::endl;
				ClientMessageSender::sendCreateGameRequest("default");
			}
			break;
        case ServerMessage::LOGIN_REQUIRE:	//pas login , action illegal
            {

            }
            break;
        case ServerMessage::CONNECTION_LOST:
            {
				std::cout<<"Connection lost to current game, attempting reconnection"<<std::endl;
				ClientMessageSender::sendJoinGameRequest("");
            }

            break;
        case ServerMessage::ALREADY_CHOSEN:
            {

            }
            break;
        case ServerMessage::ACTION_FAILED:
            {

            }
            break;
        case ServerMessage::ENGINE_ID_DOES_NOT_EXIST:
            {

            }
            break;
        case ServerMessage::GRID_ID_DOES_NOT_EXIST:
            {

            }
            break;
        default:
            std::cerr<<"[-] Error that has been received could not be recognized"<<std::endl;
    }
}


void Interface::on_server_connection_open( const std::shared_ptr<WssClient::Connection>& connection){

	if(!ClientMessageSender::isUp())
		ClientMessageSender::setServer(connection.get());

	std::cout<< "Server connection opened, sending login information" << std::endl;

	//When the connection is established, we send the login information
	//ClientMessageSender::sendLoginRequest(, password);

}



void Interface::on_server_connection_closed( const std::shared_ptr<WssClient::Connection>& connection, int status, const std::string &reason){
	std::cout<<"Server connection closed with status code "<<status<<" and reason "<<reason<<std::endl;
}


void Interface::on_server_connection_error(const std::shared_ptr<WssClient::Connection>& connection, const SimpleWeb::error_code &ec){

	std::cout<<"Server connection error : " << ec << " with message " << ec.message() << std::endl;

}

Interface::~Interface(){
	delete this->currentMenu;
}
