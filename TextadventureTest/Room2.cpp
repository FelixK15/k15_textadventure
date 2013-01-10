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

#include "Room2.h"
#include "Scissor.h"
#include "YellowFlowers.h"

using namespace K15_Textadventure;

Room2::Room2()
{
	m_name = "The Garden";
	m_description = "You're standing in a beautiful garden.\n"\
					"It's full of red and yellow flowers.\n"\
					"When you're quite you can even hear the\n"\
					"birds tweeting.";

	m_itemList.push_back(new Scissor());
	m_itemList.push_back(new YellowFlowers());
}