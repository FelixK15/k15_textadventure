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

#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "Action.h"
#include <iostream>

using namespace K15_Textadventure;


Player::Player()
{
	m_curRoom = NULL;
}

Player::~Player()
{

}

void Player::addItem( Item *item )
{
	m_items.push_back(item);
}

void Player::removeItem( Item *item )
{
	for(std::vector<Item*>::iterator i = m_items.begin();i != m_items.end();i++){
		if((*i) == item){
			m_items.erase(i);
			break;
		}
	}
}

void Player::printItems()
{
	for(std::vector<Item*>::iterator i = m_items.begin();i != m_items.end();i++){
		std::cout << (*i)->getName() << " | ";
	}
}

void Player::printActions()
{
	for(std::vector<Action>::iterator i = m_actions.begin();i != m_actions.end();i++){
		std::cout << i->getName() << " | ";
	}
}

void Player::setCurrentRoom( Room *room )
{
	m_curRoom = room;
}

Room * Player::getCurrentRoom()
{
	return m_curRoom;
}

std::vector<Action> Player::getActions()
{
	return m_actions;
}

std::vector<Item*> Player::getItems()
{
	return m_items;
}

bool Player::hasAction( const std::string& name )
{
	for(std::vector<Action>::iterator i = m_actions.begin();i != m_actions.end();i++){
		if(i->getName() == name){
			return true;
		}
	}

	return false;
}

Item * Player::getItem( const std::string& name )
{
	for(std::vector<Item*>::iterator i = m_items.begin();i != m_items.end();i++){
		if((*i)->getName() == name){
			return (*i);
		}
	}

	return NULL;
}

bool Player::hasItem( const std::string& name )
{
	for(std::vector<Item*>::iterator i = m_items.begin();i != m_items.end();i++){
		if((*i)->getName() == name){
			return true;
		}
	}

	return false;
}

void Player::addAction( const Action& action )
{
	m_actions.push_back(action);
}
