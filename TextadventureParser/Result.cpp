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

#include "Result.h"

using namespace K15_Textadventure;

Result::Result()
	: m_action(""),
	  m_item(""),
	  m_interactableItem("")
{

}

const std::string& Result::getAction() const
{
	return m_action;
}

const std::string& Result::getItem() const
{
	return m_item;
}

const std::string& Result::getInteractableItem() const
{
	return m_interactableItem;
}

bool Result::hasAction()
{
	return m_action != "";
}

bool Result::hasItem()
{
	return m_item != "";
}

bool Result::hasInteractableItem()
{
	return m_interactableItem != "";
}

Result & Result::operator=( const Result &otherResult )
{
	this->m_action = otherResult.m_action;
	this->m_item = otherResult.m_item;
	this->m_interactableItem = otherResult.m_interactableItem;

	return *this;
}

void Result::setAction( const std::string& action )
{
	this->m_action = action;
}

void Result::setItem( const std::string& item )
{
	this->m_item = item;
}

void Result::setInteractableItem( const std::string& interactableItem )
{
	this->m_interactableItem = interactableItem;
}
