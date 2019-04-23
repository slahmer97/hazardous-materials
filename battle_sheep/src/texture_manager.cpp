#include "../include/texture_manager.h"

namespace TextureManager {


	/*
	 * Function initializing the texture manager, required for everything else to work
	 * Implemented at the end of the file to solve some bugs
	 */
	void Init(){
		using namespace TextureManager;


		std::cout<<"Loading Background texture atlas"<<std::endl;
		if(!Background::Atlas.loadFromFile(Background::atlasFileLocation)){
			std::cerr<<"Coulnd't load "<<Background::atlasFileLocation<<", aborting"<<std::endl;
			std::abort();
		}
		
		std::cout<<"Loading Planes texture atlas"<<std::endl;
		if(!Plane::Atlas.loadFromFile(Plane::atlasFileLocation)){
			std::cerr<<"Coulnd't load "<<Plane::atlasFileLocation<<", aborting"<<std::endl;
			std::abort();
		}
	
		std::cout<<"Loading Ships texture atlas"<<std::endl;
		if(!Ship::Atlas.loadFromFile(Ship::atlasFileLocation)){
			std::cerr<<"Coulnd't load "<<Ship::atlasFileLocation<<", aborting"<<std::endl;
			std::abort();
		}



	}

	namespace Ship {
		sf::Texture Atlas;
	}

	namespace Plane {
		sf::Texture Atlas;
	}

	namespace Background {
		sf::Texture Atlas;
	}

	namespace Other {
		sf::Texture Atlas;
	}
}




