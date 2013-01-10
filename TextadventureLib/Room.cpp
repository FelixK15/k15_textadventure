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

#include "Room.h"
#include <iostream>

using namespace K15_Textadventure;

Room::Room( const Room &room2 )
{
	this->m_name = room2.m_name;
	this->m_description = room2.m_description;
}

const std::string& Room::getName() const
{
	return m_name;
}

const std::string& Room::getDescription() const
{
	return m_description;
}

bool Room::hasItem( const std::string& name ) const
{
	for(std::list<Item*>::const_iterator i = m_itemList.begin();i != m_itemList.end();i++){
		if((*i)->getName() == name){
			return true;
		}
	}

	return false;
}

Item * Room::getItem( const std::string& name )
{
	for(std::list<Item*>::iterator i = m_itemList.begin();i != m_itemList.end();i++){
		if((*i)->getName() == name){
			return (*i);
		}
	}

	return NULL;
}

void Room::removeItem( Item *item )
{
	m_itemList.remove(item);
}

void Room::setPreviousRoom( Room *room )
{
	m_previousRoom = room;
}

void Room::printItemList() const
{
	for(std::list<Item*>::const_iterator i = m_itemList.begin();i != m_itemList.end();i++){
		std::cout << (*i)->getName() << " | ";
	}
}

void Room::printDescription() const
{
	std::cout << m_description << std::endl;
}

void Room::printName() const
{
	std::cout << m_name << std::endl;
}

bool Room::hasNextRoom( const std::string& name ) const
{
	for(std::list<Room*>::const_iterator i = m_nextRooms.begin();i != m_nextRooms.end();i++){
		if((*i)->getName() == name){
			return true;
		}
	}

	return false;
}

Room *Room::getNextRoom( const std::string name )
{
	for(std::list<Room*>::iterator i = m_nextRooms.begin();i != m_nextRooms.end();i++){
		if((*i)->getName() == name){
			return (*i);
		}
	}

	return NULL;
}

Room * Room::getPreviousRoom()
{
	return m_previousRoom;
}
