#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "../include/menu.h"
#include "../include/button.h"
#include "../include/b_switch.h"
#include "../include/textfield.h"
#include "../include/display_grid.h"
#include "../include/click_callback.h"

class GameMenu : public Menu//, ClickListener
{
	public:
		GameMenu();

		void handleEvent(sf::Window* window, sf::Event* event);

	 	void draw(sf::RenderTarget* drawingBoard);

		//void ClickListener::on_click(Component* button);
	private:
		/**
		 * Button to confirm the selected action and leave the
		 */
		Button * confirm = new Button("Confirm",430,420,100,50);
		/**
		 * Switch buttons to select the 2 grids that are displayed
		 */
		B_Switch * b1 = new B_Switch("",280,420,100,50);
		B_Switch * b2 = new B_Switch("",580,420,100,50);





};




#endif
