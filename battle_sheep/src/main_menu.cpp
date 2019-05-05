#include "../include/main_menu.h"

MainMenu::MainMenu():
    login("","login>",100,100,500,50),
    password("","password>",100,300,500,50),
	confirm_lp("Confirm",430,420,100,50)
{
  confirm_lp.set_on_click(this);
  login.setListener(this);
  password.setListener(this);
}

void MainMenu::handle_server_message(ServerMessage* m){
	switch(m->get_msg_type()){
		default:
			break;
	}
}
void MainMenu::handleEvent(sf::Window* window, sf::Event* event){
    login.handleEvent(window,event);
    password.handleEvent(window,event);
    confirm_lp.handleEvent(window,event);
}
void MainMenu::draw(sf::RenderTarget* drawingBoard){

    login.draw(drawingBoard);
    password.draw(drawingBoard);
    confirm_lp.draw(drawingBoard);
}

std::string MainMenu::getLogin(){
	return this->login.text;
}

void MainMenu::on_click(Component* button){
    
	if((void*)button == (void*)&confirm_lp){
		std::string log1=login.text;
		std::string pass1=password.text;
        if(pass1!="" && log1!="")
        {
            ClientMessageSender::sendLoginRequest(log1,pass1);
        }
	} else if((void*)button == (void*)&login){
		//We pass the focus to password
		login.selected = false;
		password.selected = true;
	} else if((void*)button == (void*)&password){
		//emulating button click
		this->on_click(&confirm_lp);
	}
}
