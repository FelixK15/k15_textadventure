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

#include "Parser.h"
#include <map>
#include <algorithm>

using namespace K15_Textadventure;

void toUpperCase(std::string &string)
{
	std::transform(string.begin(),string.end(),string.begin(),toupper);
}

void Parser::parseString(const char *string,Result *result,std::vector<std::string> usableWords)
{
	const int SPACE = 32;
	
	std::map<int,int> setWordIndexes;
	std::string userInput = std::string(string);

	int indexStart = 0;
	int indexStop = 0;
	bool lastLetterWasSpace = false;
	
	for(int i = 0;i < userInput.length();i++){
		//Save the current letter of the string.
		char letter = userInput.at(i);
		
		if(lastLetterWasSpace){
			//If the last letter was a space continue here
			if(letter != SPACE){
				//if the current letter is not a space continue here

				//Set the new index start.
				indexStart = i;
				lastLetterWasSpace = false;
			}
		}else{
			//continue here if last letter was not a space.
			if(letter == SPACE){
				//if current letter is a space continue here
				lastLetterWasSpace = true;
				indexStop = i - indexStart;

				//add new word to the set.
				setWordIndexes[indexStart] = indexStop;
			}
		}

		if(i == userInput.length() -1){
			if(letter != SPACE){
				setWordIndexes[indexStart] = i;
			}
		}
	}

	std::vector<std::string> filteredWords;

	for(std::map<int,int>::iterator i = setWordIndexes.begin();i != setWordIndexes.end();i++){
		for(std::vector<std::string>::iterator j = usableWords.begin();j != usableWords.end();j++){
			std::string curWord = userInput.substr(i->first,i->second);
			toUpperCase(curWord);
			if((*j) == curWord){
				filteredWords.push_back(curWord);
			}
		}
	}

	if(filteredWords.size() > 0){
		result->setAction(filteredWords.at(0));
	}

	if(filteredWords.size() > 1){
		result->setItem(filteredWords.at(1));
	}

	if(filteredWords.size() > 2){
		result->setInteractableItem(filteredWords.at(2));
	}

	return;
}