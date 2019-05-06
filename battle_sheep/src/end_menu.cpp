#include "../include/end_menu.h"

EndMenu::EndMenu():
  	confirm("Confirm",430,420,100,50)
{
  end_text.setCharacterSize(40);
  sf::Vector2f vec;
  vec.x=400;
  vec.y=270;
  end_text.setPosition(vec);
  confirm.set_on_click(this);
}

void EndMenu::handle_server_message(ServerMessage* m){
	switch(m->get_msg_type()){
		case ServerMessage::WON:
		{
			end_text.setColor(sf::Color::Blue);
			end_text.setString("YOU WON !");
		}
		break;
		case ServerMessage::LOST:
		{
			end_text.setColor(sf::Color::Red);
			end_text.setString("YOU LOSE!");
		}
		break;
		default:
			break;
	}
}
void EndMenu::handleEvent(sf::Window* window, sf::Event* event){
    confirm.handleEvent(window,event);
}
void EndMenu::draw(sf::RenderTarget* drawingBoard){
	drawingBoard->draw(end_text);
    confirm.draw(drawingBoard);
}
void EndMenu::on_click(Component* button){
    
	if((void*)button == (void*)&confirm){
		
	} 
}
