//
// Created by sidahmedlahmer on 3/26/19.
//
#include <iostream>
#include <client_wss.hpp>
#include <thread>
#include <ClientMessage.h>
#include <ClientMessageSender.h>

using WssClient = SimpleWeb::SocketClient<SimpleWeb::WSS>;
using namespace std;
int main(){
    WssClient client("localhost:8080/game", false);
    client.on_message = [](shared_ptr<WssClient::Connection> connection, shared_ptr<WssClient::InMessage> in_message) {
        cout << "\n------>Received :\n" << in_message->string()<< endl;
    };
    client.on_open = [](shared_ptr<WssClient::Connection> connection) {
        if(!ClientMessageSender::isUp())
            ClientMessageSender::setServer(connection.get());
        cout << "Client: Opened connection" << endl;

};
    client.on_close = [](shared_ptr<WssClient::Connection> /*connection*/, int status, const string & /*reason*/) {
        cout << "Client: Closed connection with status code " << status << endl;
    };
    client.on_error = [](shared_ptr<WssClient::Connection> /*connection*/, const SimpleWeb::error_code &ec) {
        cout << "Client: Error: " << ec << ", error message: " << ec.message() << endl;
    };
    thread client_thread([&client]() {
        client.start();
    });


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
            ENGINE_TYPE type = ENGINE_TYPE ::PORTE_AVION;
            int horu = 0,x=0,y=0;
            std::cout<<"hori : ";
            std::cin>>horu;
            std::cout<<"x : ";
            std::cin>>x;
            std::cout<<"y : ";
            std::cin>>y;
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
            continue;

    }
    client_thread.join();
}

