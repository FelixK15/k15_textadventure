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

#include "TextadventurePlayer.h"

using namespace K15_Textadventure;

TextadventurePlayer::TextadventurePlayer()
{
	m_actions.push_back(Action("TAKE"));
	m_actions.push_back(Action("LOOKAT"));
	m_actions.push_back(Action("USE"));
	m_actions.push_back(Action("OPEN"));
	m_actions.push_back(Action("BACK"));
}