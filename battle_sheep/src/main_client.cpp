//
// Created by sidahmedlahmer on 3/26/19.
//
#include <iostream>
#include <client_wss.hpp>
#include <thread>
#include <ClientMessage.h>

using WssClient = SimpleWeb::SocketClient<SimpleWeb::WSS>;
using namespace std;
WssClient::Connection* server = nullptr;
int main(){
    WssClient client("localhost:8080/game", false);
    client.on_message = [](shared_ptr<WssClient::Connection> connection, shared_ptr<WssClient::InMessage> in_message) {
        cout << "\n------>Received :\n" << in_message->string()<< endl;
    };
    client.on_open = [](shared_ptr<WssClient::Connection> connection) {
        if(server == nullptr)
            server = connection.get();
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
            send = ClientMessage::getLoginMessage(tmp1,"");
        }
        else if(in == "create_game"){
            std::cout<<"game_name : ";
            getline(std::cin,tmp1);
            send = ClientMessage::getCreateGameMessage(tmp1);
        }
        else if(in == "choose_grid"){
            int id = 0;
            std::cout<<"grid id : ";
            std::cin>>id;
            send = ClientMessage::getChoseGridMessage(id);
        }
        else if(in == "join_game"){
            std::cout<<"game_id : ";
            getline(std::cin,tmp1);
            send = ClientMessage::getJoinGameMessage(tmp1);
        }
        else
            continue;



        std::cout<<"\n--->Sent : \n"<<send<<std::endl;
        server->send(send);
    }
    client_thread.join();
}

