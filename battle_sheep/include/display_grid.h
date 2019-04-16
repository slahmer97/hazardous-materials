#ifndef DISPLAY_GRID_H
#define DISPLAY_GRID_H

#include "../include/component.h"
#include "../include/click_callback.h"
#include "../include/texture_manager.h"

#include <vector>
#include <iostream>

class DisplayGrid : Component {

	public:
		DisplayGrid( void* placeholder = nullptr, int gridWidth = 10, int gridHeight = 10, int x = 0, int y = 0);

		/**
		 * Method to which all event are passed
		 */
		virtual void handleEvent(sf::Window* window,sf::Event* event);
		/**
		 * Method drawing the Component
		 */
		virtual void draw(sf::RenderTarget* drawingBoard);

		/**
		 * Setter for the click handler
		 */
		void set_on_click(ClickListener* listener);
		
		
		/**
		 * If we need to display the air or the water
		 */
		bool displayAir = false;

		/**
		 * Set the listener for the return button
		 */
		void setListener(ClickListener* listener);

		void calculate_sprites();


		~DisplayGrid();

	private:
		
		/**
		 * Geometry information for the textfield
		 */
		int x,y,width,height;
		
		/**
		 * The listener for when the Enter key is pressed
		 */
		GridActionListener* listener = nullptr;
		
		/**
		 * Size of the grid
		 */
		int gridWidth, gridHeight;

		/**
		 * All the sprites used to display the grid itself
		 */
		std::vector<std::vector<sf::Sprite>> spritesBackground;
		std::vector<std::vector<sf::Sprite>> spritesBackgroundAir;
	
		/**
		 * All the sprites used for the ships
		 * TODO: update it to work with data obtained from the network
		 */
		std::vector<std::vector<sf::Sprite>> spritesShip;
		std::vector<std::vector<sf::Sprite>> spritesPlanes;



};



#endif
