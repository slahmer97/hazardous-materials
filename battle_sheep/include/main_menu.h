#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "../include/menu.h"
#include "../include/button.h"
#include "../include/b_switch.h"
#include "../include/textfield.h"
#include "../include/display_grid.h"
#include "../include/click_callback.h"
#include "../include/ServerMessage.h"
#include "../include/ClientMessageSender.h"
#include "../include/enum.h"


class MainMenu : public Menu, public ClickListener
{
	public:
		MainMenu();

		virtual void handleEvent(sf::Window* window, sf::Event* event);

		void handle_server_message(ServerMessage* m);

	 	virtual void draw(sf::RenderTarget* drawingBoard);

		virtual void on_click(Component* button);
		
		std::string getLogin();

		~MainMenu();

	private:
		/**
		 * Button to confirm the login and password
		 */
		Button confirm_lp;

        TextField login;
        TextField password;
};


#endif
