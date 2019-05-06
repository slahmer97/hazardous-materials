#include "../include/choose_menu.h"

ChooseMenu::ChooseMenu():
select_1("Select 1",300,195,140,35),
select_2("Select 2",300,315,140,35),
select_3("Select 3",490,195,140,35),
select_4("Select 4",490,315,140,35)
{
  select_1.set_on_click(this);
  select_2.set_on_click(this);
  select_3.set_on_click(this);
  select_4.set_on_click(this);
}

void ChooseMenu::handle_server_message(ServerMessage* m){
	switch(m->get_msg_type()){
		case ServerMessage::GRID_ASSIGN_SUCCESS: 
		{

		}
		break;
		case ServerMessage::ALREADY_CHOSEN:
		{

		}
		break;
		default:
			break;
	}
}
void ChooseMenu::handleEvent(sf::Window* window, sf::Event* event){
    select_1.handleEvent(window,event);
    select_2.handleEvent(window,event);
    select_3.handleEvent(window,event);
    select_4.handleEvent(window,event);
}
void ChooseMenu::draw(sf::RenderTarget* drawingBoard){

    select_1.draw(drawingBoard);
    select_2.draw(drawingBoard);
    select_3.draw(drawingBoard);
    select_4.draw(drawingBoard);
}

void ChooseMenu::on_click(Component* button){
    
	if((void*)button == (void*)&select_1){
        ClientMessageSender::sendChooseGridRequest(1);
	} else if((void*)button == (void*)&select_2){
        ClientMessageSender::sendChooseGridRequest(2);
	} else if((void*)button == (void*)&select_3){
        ClientMessageSender::sendChooseGridRequest(3);
	} else if((void*)button == (void*)&select_4){
        ClientMessageSender::sendChooseGridRequest(4);
	}
}
