#include "../include/interface.h"
#include "../include/texture_manager.h"
#include <iostream>

int main(int argv, char**argc){

	std::cout<<"Initializing texture manager"<<std::endl;
	TextureManager::Init();
	std::cout<<"Texture manager initialized"<<std::endl;

	std::cout<<"Creating interface"<<std::endl;
	Interface inter;

	std::cout<<"Starting interface"<<std::endl;
	inter.start();

	return 0;
}
