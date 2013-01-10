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

#ifndef __K15_TEXTADVENTURELIB_ROOM__
#define __K15_TEXTADVENTURELIB_ROOM__

#include <list>
#include "Item.h"

namespace K15_Textadventure
{
	class Room
	{
	public:
		Room(const Room &room2);

		const std::string& getName() const;
		const std::string& getDescription() const;

		void printDescription() const;
		void printName() const;
		void printItemList() const;

		void setPreviousRoom(Room *room);

		bool hasItem(const std::string& name) const;
		Item *getItem(const std::string& name);
		void removeItem(Item *item);

		bool hasNextRoom(const std::string& name) const;
		Room *getNextRoom(const std::string name);
		Room *getPreviousRoom();

	protected:
		Room()
		{
			m_previousRoom = NULL;
		};


		Room *m_previousRoom;
		std::list<Room*> m_nextRooms;
		std::list<Item*> m_itemList;
		std::string m_name;
		std::string m_description;
	};
}

#endif //__K15_TEXTADVENTURELIB_ROOM__