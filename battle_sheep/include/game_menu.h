#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "../include/menu.h"
#include "../include/button.h"
#include "../include/b_switch.h"
#include "../include/textfield.h"
#include "../include/display_grid.h"
#include "../include/click_callback.h"

class GameMenu : public Menu, public ClickListener
{
	public:
		GameMenu();

		virtual void handleEvent(sf::Window* window, sf::Event* event);

	 	virtual void draw(sf::RenderTarget* drawingBoard);

		virtual void on_click(Component* button);

		~GameMenu();
	private:
		/**
		 * Button to confirm the selected action and leave the
		 */
		Button confirm;
		/**
		 * Switch buttons to select the 2 grids that are displayed
		 */
		B_Switch b1;
		B_Switch b2;

		DisplayGrid grid_self, grid_opponent;

		sf::Texture grille;



};




#endif
