#include <utility>

//
// Created by sidahmedlahmer on 3/26/19.
//

#include <Player.h>
#include <boost/lexical_cast.hpp>
#include <FactoryEngine.h>

void Player::sendMessage(const std::string& msg) {
     auto out_message = std::make_shared<WssServer::OutMessage>();
     *out_message <<msg;
     m_connection->send(out_message);
}
Player::Player(const std::shared_ptr<WssServer::Connection>& conx) {
     if(conx != nullptr)
        m_connection = conx.get();
     else
         m_connection = nullptr;
     m_grid = new Grid();
}
unsigned char Player::get_id() const {
     return m_id;
}
void Player::set_id(int id) {
     Player::m_id = id;
}
const std::string &Player::get_username() const {
     return m_username;
}
void Player::set_username(char* username) {
     m_username = std::string(username);

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
Grid * Player::get_grid(){
    return m_grid;
}

std::string Player::get_pub_grid(){

    return "Pub grid";
}

std::string Player::get_priv_grid() {
    std::string ret;
    for (int line = 0; line < 10; ++line) {
        for (int column = 0; column < 10 ; ++column) {
            ret += m_grid->get(line,column)->to_pri_string()+std::string("----");
        }
        ret +=std::string("=========");
    }
    return ret;
}

void Player::set_logged_in(){
    m_logged_in = true;
}
bool Player::is_logged_in(){
    return m_logged_in;
}



Engine* Player::get_engine_by_id(int id){
    if(m_engine.size() >= id)
        return m_engine[id-1];
}
Engine* Player::create_engine(ENGINE_TYPE engine){
    Engine* ret = FactoryEngine::getEngine(engine);
    this->m_engine.push_back(ret);
    if(ret != nullptr)
        ret->set_id(m_engine.size()+1);
    return ret;
}

bool Player::is_ready() {
    return this->m_engine.size() == 1;
}

void Player::forward_chat_message(const std::string& msg){
    if(!m_mute_chat)
        send_message(msg);
}

int Player::get_engine_size() {
    return m_engine.size();
}

std::vector<Engine *> Player::get_engines() {
    return m_engine;
}
