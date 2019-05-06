#ifndef CHOOSE_MENU_H
#define CHOOSE_MENU_H

#include "../include/menu.h"
#include "../include/button.h"
#include "../include/b_switch.h"
#include "../include/textfield.h"
#include "../include/display_grid.h"
#include "../include/click_callback.h"
#include "../include/ServerMessage.h"
#include "../include/ClientMessageSender.h"
#include "../include/enum.h"


class ChooseMenu : public Menu, public ClickListener
{
	public:
		ChooseMenu();

		virtual void handleEvent(sf::Window* window, sf::Event* event);

		void handle_server_message(ServerMessage* m);

	 	virtual void draw(sf::RenderTarget* drawingBoard);

		virtual void on_click(Component* button);
		
		~ChooseMenu() {};

	private:
		/**
		 * Button to select grid
		 */
		Button select_1;
		Button select_2;
		Button select_3;
		Button select_4;

};


#endif
