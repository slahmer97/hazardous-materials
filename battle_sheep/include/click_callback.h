#ifndef CLICK_CALLBACK_H
#define CLICK_CALLBACK_H


#include "../include/component.h"

class ClickListener {
	public:
		virtual void on_click(Component* source) = 0;
};


#endif
