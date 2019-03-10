#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <SFML/Graphics.hpp>

#include "menu.h"

/**
 * Main class of the client-side GUI
 */
class Interface
{
	/*Methods*/
	public:
		/**
		 * Constructor of the class
		 */
		Interface();
		
		/**
		 * Start the rendering and updating loop, displaying the Interface
		 */
		void start();
		
		/**
		 * Change the currently used menu to another (main menu to game menu, etc)
		 */
		void change_current_menu(Menu* newMenu);

	private:
		/**
		 * The window in which we render everything
		 */
		sf::RenderWindow window;
		/**
		 * The currently used menu
		 */
		Menu* currentMenu = nullptr;
};

#endif
