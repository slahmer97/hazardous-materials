#ifndef DISPLAY_GRID_H
#define DISPLAY_GRID_H

#include "../include/component.h"

class GridActionListener;
#include "../include/click_callback.h"
#include "../include/texture_manager.h"
#include "../include/Square.h"

#include <vector>
#include <iostream>
#include <sstream>


struct GridCase {
	int id;
	float health;
	SQUARE_TYPE type;
};

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
		
		void get_selected_cases(int* x, int* y);

		GridCase get_case_at(int x, int y, bool air);

		/**
		 * Set the listener for the return button
		 */
		void setListener(GridActionListener* listener);

		void calculate_sprites();

		void set_grid_ship(std::string strGridShip);

		void set_grid_planes(std::string strGridPlane);
		
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
		 */
		std::vector<std::vector<sf::Sprite>> spritesShip;
		std::vector<std::vector<sf::Sprite>> spritesPlanes;
	
		/**
		 * The grids containing the logical parts of the ships
		 */
		std::vector<std::vector<GridCase>> gridShip;
		std::vector<std::vector<GridCase>> gridPlane;

		//TODO: create member to store successful shots on this grid

};



#endif
