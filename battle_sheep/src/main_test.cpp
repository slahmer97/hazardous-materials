#include <ServerMessage.h>
#include <ClientMessage.h>
#include <iostream>
#include <Player.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


int main(int argc,char**argv){

    Player p(nullptr);

    std::string s = "{\n"
                    "    \"msg_type\": \"move\",\n"
                    "    \"engine_id\": \"0\",\n"
                    "    \"x\": \"1\",\n"
                    "    \"y\": \"2\"\n"
                    "}";


    std::cout<<s;
    ClientMessage *c = ClientMessage::getClientMessage(s);





}