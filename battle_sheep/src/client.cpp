#include "../include/interface.h"
#include "../include/texture_manager.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>

using WssClient = SimpleWeb::SocketClient<SimpleWeb::WSS>;
int main(int argv, char**argc){

	//Very basic cmd args handling

	if(argv != 3 && argv != 2) {
		std::cerr<<"Usage : "<<argc[0]<<" host [port]"<<std::endl;
		return -1;
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
	WssClient client(hostname+std::string(":")+std::to_string(port)+std::string("/game"), false);

	std::cout<<"Creating interface"<<std::endl;
	Interface inter(&client, username, password);

	std::cout<<"Creating network listening thread"<<std::endl;
	std::thread client_thread([&client]() {
        client.start();
    });

	std::cout<<"Starting interface"<<std::endl;
	inter.start();

	return 0;
}
