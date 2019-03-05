#include "../include/interface.h"

Interface::Interface(): window(sf::VideoMode(200,200), "Battle Sheep") {

}

void Interface::start() {

	//On démarre

	while(this->window.isOpen()){
		//On récupère tout les évenements (clavier, souris, etc...)
		sf::Event event;
		while(window.pollEvent(event)){
			//Et on les analyses
			if(event.type == sf::Event::Closed)
				window.close();
		}
		
		//On vide la fenètre de l'affichage précédent
		window.clear();
		//On dessine (pour l'instant rien
		window.display();


	}

	//On finit par nettoyer ce qu'il faut
}

