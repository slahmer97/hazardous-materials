#include "../include/interface.h"
#include "../include/texture_manager.h"
#include <iostream>

int main(int argv, char**argc){
	
	TextureManager::Init();

	Interface inter;

	inter.start();

	return 0;
}
