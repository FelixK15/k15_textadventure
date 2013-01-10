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

#include "Window.h"
#include <iostream>

using namespace K15_Textadventure;

Window::Window()
{
	m_name = "WINDOW";
	m_description = "A pretty colorful window.There's some sort of picture in it.";
}

ActionResult Window::performAction( Action &action,Player *player )
{
	Item::performAction(action,player);

	if(action.getName() == "OPEN" || action.getName() == "TAKE" || action.getName() == "USE"){
		std::cout << "\nYou push and pull the window, but nothing happened.";
	}

	return NOTHING_HAPPENED;
}

