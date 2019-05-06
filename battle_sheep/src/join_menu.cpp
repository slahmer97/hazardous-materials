#include "../include/join_menu.h"

JoinMenu::JoinMenu():
createtxt("","Create/Join>",150,193,300,50),
createbut("Create",505,63,140,50),
joinbut("Join",505,323,140,50),
error(20,150,100,300,50),
show(false)
{
  createtxt.setListener(this);
  createbut.set_on_click(this);
  joinbut.set_on_click(this);
}

void JoinMenu::handle_server_message(ServerMessage* m){
	switch(m->get_msg_type()){
		default:
			break;
	}
}
void JoinMenu::handleEvent(sf::Window* window, sf::Event* event){
    createtxt.handleEvent(window,event);
    createbut.handleEvent(window,event);
    joinbut.handleEvent(window,event);
	error.handleEvent(window,event);
}
void JoinMenu::draw(sf::RenderTarget* drawingBoard){

    createtxt.draw(drawingBoard);
    createbut.draw(drawingBoard);
    joinbut.draw(drawingBoard);
	if(show==true)
		error.draw(drawingBoard);
}


void JoinMenu::on_click(Component* button){
    
	if((void*)button == (void*)&createbut){
		std::string create1="";
        create1=createtxt.text;
        if(create1!="")
        {
            ClientMessageSender::sendCreateGameRequest(create1);
        }
	} else if((void*)button == (void*)&createtxt){
		//emulating button click
		this->on_click(&createbut);
	} else if((void*)button == (void*)&joinbut){
		std::string join1="";
        join1=createtxt.text;
        if(join1!="")
        {
            ClientMessageSender::sendJoinGameRequest(join1);
        }
	}
}
