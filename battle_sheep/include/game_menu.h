#ifndef GAME_MENU_H
#define GAME_MENU_H

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

//TODO: implement current selected ship/plane to be highlighted
//TODO: implement ghost of the ship you have to place

class GameMenu : public Menu, public ClickListener, public GridActionListener
{
	public:
		GameMenu(std::string players[4], int local_player);

		virtual void handleEvent(sf::Window* window, sf::Event* event);

		void handle_server_message(ServerMessage* m);

	 	virtual void draw(sf::RenderTarget* drawingBoard);

		virtual void on_action(DisplayGrid* grid, sf::Mouse::Button button, int gridX, int gridY, int options1=0, int options2=0);
		virtual void on_click(Component* button);

		~GameMenu();

		GameMenuState currentState;
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

		TextArea textarea;
		TextField chatField;

		sf::Texture grille;

		std::string players[4];

		int local_player;


};




#endif
