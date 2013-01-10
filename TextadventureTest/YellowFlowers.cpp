/**
 * author  Felix Klinge <f.klinge15@gmail.com>
 * version 1.0
 *
 * LICENSE
 * The sourcecode of this project is fully open source.
 * You can do whatever you want with it.
 *
 * DESCRIPTION
 * This is a Textadventure game that got developed during a 24 hours competition.
 * So don't expect to find clean code or comments.
 * 
 */

#include "YellowFlowers.h"
#include <iostream>
using namespace K15_Textadventure;

YellowFlowers::YellowFlowers()
{
	m_name = "YELLOWFLOWERS";
	m_description = "Beautiful yellow flowers. You smell at them and realize that they are smelling fantastic.";
}

ActionResult YellowFlowers::performAction( Action &action,Player *player )
{
	Item::performAction(action,player);

	if(action.getName() == "TAKE"){
		std::cout << "\nYou try to take them, but the thorns of the flower are too sharp.";
	}

	return NOTHING_HAPPENED;
}


ActionResult YellowFlowers::performAction( Action &action,Item *item,Player *player )
{
	if(action.getName() == "TAKE" || action.getName() == "USE"){
		if(item->getName() == "SCISSOR"){
			std::cout << "\nYou cut the flower off and take them from the ground.\nTHE GAME IS OVER NOW. YOUR MISSION WAS TO TAKE THE YELLOW FLOWERS ;)\nYOU CAN CONTINUE PLAYING BUT THERE'S NOTHING MORE TO DO.";
			return ITEM_TAKEN;
		}
	}

	return NOTHING_HAPPENED;
}
