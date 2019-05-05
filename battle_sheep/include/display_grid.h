#ifndef DISPLAY_GRID_H
#define DISPLAY_GRID_H

#include "../include/component.h"

class GridActionListener;
#include "../include/click_callback.h"
#include "../include/texture_manager.h"

#include <vector>
#include <iostream>

class DisplayGrid : public Component {

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
		 * If we need to display the air or the water
		 */
		bool displayAir = false;


		/**
		 * Select a case to highlight
		 * Will also highliht the ship if there is one there
		 */
		void selectCase(int x, int y, bool force = false);

		/**
		 * Set the listener for the return button
		 */
		void setListener(GridActionListener* listener);

		void calculate_sprites();


		~DisplayGrid();

	private:
		
		/**
		 * Geometry information for the textfield
		 */
		int x,y,width,height;
		
		/**
		 * The listener for when we click somewhere on the grid
		 */
		GridActionListener* listener = nullptr;
		
		/**
		 * Size of the grid
		 */
		int gridWidth, gridHeight;

		/**
		 * The currently selected case, to hightlight a boat/plane or to aim
		 */
		int selectedX = -1, selectedY = -1;
		
		std::vector<sf::Sprite> highlight_sprites;

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
	
		//TODO: create member to contain the ships/planes received from the network
		//TODO: create member to store successful shots on this grid

};



#endif
