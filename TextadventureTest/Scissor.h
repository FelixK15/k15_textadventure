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

#ifndef __K15_TEXTADVENTURETEST_SCISSOR__
#define __K15_TEXTADVENTURETEST_SCISSOR__

#include "Item.h"

namespace K15_Textadventure
{
	class Action;
	class Player;

	class Scissor
		: public Item
	{

	public:
		Scissor();

		virtual ActionResult performAction( Action &action,Player *player );
	};
}

#endif //__K15_TEXTADVENTURETEST_SCISSOR__