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

#include "Action.h"

using namespace K15_Textadventure;

Action::Action(const char* name)
{
	m_name = name;
}

const std::string Action::getName() const
{
	return std::string(m_name);
}