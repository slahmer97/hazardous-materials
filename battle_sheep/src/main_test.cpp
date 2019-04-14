#include <ServerMessage.h>
#include <ClientMessage.h>
#include <iostream>
#include <Player.h>


int main(int argc,char**argv){
    Player p(nullptr);
    std::cout<<p.get_priv_grid();
}