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
#ifndef __K15_TEXTADVENTURELIB_PLAYER__
#define __K15_TEXTADVENTURELIB_PLAYER__

#include <vector>
#include "Action.h"

namespace K15_Textadventure
{
	class Item;
	class Action;
	class Room;

	class Player
	{
	public:
		Player();
		virtual ~Player();

		bool hasAction(const std::string& name);
		void addAction(const Action& action);

		Item *getItem(const std::string& name);
		bool hasItem(const std::string& name);
		void addItem(Item *item);
		void removeItem(Item *item);

		void printItems();
		void printActions();

		void setCurrentRoom(Room *room);
		Room *getCurrentRoom();

		std::vector<Action> getActions();
		std::vector<Item*> getItems();

	protected:
		Room *m_curRoom;
		std::vector<Action> m_actions;
		std::vector<Item*> m_items;
	};
}

#endif // __K15_TEXTADVENTURELIB_PLAYER__