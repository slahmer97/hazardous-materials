#include "../include/interface.h"
#include "../include/b_switch.h"
#include "../include/display_grid.h"
#include "../include/textarea.h"
#include "../include/textfield.h"



Interface(WssClient * connection, std::string username, std::password):
	player(username),
	password(password),
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
	co->on_close = [this](std::shared_ptr<WssClient::Connection> connection, int status, const string &reason){
		this->on_server_connection_closed(connection, status, reason);
	};

	//And the method dedicated to errors from the connection
	co->on_error = [this](std::shared_ptr<WssClient::Connection> connection, const SimpleWeb::error_code &ec) {
		this->on_server_connection_error(connection, ec);
	};
}

TextArea txt(10, 0, 0, 300, 100);

void Interface::start() {

    this->change_current_menu(new GameMenu());
	
	

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

		}

		//We clear the window of any previous drawing
		window.clear(sf::Color(128,128,128));
		//We draw the current menu in a buffer
		if(this->currentMenu != nullptr)
			this->currentMenu->draw(&window);
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



void Interface::on_server_message_received( std::shared_ptr<WssClient::Connection> connection, std::shared_ptr<WssClient::InMessage> in_message  ){
	ServerMessage m = ServerMessage::getServerMessage(in_message->string());
	
	//Les messages normaux
	switch(m.get_msg_type()){
		case LOGIN_SUCCESS:
			{
				//We managed to login
				std::cout<<"Succefully logged in with username '"<<username<<"'"<<std::endl;
				std::cout<<"Attempting to login on game "
			}
			break;
		case ERROR://Handle error message
			{
				handle_errror_message(&m);
			}
			break;
		case CREATED_SUCCESS:
			{
				std::cout<<"Succefullt created game default"<<std::endl;
			}
			break;
		//Add any other messages that need to be transmitted to the menu
		case MOVE:
		case CURRENT_TURN:
			GameMenu* menu = dynamic_cast<GameMenu*>(this->currentMenu);
			if(menu != nullptr){
				menu->handle_server_message(&m);
			}
			break;
	}

}

void Interface::handle_errror_message(ServerMessage* m){
	switch(m->get_err_type()){
		case GAME_DOES_NOT_EXIST:
			{
				std::cout<<"Default game inexistant, requesting creation of it"<<endl;
				ClientMessageSender::sendCreateGameRequest("default");
			}
			break;
	}
}


void Interface::on_server_connection_open( std::shared_ptr<WssClient::Connection> connection){

	if(!ClientMessageSender::isUp())
		ClientMessageSender::setServer(connection.get());

	cout << "Server connection opened, sending login information" << endl;
	
	//When the connection is established, we send the login information
	ClientMessageSender::sendLoginRequest(username, password);

}



void Interface::on_server_connection_closed( std::shared_ptr<WssClient::Connection> connection, int status, const std::string &reason){
	std::cout<<"Server connection closed with status code "<<status<<" and reason "<<reason<<std::endl;
}


void Interface::on_server_connection_error(std::shared_ptr<WssClient::Connection>, const SimpleWeb::error_code &ec){
	
	std::cout "Server connection error : " << ec << " with message " << ec.message() << std::endl;

}

Interface::~Interface(){
	delete this->currentMenu;
}
