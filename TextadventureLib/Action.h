/**
 * author  Felix Klinge <f.klinge15@gmail.com>
 * version 1.0
 *
 * LICENSE
 * The sourcecode of this project is fully open source.
 * You can do whatever you want with it.
 *
 * DESCRIPTION
 * This is a Textadventure game that got developed during a 24 hours competetion.
 * So don't expect to find clean code or comments.
 * 
 */

#ifndef __K15_TEXTADVENTURELIB_ACTION__
#define __K15_TEXTADVENTURELIB_ACTION__

#include <string>

namespace K15_Textadventure
{
	class Item;

	class Action
	{
	public:
		Action(const char* name);

		const std::string getName() const;

	protected:
		const char *m_name;
	};
}

#endif //__K15_TEXTADVENTURELIB_ACTION__