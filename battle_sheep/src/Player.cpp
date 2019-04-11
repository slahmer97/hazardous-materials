#include <utility>

//
// Created by sidahmedlahmer on 3/26/19.
//

#include <Player.h>
#include <boost/lexical_cast.hpp>

void Player::sendMessage(const std::string& msg) {
     auto out_message = std::make_shared<WssServer::OutMessage>();
     *out_message <<msg;
     m_connection->send(out_message);
}
Player::Player(const std::shared_ptr<WssServer::Connection>& conx) {
     m_connection = conx.get();
}
unsigned char Player::get_id() const {
     return m_id;
}
void Player::set_id(unsigned char id) {
     Player::m_id = id;
}
const std::string &Player::get_username() const {
     return m_username;
}
void Player::set_username(const std::string &username) {
     Player::m_username = username;
}
bool Player::equals(Player * player) {
     return m_connection == player->get_connection();
}
WssServer::Connection* Player::get_connection() {
     return m_connection;
}
void Player::desactivate_chat(){
    m_mute_chat = false;
}
void Player::activate_chat() {
    m_mute_chat = true;
}
bool Player::get_chat_status() {
    return !m_mute_chat;
}
void Player::send_message(const std::string& msg){
    m_connection->send(msg);
}
bool Player::is_me(const std::string& name) {
    return name == boost::lexical_cast<std::string>(m_connection);
}
Game * Player::get_game(){
    return m_game;
}
void Player::set_game(Game* _game){
    m_game = _game;
}

