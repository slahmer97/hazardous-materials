#ifndef JOIN_MENU_H
#define JOIN_MENU_H

#include "../include/menu.h"
#include "../include/button.h"
#include "../include/b_switch.h"
#include "../include/textfield.h"
#include "../include/textarea.h"
#include "../include/display_grid.h"
#include "../include/click_callback.h"
#include "../include/ServerMessage.h"
#include "../include/ClientMessageSender.h"
#include "../include/enum.h"


class JoinMenu : public Menu, public ClickListener
{
	public:
		JoinMenu();

		virtual void handleEvent(sf::Window* window, sf::Event* event);

		void handle_server_message(ServerMessage* m);

	 	virtual void draw(sf::RenderTarget* drawingBoard);

		virtual void on_click(Component* button);

		void show_error(bool show);

		~JoinMenu();
        TextField createtxt;
		TextArea error;
		bool show;

	private:
		/**
		 * Button to join or create
		 */
		Button createbut;
		Button joinbut;
};


#endif
