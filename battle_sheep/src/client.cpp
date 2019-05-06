#include "../include/interface.h"
#include "../include/texture_manager.h"
#include <iostream>
#include <string>
#include <thread>
#include <Engine.h>

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
		port = std::atoi(argc[2]);
	}


	std::cout<<"Initializing texture manager"<<std::endl;
	TextureManager::Init();
	std::cout<<"Texture manager initialized"<<std::endl;


	std::cout<<"Creating connection"<<std::endl;
	WssClient client(hostname+std::string(":")+std::to_string(port)+std::string("/game"), false);

	std::cout<<"Creating interface"<<std::endl;
	Interface inter(&client);

	std::cout<<"Creating network listening thread"<<std::endl;
	std::thread client_thread([&client]() {
        client.start();
    });


    std::cout<<"Creating server second communicator thread"<<std::endl;
    std::thread communicator([]() {

            std::string in;
            while(in != "CLOSEE"){
                std::cout<<"Enter your msg : ";
                getline(std::cin,in);
                std::string send = "TMP";
                std::string tmp1,tmp2,tmp3;
                if(in == "login"){
                    std::cout<<"login : ";
                    getline(std::cin,tmp1);
                    ClientMessageSender::sendLoginRequest(tmp1,"");
                }
                else if(in == "create_game"){
                    std::cout<<"game_name : ";
                    getline(std::cin,tmp1);
                    ClientMessageSender::sendCreateGameRequest(tmp1);
                }
                else if(in == "choose_grid"){
                    int id = 0;
                    std::cout<<"grid id : ";
                    std::cin>>id;
                    ClientMessageSender::sendChooseGridRequest(id);
                }
                else if(in == "join_game"){
                    std::cout<<"game_id : ";
                    getline(std::cin,tmp1);
                    ClientMessageSender::sendJoinGameRequest(tmp1);
                }
                else if(in == "add_engine"){
                    ENGINE_TYPE type;
                    int horu = 0,x=0,y=0;
                    std::string e_type;
                    std::cout<<"hori : ";
                    std::cin>>horu;
                    std::cout<<"x : ";
                    std::cin>>x;
                    std::cout<<"y : ";
                    std::cin>>y;
                    std::cout<<"Engine type : ";
                    std::cin>>e_type;
                    type = Engine::engine_type_to_type(e_type);
                    std::cout<<"Final type : "<<Engine::engine_type_to_string(type)<<std::endl;
                    ClientMessageSender::sendAddEngineRequest(type,horu,x,y);
                }
                else if(in == "move_engine"){
                    int id = 1,x,y;
                    std::cout<<"id : ";
                    std::cin>>id;
                    std::cout<<"reading dir? : ";
                    std::cin>>x;
                    std::cout<<"distance : ";
                    std::cin>>y;
                    ClientMessageSender::sendMoveEngineRequest(id,x,y);
                }
                else if(in == "chat"){
                    std::cout<<"msg_chat : ";
                    getline(std::cin,tmp1);
                    ClientMessageSender::sendChatRequest(tmp1);
                }
                else if(in == "engine_rotate"){
                    int id = 1,x,y;
                    std::cout<<"id : ";
                    std::cin>>id;
                    std::cout<<"clock ? : ";
                    std::cin>>x;
                    std::cout<<"node dist : ";
                    std::cin>>y;
                    ClientMessageSender::sendRotateEngineRequest(id,x,y);
                }
                else if(in == "shot"){
                    int id = 1,grid,x,y,h;
                    std::cout<<"engine_id: ";
                    std::cin>>id;
                    std::cout<<"grid_target_id ? : ";
                    std::cin>>grid;
                    std::cout<<"hori ? : ";
                    std::cin>>h;
                    std::cout<<"x ? : ";
                    std::cin>>x;
                    std::cout<<"y ? : ";
                    std::cin>>y;
                    ClientMessageSender::sendShotRequest(id,grid,h,x,y);
                }
                continue;
        }
    });

	std::cout<<"Starting interface"<<std::endl;
	inter.start();


	communicator.join();
	return 0;
}
