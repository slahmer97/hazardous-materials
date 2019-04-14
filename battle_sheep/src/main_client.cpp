//
// Created by sidahmedlahmer on 3/26/19.
//
#include <iostream>
#include <client_wss.hpp>
#include <thread>

using WssClient = SimpleWeb::SocketClient<SimpleWeb::WSS>;
using namespace std;
WssClient::Connection* server = nullptr;
int main(){
    WssClient client("localhost:8081/echo", false);
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



    while(true){
        std::string in;
        std::cout<<"Enter your msg : ";
        getline(std::cin,in);
        server->send(in);
    }
    client_thread.join();
}

