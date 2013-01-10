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

#include "Scissor.h"
#include "Action.h"
#include "Player.h"

#include <iostream>

using namespace K15_Textadventure;

Scissor::Scissor()
{
	m_name = "SCISSOR";
	m_description = "A very sharp scissor. You wonder that it is so sharp as it looks like the scissor is really old.";
}

ActionResult Scissor::performAction( Action &action,Player *player )
{
	Item::performAction(action,player);

	if(action.getName() == "TAKE"){
		if(!player->hasItem(getName())){
			std::cout << "\nYou look at the scissor and take it carefully as it looks very rusty.";
			return ITEM_TAKEN; 
		}		
	}else if(action.getName() == "USE"){
		std::cout << "\nYou wonder what you would use the scissor with.";
	}else{
		std::cout << "\nYou better not try to interact with the scissor in that way as it looks very sharp.";
	}

	return NOTHING_HAPPENED;
}