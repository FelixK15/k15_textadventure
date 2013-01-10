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

#ifndef __K15_TEXTADVENTURELIB_ITEM__
#define __K15_TEXTADVENTURELIB_ITEM__

#include <string>
#include <vector>
#include "Action.h"

namespace K15_Textadventure
{

	enum ActionResult
	{
		ITEM_TAKEN,
		NOTHING_HAPPENED,
		ITEM_USED
	};

	class Action;
	class Player;
	class Item;

	class Item
	{
	public:

		Item(const Item &item2);

		const std::string& getName() const;
		const std::string& getDescription() const;

		virtual ActionResult performAction(Action &action,Player *player)
		{
			if(action.getName() == "LOOKAT"){
				printDescription();
			}

			return NOTHING_HAPPENED;
		}

		virtual ActionResult performAction(Action &action,Item *item,Player *player)
		{
			return NOTHING_HAPPENED;
		}

		void printName() const;
		void printDescription() const;

		bool worksWith(Item &item);

	protected:

		Item(){};

		std::vector<Item> m_workableItems;
		std::string m_name;
		std::string m_description;
	};

	bool operator==(const Item &item,const Item &item2);
}

#endif //__K15_TEXTADVENTURELIB_ITEM__