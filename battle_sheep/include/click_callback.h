#ifndef CLICK_CALLBACK_H
#define CLICK_CALLBACK_H


class DisplayGrid;
#include "../include/component.h"
#include "../include/display_grid.h"

/**
 * A Basic action listener
 */
class ClickListener {
	public:
		virtual void on_click(Component* source) = 0;
};

/**
 * A listener for action done on a display grid
 */
class GridActionListener {
	public:
		virtual void on_action(DisplayGrid* grid, sf::Mouse::Button button, int gridX, int gridY, int options1=0, int options2=0)=0;
};


#endif
