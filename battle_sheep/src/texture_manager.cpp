#include "../include/texture_manager.h"

namespace TextureManager {


	/*
	 * Function initializing the texture manager, required for everything else to work
	 * Implemented at the end of the file to solve some bugs
	 */
	void Init(){
		using namespace TextureManager;


		if(!Background::Atlas.loadFromFile(Background::atlasFileLocation)){
			std::cerr<<"Coulnd't load "<<Background::atlasFileLocation<<", aborting"<<std::endl;
			std::abort();
		}
		if(!Plane::Atlas.loadFromFile(Plane::atlasFileLocation)){
			std::cerr<<"Coulnd't load "<<Plane::atlasFileLocation<<", aborting"<<std::endl;
			std::abort();
		}
		if(!Ship::Atlas.loadFromFile(Ship::atlasFileLocation)){
			std::cerr<<"Coulnd't load "<<Ship::atlasFileLocation<<", aborting"<<std::endl;
			std::abort();
		}



	}

	namespace Ship {
		sf::Texture Atlas;

		/*
		 * Part of the Atlas for horizontal ships :
		 * _____________
		 * \___________/
		 * left|body|right
		 */

		sf::IntRect ShipHoriLeft(0, 32, 32, 32);
		sf::IntRect ShipHoriBody(0, 64, 32, 32);
		sf::IntRect ShipHoriRight(0, 96, 32, 32);

		/**
		 * Part of the atlas for an empty square
		 */
		sf::IntRect Empty(0,0,32,32);

		/*
		 * Part of the atlas for vertical ships :
		 * 
		 * /| Up
		 * || Body
		 * \| Down
		 *
		 */
		sf::IntRect ShipVertUp(32,0, 32,32);
		sf::IntRect ShipVertBody(64,0,32,32);
		sf::IntRect ShipVertDown(96, 0, 32, 32);


	}

	namespace Plane {
		sf::Texture Atlas;

	}

	namespace Background {
		sf::Texture Atlas;


		//Water textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		sf::IntRect Water(32,32,32,32);//0

		sf::IntRect WaterUpLeft(0,0,32,32);//1
		sf::IntRect WaterUp(0,32,32,32);//2
		sf::IntRect WaterUpRight(0,64,32,32);//3

		sf::IntRect WaterLeft(32,0,32,32);//8
		sf::IntRect WaterRight(32,64,32,32);//4

		sf::IntRect WaterDownLeft(64,0,32,32);//7
		sf::IntRect WaterDown(64,32,32,32);//6
		sf::IntRect WaterDownRight(64,64,32,32);//5

		//Deep water textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		sf::IntRect DeepWater(160,32,32,32);//0

		sf::IntRect DeepWaterUpLeft(128,0,32,32);//1
		sf::IntRect DeepWaterUp(128,32,32,32);//2
		sf::IntRect DeepWaterUpRight(128,64,32,32);//3

		sf::IntRect DeepWaterLeft(160,0,32,32);//8
		sf::IntRect DeepWaterRight(160,64,32,32);//4

		sf::IntRect DeepWaterDownLeft(192,0,32,32);//7
		sf::IntRect DeepWaterDown(192,32,32,32);//6
		sf::IntRect DeepWaterDownRight(192,64,32,32);//5

		//Sand textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		sf::IntRect Sand(288,32,32,32);//0

		sf::IntRect SandUpLeft(256,0,32,32);//1
		sf::IntRect SandUp(256,32,32,32);//2
		sf::IntRect SandUpRight(256,64,32,32);//3

		sf::IntRect SandLeft(288,0,32,32);//8
		sf::IntRect SandRight(288,64,32,32);//4

		sf::IntRect SandDownLeft(320,0,32,32);//7
		sf::IntRect SandDown(320,32,32,32);//6
		sf::IntRect SandDownRight(320,64,32,32);//5

		//Air textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		sf::IntRect Air(416,32,32,32);//0

		sf::IntRect AirUpLeft(384,0,32,32);//1
		sf::IntRect AirUp(384,32,32,32);//2
		sf::IntRect AirUpRight(384,64,32,32);//3

		sf::IntRect AirLeft(416,0,32,32);//8
		sf::IntRect AirRight(416,64,32,32);//4

		sf::IntRect AirDownLeft(448,0,32,32);//7
		sf::IntRect AirDown(448,32,32,32);//6
		sf::IntRect AirDownRight(448,64,32,32);//5

		//Cloud textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		sf::IntRect Cloud(32,32,32,32);//0

		sf::IntRect CloudUpLeft(512,0,32,32);//1
		sf::IntRect CloudUp(512,32,32,32);//2
		sf::IntRect CloudUpRight(512,64,32,32);//3

		sf::IntRect CloudLeft(544,0,32,32);//8
		sf::IntRect CloudRight(544,64,32,32);//4

		sf::IntRect CloudDownLeft(576,0,32,32);//7
		sf::IntRect CloudDown(576,32,32,32);//6
		sf::IntRect CloudDownRight(576,64,32,32);//5
	}

	namespace Other {
		sf::Texture Atlas;
	}
}




