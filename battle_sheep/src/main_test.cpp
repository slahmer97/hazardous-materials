#include <ServerMessage.h>
#include <ClientMessage.h>
#include <iostream>
#include <Player.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


int main(int argc,char**argv){

    std::string msg = ClientMessage::getChoseGridMessage(1);

    std::cout<<msg;



}