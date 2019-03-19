#ifndef BUTTON_H
#define BUTTON_H

#include "../include/component.h"
#include "../include/click_callback.h"
#include <string>

/**
 * A simple class to use and create a button
 */
class Button : Component {
	public:
		/**
		 * Button constructor
		 */
		Button(std::string text= "", int x = 0, int y = 0, int width = 0, int height = 0);
		
		/**
		 * Event handling function, passed from this component container
		 */
		virtual void handleEvent(sf::Window* window,sf::Event* event);
		/**
		 * Drawing function
		 */
		virtual void draw(sf::RenderTarget* drawingBoard);
		
		/**
		 * Title of the Button
		 */
		std::string text;
		
		//int[4] getGeometry();
		
		/**
		 * Setter for the click handler
		 */
		void set_on_click(ClickListener* listener);
		
		/**
		 * Var containing if the button is enabled or not
		 */
		bool enabled = true;

		/**
		 * Getter for the state of the button (pressed or not)
		 */
		bool is_pressed();
	
	private:
		/**
		 * Geometry information for the button
		 */
		int x,y,width,height;
		/**
		 * Click handler
		 */
		ClickListener* listener = nullptr;
		/**
		 * Var containing the pressed of the button
		 */
		bool pressed = false;
};


#endif
