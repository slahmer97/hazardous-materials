#include <iostream>
//#include <ServerMessage.h>
#include <GameScheduler.h>
#include <server_wss.hpp>
using namespace std;


using WssServer = SimpleWeb::SocketServer<SimpleWeb::WSS>;

int main() {
    std::string crt = "/home/sidahmedlahmer/CLionProjects/hazardous-materials/battle_sheep/build/server.crt";
    std::string key = "/home/sidahmedlahmer/CLionProjects/hazardous-materials/battle_sheep/build/server.key";
    WssServer server(crt, key);
    server.config.port = 8081;

    auto &echo = server.endpoint["^/echo/?$"];

    echo.on_message = [](shared_ptr<WssServer::Connection> connection, shared_ptr<WssServer::InMessage> in_message) {
        auto out_message = in_message->string();
        GameScheduler::onMessageReceived(connection,out_message);

        // connection->send is an asynchronous function
        connection->send(out_message, [](const SimpleWeb::error_code &ec) {
            if(ec) {
                cout << "Server: Error sending message. " <<
                     // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
                     "Error: " << ec << ", error message: " << ec.message() << endl;
            }
        });

        // Alternatively use streams:
        // auto out_message = make_shared<WssServer::OutMessage>();
        // *out_message << in_message->string();
        // connection->send(out_message);
        sleep(10);
        std::cout<<"on message ended for..."<<connection.get()->remote_endpoint_address()<<std::endl;
    };

    echo.on_open = [](shared_ptr<WssServer::Connection> connection) {
      //  GameScheduler::onConnectionOpened(connection);
    };

    echo.on_close = [](shared_ptr<WssServer::Connection> connection, int status, const string & reason) {
       // GameScheduler::onConnectionClosed(connection,status,reason);
    };

    echo.on_error = [](shared_ptr<WssServer::Connection> connection, const SimpleWeb::error_code &ec) {
        //GameScheduler::onError(connection,ec);
    };

    thread server_thread([&server]() {
        server.start();
    });

    this_thread::sleep_for(chrono::seconds(1));

    server_thread.join();

/*
    std::string msg = network::ServerMessage::getKillPlayerMessage(20);
    std::cout<<msg<<std::endl;

    std::string msg2 = network::ServerMessage::getGridAssinementMessage("jimmy",4);

    std::cout<<msg2<<std::endl;


    std::string msg3 = network::ServerMessage::getChatMessage("chat",2);

    std::cout<<msg3<<std::endl;


    std::string msg4 = network::ServerMessage::getCurrentTurnMessage(2);

    std::cout<<msg4 <<std::endl;

    Score score(1,2,3,4);
    std::string msg5 = network::ServerMessage::getScoreBroadCastMessage(score);
    std::cout<< msg5<<std::endl;


    network::ServerMessage::getServerMessage(msg5);
*/
    return 0;
}