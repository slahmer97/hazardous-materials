#include <ServerMessage.h>
#include <ClientMessage.h>
#include <iostream>
#include <Player.h>


int main(int argc,char**argv){

    std::string msg = ClientMessage::getChoseGridMessage(1);
    std::cout<<msg;

}