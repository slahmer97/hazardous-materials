#ifndef END_MENU_H
#define END_MENU_H

#include "../include/menu.h"
#include "../include/button.h"
#include "../include/b_switch.h"
#include "../include/textfield.h"
#include "../include/display_grid.h"
#include "../include/click_callback.h"
#include "../include/ServerMessage.h"
#include "../include/ClientMessageSender.h"
#include "../include/enum.h"


class EndMenu : public Menu, public ClickListener
{
	public:
		EndMenu();

		virtual void handleEvent(sf::Window* window, sf::Event* event);

		void handle_server_message(ServerMessage* m);

	 	virtual void draw(sf::RenderTarget* drawingBoard);

		virtual void on_click(Component* button);
		
		std::string getLogin();

		~EndMenu();

	private:
		/**
		 * Button to confirm the login and password
		 */
		Button confirm;
		sf::Text end_text;

		sf::Font font;
};


#endif
