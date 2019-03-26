#include <GameScheduler.h>

GameScheduler::onConnectionOpen(shared_ptr<WssServer::Connection>) {
	
}

GameScheduler::onMessageReceive(shared_ptr<WssServer::Connection connection, shared_ptr<WssServer::Message> message) {

}

GameScheduler::onConnectionClosed(shared_ptr<WssServer::Connection> connection, int status, str::string reason) {

}
