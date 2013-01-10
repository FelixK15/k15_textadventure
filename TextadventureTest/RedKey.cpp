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

#include "RedKey.h"
#include "RedDoor.h"
#include "Player.h"

#include <iostream>

using namespace K15_Textadventure;

RedKey::RedKey()
{
	m_name = "REDKEY";
	m_description = "A red key. Nothing special about it.";
}

ActionResult K15_Textadventure::RedKey::performAction( Action &action,Player *player )
{
	Item::performAction(action,player);

	if(action.getName() == "TAKE"){
		if(!player->hasItem(getName())){
			std::cout << "\nYou look around yourself to make sure that nobody's watching you while you take the key.";
			return ITEM_TAKEN;
		}
	}else{
		std::cout << "\nThat doesn't work.";
	}

	return NOTHING_HAPPENED;
}

ActionResult RedKey::performAction( Action &action,Item *item,Player *player )
{
	if(action.getName() == "USE"){
		if(item->getName() == "REDDOOR"){
			return item->performAction(Action("OPEN"),this,player);
		}
	}

	return NOTHING_HAPPENED;
}
