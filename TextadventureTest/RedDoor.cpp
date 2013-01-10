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

#include "RedDoor.h"
#include "Parser.h"
#include "Item.h"
#include "Action.h"
#include "Player.h"
#include "Room.h"
#include <iostream>

using namespace K15_Textadventure;

RedDoor::RedDoor()
{
	m_name = "REDDOOR";
	m_description = "A door with red color.";

	m_isClosed = true;
}

ActionResult RedDoor::performAction( Action &action, Player *player)
{
	if(action.getName() == "OPEN" || action.getName() == "USE"){
		if(m_isClosed){
			std::cout << "\nYou realize that the door is closed.";
		}else{
			Room *room2 = player->getCurrentRoom()->getNextRoom("The Garden");
			room2->setPreviousRoom(player->getCurrentRoom());
			player->setCurrentRoom(room2);
		}
	}else if(action.getName() == "LOOKAT"){
		printDescription();
	}else if(action.getName() == "TAKE"){
		std::cout << "\nThe door is definitely too heavy to take it...";
	}else{
		std::cout << "\nCertainly, that does not work.";
	}

	return NOTHING_HAPPENED;
}

ActionResult RedDoor::performAction( Action &action,Item *item,Player *player )
{
	if(action.getName() == "OPEN" || action.getName() == "USE"){
		if(item->getName() == "REDKEY"){
			m_isClosed = false;
			player->removeItem(item);

			std::cout << "\nYou opened the door with the red key.\nUnfortunately the key got destroyed in the process...";
			return ITEM_USED;
		}
	}

	return NOTHING_HAPPENED;
}
