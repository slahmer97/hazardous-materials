#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

namespace TextureManager {
	
	
	/*
	 * Function initializing the texture manager, required for everything else to work
	 * Implemented at the end of the file to solve some bugs
	 */
	void Init();
	
	namespace Ship {
		extern sf::Texture Atlas;
		const std::string atlasFileLocation = "assets/textures/ships.png";

		/*
		 * Part of the Atlas for horizontal ships :
		 * _____________
		 * \___________/
		 * left|body|right
		 */

		const sf::IntRect ShipHoriLeft(0, 32, 32, 32);
		const sf::IntRect ShipHoriBody(0, 64, 32, 32);
		const sf::IntRect ShipHoriRight(0, 96, 32, 32);

		/**
		 * Part of the atlas for an empty square
		 */
		const sf::IntRect Empty(0,0,32,32);

		/*
		 * Part of the atlas for vertical ships :
		 * 
		 * /| Up
		 * || Body
		 * \| Down
		 *
		 */
		const sf::IntRect ShipVertUp(32,0, 32,32);
		const sf::IntRect ShipVertBody(64,0,32,32);
		const sf::IntRect ShipVertDown(96, 0, 32, 32);


	}

	namespace Plane {
		extern sf::Texture Atlas;
		const std::string atlasFileLocation = "assets/textures/planes.png";

	}

	namespace Background {
		extern sf::Texture Atlas;
		const std::string atlasFileLocation = "assets/textures/tiles.png";


		//Water textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		const sf::IntRect Water(32,32,32,32);//0

		const sf::IntRect WaterUpLeft(0,0,32,32);//1
		const sf::IntRect WaterUp(32,0,32,32);//2
		const sf::IntRect WaterUpRight(64,0,32,32);//3

		const sf::IntRect WaterLeft(0,32,32,32);//8
		const sf::IntRect WaterRight(64,32,32,32);//4

		const sf::IntRect WaterDownLeft(0,64,32,32);//7
		const sf::IntRect WaterDown(32,64,32,32);//6
		const sf::IntRect WaterDownRight(64,64,32,32);//5

		//Deep water textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		const sf::IntRect DeepWater(32,160,32,32);//0

		const sf::IntRect DeepWaterUpLeft(0,128,32,32);//1
		const sf::IntRect DeepWaterUp(32,128,32,32);//2
		const sf::IntRect DeepWaterUpRight(64,128,32,32);//3

		const sf::IntRect DeepWaterLeft(0,160,32,32);//8
		const sf::IntRect DeepWaterRight(64,160,32,32);//4

		const sf::IntRect DeepWaterDownLeft(0,192,32,32);//7
		const sf::IntRect DeepWaterDown(32,192,32,32);//6
		const sf::IntRect DeepWaterDownRight(64,192,32,32);//5

		//Sand textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		const sf::IntRect Sand(32,288,32,32);//0

		const sf::IntRect SandUpLeft(0,256,32,32);//1
		const sf::IntRect SandUp(32,256,32,32);//2
		const sf::IntRect SandUpRight(64,256,32,32);//3

		const sf::IntRect SandLeft(0,288,32,32);//8
		const sf::IntRect SandRight(64,288,32,32);//4

		const sf::IntRect SandDownLeft(0,320,32,32);//7
		const sf::IntRect SandDown(32,320,32,32);//6
		const sf::IntRect SandDownRight(64,320,32,32);//5

		//Air textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		const sf::IntRect Air(32,416,32,32);//0

		const sf::IntRect AirUpLeft(0,384,32,32);//1
		const sf::IntRect AirUp(32,384,32,32);//2
		const sf::IntRect AirUpRight(64,384,32,32);//3

		const sf::IntRect AirLeft(0,416,32,32);//8
		const sf::IntRect AirRight(64,416,32,32);//4

		const sf::IntRect AirDownLeft(0,448,32,32);//7
		const sf::IntRect AirDown(32,448,32,32);//6
		const sf::IntRect AirDownRight(64,448,32,32);//5

		//Cloud textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		const sf::IntRect Cloud(32,544,32,32);//0

		const sf::IntRect CloudUpLeft(0,512,32,32);//1
		const sf::IntRect CloudUp(32,512,32,32);//2
		const sf::IntRect CloudUpRight(64,512,32,32);//3

		const sf::IntRect CloudLeft(0,544,32,32);//8
		const sf::IntRect CloudRight(64,544,32,32);//4

		const sf::IntRect CloudDownLeft(0,576,32,32);//7
		const sf::IntRect CloudDown(32,576,32,32);//6
		const sf::IntRect CloudDownRight(64,576,32,32);//5
	}

	namespace Other {
		extern sf::Texture Atlas;
		const std::string atlasFileLocation = "assets/textures/other.png";
	}
}




#endif
