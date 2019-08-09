#ifndef BOX_H
#define BOX_H

#include "../include/button.h"
#include "../include/b_switch.h"
#include "../include/textfield.h"
#include "../include/textarea.h"
#include <string>
#include <stdlib.h>
#include <iostream>

/**
 *  A class to regroup and organized a group of component
 */

 class Box : public Component {
 public:
   /**
    * Box constructor
    * pos x, pos y , width , height
    */
    Box(int x = 0, int y = 0, int width = 0, int height = 0);

    /**
		 * Event handling function, passed from this component container
		 */
		virtual void handleEvent(sf::Window* window,sf::Event* event);
		/**
		 * Drawing function
		 */
		virtual void draw(sf::RenderTarget* drawingBoard);

    std::vector<Component*> compo;

    void setPosition(int x, int y);

    void setSize (int width, int height);

  private:

    int x,y,width,height;

    sf::RectangleShape fond;

 };

 #endif
