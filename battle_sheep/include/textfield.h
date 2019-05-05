#ifndef TEXT_FIELD_H
#define TEXT_FIELD_H

#include <iostream>

#include "../include/component.h"
#include "../include/click_callback.h"

class TextField : public Component {
	public:
		TextField(sf::String defaultText = "", sf::String prompt = "", int x = 0, int y = 0, int width = 0, int height = 0);

		/**
		 * Method to which all event are passed
		 */
		virtual void handleEvent(sf::Window* window,sf::Event* event);
		/**
		 * Method drawing the Component
		 */
		virtual void draw(sf::RenderTarget* drawingBoard);

		/**
		 * The text contained in the Textfield, minus the prompt
		 */
		sf::String text;

		/**
		 * A prompt for the textfield, printed before the text can be entered
		 */
		sf::String prompt;


		/**
		 * Var containing if the textfield is enabled or not
		 */
		bool enabled = true;

		/**
		 * Set the listener for the return button
		 */
		void setListener(ClickListener* listener);


		/**
		 * If the textfield is selected
		 */
		bool selected = false;


	private:

		/**
		 * Geometry information for the textfield
		 */
		int x,y,width,height;

		/**
		 * The font for the textfield
		 */
		sf::Font font;

		/**
		 * The listener for when the Enter key is pressed
		 */
		ClickListener* listener = nullptr;

};


#endif
