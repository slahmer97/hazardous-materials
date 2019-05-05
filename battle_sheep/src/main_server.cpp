#include <iostream>
#include <GameScheduler.h>
#include <server_wss.hpp>
#include <ServerMessage.h>
#include <thread>
using namespace std;
using WssServer = SimpleWeb::SocketServer<SimpleWeb::WSS>;
int main() {
    std::string crt = "/home/seyyidahmed/CLionProjects/hazardous-materials/battle_sheep/simple_web_socket/key/server.crt";
    std::string key = "/home/seyyidahmed/CLionProjects/hazardous-materials/battle_sheep/simple_web_socket/key/server.key";
    WssServer server(crt, key);
    server.config.port = 8080;
    auto &echo = server.endpoint["^/game/?$"];
    echo.on_message = [](shared_ptr<WssServer::Connection> connection, shared_ptr<WssServer::InMessage> in_message) {
        auto out_message = in_message->string();
        GameScheduler::onMessageReceived(connection,out_message);
    };
    echo.on_open = [](shared_ptr<WssServer::Connection> connection) {
        GameScheduler::onConnectionOpened(connection);
    };
    echo.on_close = [](shared_ptr<WssServer::Connection> connection, int status, const string & reason) {
        GameScheduler::onConnectionClosed(connection,status,reason);
    };
    echo.on_error = [](shared_ptr<WssServer::Connection> connection, const SimpleWeb::error_code &ec) {
        GameScheduler::onError(connection,ec);
    };
    thread server_thread([&server]() {
        server.start();
    });


    server_thread.join();
    return 0;
}