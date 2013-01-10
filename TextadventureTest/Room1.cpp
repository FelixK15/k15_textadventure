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

#include "Room1.h"
#include "Room2.h"
#include "RedDoor.h"
#include "RedKey.h"
#include "Window.h"
using namespace K15_Textadventure;

Room1::Room1()
{
	m_name = "Hallway";
	m_description = "You see a long and brightful hallway in front of you.\n"\
					"The sun in shining through the big and colorful windows\n"\
					"and there's absolute silence.\n\n"\
					"You notice a little |RedKey| laying around on an old\n"\
					"and dusty desk. While you look around, you also notice a\n"\
					"|RedDoor| to your left.";

	m_itemList.push_back(new RedKey());
	m_itemList.push_back(new RedDoor());
	m_itemList.push_back(new Window());

	m_nextRooms.push_back(new Room2());
}