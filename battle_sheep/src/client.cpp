#include "../include/interface.h"
#include "../include/texture_manager.h"
#include <iostream>
#include <string>
#include <cstdlib>

#include <client_wss.hpp>

using WssClient = SimpleWeb::SocketClient<SimpleWeb::WSS>;
int main(int argv, char**argc){
	
	//Very basic cmd args handling
	
	if(argv != 3 || argv != 2) {
		std::cerr<<"Usage : "<<argc[0]<<" host [port]"<<std::endl;
	}
	
	std::string hostname(argc[1]);
	int port = 8080;
	
	if( argv == 3){
		port = atoi(argc[2]);
	}

	std::cout<<"Initializing texture manager"<<std::endl;
	TextureManager::Init();
	std::cout<<"Texture manager initialized"<<std::endl;


	std::cout<<"Creating connection"<<std::endl;
	WssClient client(hostname+":"+port+"/game", false);

	std::cout<<"Creating interface"<<std::endl;
	Interface inter(&client);

	std::cout<<"Starting interface"<<std::endl;
	inter.start();

	return 0;
}
