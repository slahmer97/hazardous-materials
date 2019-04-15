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

		extern sf::IntRect ShipHoriLeft;
		extern sf::IntRect ShipHoriBody;
		extern sf::IntRect ShipHoriRight;
		
		/**
		 * Part of the atlas for an empty square
		 */
		extern sf::IntRect Empty;

		/*
		 * Part of the atlas for vertical ships :
		 * 
		 * /| Up
		 * || Body
		 * \| Down
		 *
		 */
		extern sf::IntRect ShipVertUp;
		extern sf::IntRect ShipVertBody;
		extern sf::IntRect ShipVertDown;
		
		
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
		extern sf::IntRect Water;//0

		extern sf::IntRect WaterUpLeft;//1
		extern sf::IntRect WaterUp;//2
		extern sf::IntRect WaterUpRight;//3

		extern sf::IntRect WaterLeft;//8
		extern sf::IntRect WaterRight;//4

		extern sf::IntRect WaterDownLeft;//7
		extern sf::IntRect WaterDown;//6
		extern sf::IntRect WaterDownRight;//5

		//Deep water textures
		
		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		extern sf::IntRect DeepWater;//0

		extern sf::IntRect DeepWaterUpLeft;//1
		extern sf::IntRect DeepWaterUp;//2
		extern sf::IntRect DeepWaterUpRight;//3

		extern sf::IntRect DeepWaterLeft;//8
		extern sf::IntRect DeepWaterRight;//4

		extern sf::IntRect DeepWaterDownLeft;//7
		extern sf::IntRect DeepWaterDown;//6
		extern sf::IntRect DeepWaterDownRight;//5

		//Sand textures
		
		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		extern sf::IntRect Sand;//0

		extern sf::IntRect SandUpLeft;//1
		extern sf::IntRect SandUp;//2
		extern sf::IntRect SandUpRight;//3

		extern sf::IntRect SandLeft;//8
		extern sf::IntRect SandRight;//4

		extern sf::IntRect SandDownLeft;//7
		extern sf::IntRect SandDown;//6
		extern sf::IntRect SandDownRight;//5

		//Air textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		extern sf::IntRect Air;//0

		extern sf::IntRect AirUpLeft;//1
		extern sf::IntRect AirUp;//2
		extern sf::IntRect AirUpRight;//3

		extern sf::IntRect AirLeft;//8
		extern sf::IntRect AirRight;//4

		extern sf::IntRect AirDownLeft;//7
		extern sf::IntRect AirDown;//6
		extern sf::IntRect AirDownRight;//5

		//Cloud textures

		/*     2
		 *   1 _ 3
		 *    / \
		 *  8 |0| 4
		 *    \_/
		 *   7   5
		 *     6  
		 */
		extern sf::IntRect Cloud;//0

		extern sf::IntRect CloudUpLeft;//1
		extern sf::IntRect CloudUp;//2
		extern sf::IntRect CloudUpRight;//3

		extern sf::IntRect CloudLeft;//8
		extern sf::IntRect CloudRight;//4

		extern sf::IntRect CloudDownLeft;//7
		extern sf::IntRect CloudDown;//6
		extern sf::IntRect CloudDownRight;//5
	}

	namespace Other {
		extern sf::Texture Atlas;
		const std::string atlasFileLocation = "assets/textures/other.png";
	}
}




#endif
