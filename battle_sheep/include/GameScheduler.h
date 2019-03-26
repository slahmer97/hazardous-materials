#ifndef HAZARDOUS_MATERIALS_CLIENTMESSAGE_H
#ifndef HAZARDOUS_MATERIALS_CLIENTMESSAGE_H

#include <Game.h>

class GameScheduler {
	public:
		static onConnectionOpen(shared_ptr<WssServer::Connection>); //
		static onMessageReceive(shared_ptr<WssServer::Connection>, shared_ptr<WssServer::Message>);
		static onConnectionClosed(shared_ptr<WssServer::Connection>, int, std::string);

	private:
		static std::vector<&Game> Games;
		static std::vector<&Player> Players;
};

#endif
