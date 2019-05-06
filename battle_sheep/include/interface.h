#ifndef DEF_INTERFACE
#define DEF_INTERFACE

#include <SFML/Graphics.hpp>
#include "../include/game_menu.h"
#include "../include/main_menu.h"
#include "../include/join_menu.h"
#include "../include/choose_menu.h"
#include "../include/menu.h"
#include "../include/box.h"

#include "../include/ServerMessage.h"
#include "../include/ClientMessageSender.h"

#include <client_wss.hpp>

/**
 * Main class of the client-side GUI
 */
class Interface
{
	/*Methods*/
	public:
		/**
		 * Constructor of the class
		 */
		Interface(WssClient * connection, std::string username = "player", std::string password = "");

		/**
		 * Start the rendering and updating loop, displaying the Interface
		 */
		void start();

		/**
		 * Change the currently used menu to another (main menu to game menu, etc)
		 */
		void change_current_menu(Menu* newMenu);

		/**
		 * Class destructor
		 */
		~Interface();

		/*Variables*/

		std::vector<Box*> boite;


	private:

		/**
		 * The player name and passwords
		 */
		std::string player, password;


		/**
		 * The window in which we render everything
		 */
		sf::RenderWindow window;
		/**
		 * The currently used menu
		 */
		Menu* currentMenu = nullptr;

		/**
		 * The connection to the server
		 */
		WssClient * co;


		/**
		 * Method used to receive messages from the server, it's here that everything is parseda first time
		 */
		void on_server_message_received( const std::shared_ptr<WssClient::Connection>& connection, std::shared_ptr<WssClient::InMessage> in_message  );

		/**
		 * Method used to handle error message, to free space in on_server_message_received
		 */
		void handle_errror_message(ServerMessage* m);

		/**
		 * Method called when the server is first started
		 */
		void on_server_connection_open( const std::shared_ptr<WssClient::Connection>& connection);

		/**
		 * Method called when the server is closed
		 */
		void on_server_connection_closed( const std::shared_ptr<WssClient::Connection>& connection, int status, const std::string &reason);

		/**
		 * Method called when we receive an error from the server
		 */
		void on_server_connection_error(const std::shared_ptr<WssClient::Connection>&, const SimpleWeb::error_code &ec);
};

#endif
