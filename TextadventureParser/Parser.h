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

#ifndef __K15_TEXTADVENTURE_PARSER__
#define __K15_TEXTADVENTURE_PARSER__

#include "Result.h"
#include <string>
#include <vector>

namespace K15_Textadventure
{
	class Parser
	{
	public:
		static void parseString(const char *string,Result *result,std::vector<std::string> usableWords);
	};
}

#endif //__K15_TEXTADVENTURE_PARSER__