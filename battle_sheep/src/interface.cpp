#include "../include/interface.h"

Interface::Interface(): window(sf::VideoMode(960,540), "Battle Sheep") {
	//Initialisation
	//In the end here, there will be something like :
	//this->change_current_menu(new MainMenu());
}

void Interface::start() {

    this->change_current_menu(new GameMenu());

	//Starting the loop


	std::cout<<"Starting loop"<<std::endl;
	while(this->window.isOpen()){
		//We check all event generated since the last loop
		sf::Event event;
		while(window.pollEvent(event)){
			//We then do things depending on which was detected
			if(event.type == sf::Event::Closed){
				window.close();
				break;
			}
			b.handleEvent(&window, &event);
			if(event.type == sf::Event::Resized ){
				if(event.size.width != 960 || event.size.height != 540)
					window.setSize(sf::Vector2u(960, 540));
				break;
			}

			//Then we pass any other to the current Menu
			if(this->currentMenu != nullptr)
				this->currentMenu->handleEvent(&window,&event);

		}

		//We clear the window of any previous drawing
		window.clear();
		//gmenu.draw(&window);
		//We draw the current menu in a buffer
		if(this->currentMenu != nullptr)
			this->currentMenu->draw(&window);
		//We then display the buffer on the window
		window.display();


	}
	std::cout<<"Cleaning up"<<std::endl;

}

void Interface::change_current_menu(Menu* newMenu){
	//If the previous menu is not null, delete it
	if(this->currentMenu != nullptr)
		delete this->currentMenu;
	//Then set the new one
	this->currentMenu = newMenu;
}



Interface::~Interface(){
	delete this->currentMenu;
}
