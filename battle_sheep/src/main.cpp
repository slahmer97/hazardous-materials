#include <iostream>
#include <ServerMessage.h>
int main() {

    std::string msg = network::ServerMessage::getKillPlayerMessage(20);
    std::cout<<msg<<std::endl;

    std::string msg2 = network::ServerMessage::getGridAssinementMessage("jimmy",4);

    std::cout<<msg2<<std::endl;


    std::string msg3 = network::ServerMessage::getChatMessage("Hello world",2);

    std::cout<<msg3<<std::endl;


    std::string msg4 = network::ServerMessage::getCurrentTurnMessage(2);

    std::cout<<msg4 <<std::endl;

    Score score(1,2,3,4);
    std::string msg5 = network::ServerMessage::getScoreBroadCastMessage(score);
    std::cout<< msg5<<std::endl;


    network::ServerMessage::getServerMessage(msg5);

    return 0;
}