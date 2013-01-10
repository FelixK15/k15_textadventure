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

#include "Item.h"
#include <iostream>

using namespace K15_Textadventure;

Item::Item( const Item &item2 )
{
	this->m_name = item2.m_name;
	this->m_description = item2.m_description;
	this->m_workableItems = item2.m_workableItems;
}

const std::string& Item::getName() const
{
	return m_name;
}

const std::string& Item::getDescription() const
{
	return m_description;
}

void Item::printName() const
{
	std::cout << m_name << std::endl;
}

void Item::printDescription() const
{
	std::cout << m_description << std::endl;
}

bool Item::worksWith( Item &item )
{
	for(std::vector<Item>::iterator i = m_workableItems.begin();i != m_workableItems.end();i++){
		Item &curItem = (*i);
		if(*this == curItem){
			return true;
		}
	}

	return false;
}

bool K15_Textadventure::operator==( const Item &item,const Item &item2 )
{
	return item.getName() == item2.getName();
}
