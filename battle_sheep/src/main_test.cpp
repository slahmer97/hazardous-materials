#include <ServerMessage.h>
#include <ClientMessage.h>
#include <iostream>
#include <Player.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <FactoryEngine.h>


int main(int argc,char**argv){

    Engine*e = FactoryEngine::getBombardierSkill();
    Grid g;

    g.add_engine(e,0,1,1);

 //   g.normal_shot(1,1,1.0f);
    std::cout<<g.to_priv();





}