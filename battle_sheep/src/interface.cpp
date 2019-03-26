#include "../include/interface.h"
#include "../include/b_switch.h"

Interface::Interface(): window(sf::VideoMode(200,200), "Battle Sheep") {
	//Initialisation
	//In the end here, there will be something like :
	//this->change_current_menu(new MainMenu());
}

void Interface::start() {

    B_Switch b("",0,0,100,50);
	//Starting the loop

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

			//Then we pass any other to the current Menu
			if(this->currentMenu != nullptr)
				this->currentMenu->handleEvent(&window,&event);

		}

		//We clear the window of any previous drawing
		window.clear();
		b.draw(&window);
		//We draw the current menu in a buffer
		if(this->currentMenu != nullptr)
			this->currentMenu->draw(&window);
		//We then display the buffer on the window
		window.display();


	}

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
