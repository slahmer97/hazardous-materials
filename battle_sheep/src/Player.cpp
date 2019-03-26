#include <utility>

//
// Created by sidahmedlahmer on 3/26/19.
//

#include <Player.h>

void Player::sendMessage(std::string msg) {
     auto out_message = std::make_shared<WssServer::OutMessage>();
     *out_message <<msg;
     m_connection->send(out_message);
}
Player::Player(std::shared_ptr<WssServer::Connection> conx) {
     m_connection = std::move(conx);
}
unsigned char Player::get_id() const {
     return m_id;
}
void Player::set_id(unsigned char m_id) {
     Player::m_id = m_id;
}
const std::string &Player::get_username() const {
     return m_username;
}
void Player::set_username(const std::string &m_username) {
     Player::m_username = m_username;
}

bool Player::equals(Player * player) {
     return m_connection.get() == player->get_connection().get() ;
}

std::shared_ptr<WssServer::Connection> Player::get_connection() {
     return m_connection;
}

