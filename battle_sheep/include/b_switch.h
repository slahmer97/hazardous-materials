#ifndef B_SWITCH_H
#define B_SWITCH_H

#include "../include/component.h"
#include "../include/click_callback.h"
#include <string>

/**
 *  A simple class to create and use a switch button
 */

 class B_Switch : public Component {
    public:
        /**
         * Switch button constructor
         */
         B_Switch(std::string img = "", int x = 0,int y = 0, int width = 0, int height = 0);

        /**
         * Event handling function
         */
        virtual void handleEvent(sf::Window* window,sf::Event* event);
        /**
         * Drawing function
         */
        virtual void draw(sf::RenderTarget* drawingBoard);

        /**
         * Setter for the click handler
         */
		void set_on_click(ClickListener* listener);

		/**
		 * Var containing if the button is enabled or not
		 */
		bool enabled = true;

         /**
		 * Getter for the state of the button (left or right)
		 */
        bool is_left();

    private:

		/**
		 * String containing the location for the texture of the button
		 */
		std::string img;

        /**
		 * Geometry information for the button
		 */
		int x,y,width,height;

		/**
		 * Click handler
         */
         ClickListener* listener = nullptr;

        /**
         * Var containing if the button is in left or right position
         */
         bool left = true;
		
 };

#endif // B_SWITCH_H
