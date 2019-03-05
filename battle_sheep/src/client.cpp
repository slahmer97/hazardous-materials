#include "../include/interface.h"
#include <iostream>

int main(int argv, char**argc){
	//Temporary main
	std::cout<<"This will be the Client"<<std::endl;

	Interface inter;

	inter.start();

	return 0;
}
