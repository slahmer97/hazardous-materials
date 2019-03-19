#ifndef CLICK_CALLBACK_H
#define CLICK_CALLBACK_H

class Button;

#include "../include/button.h"

class ClickListener {
	public:
		virtual void on_click(Button* source) = 0;
};


#endif
