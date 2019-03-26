#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "../include/menu.h"
#include "../include/button.h"

class GameMenu : Menu, ClickListener {
	public:
		GameMenu();

		virtual void handleEvent(sf::Window* window, sf::Event* event);

		virtual void draw(sf::RenderTarget* drawingBoard);

		virtual void on_click(Button* button);
	private:
		/**
		 * Button to confirm the selected action and leave the
		 */
		Button confirm;

};




#endif
