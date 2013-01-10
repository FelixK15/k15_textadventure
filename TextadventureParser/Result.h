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

#ifndef __K15_TEXTADVENTURE_PARSER_RESULT__
#define __K15_TEXTADVENTURE_PARSER_RESULT__

#include <string>

namespace K15_Textadventure
{
	class Result
	{
	public:
		Result();

		const std::string& getAction() const;
		const std::string& getItem() const;
		const std::string& getInteractableItem() const;

		void setAction(const std::string& action);
		void setItem(const std::string& item);
		void setInteractableItem(const std::string& interactableItem);

		bool hasAction();
		bool hasItem();
		bool hasInteractableItem();

		Result &operator=(const Result &otherResult);

	private:
		std::string m_action;
		std::string m_item;
		std::string m_interactableItem;
	};
}

#endif //__K15_TEXTADVENTURE_PARSER_RESULT__