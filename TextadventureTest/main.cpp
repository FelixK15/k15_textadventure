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
#include "Room1.h"
#include "Room2.h"
#include "TextadventurePlayer.h"
#include <iostream>
#include <string>

#define BACK "BAC"

using namespace K15_Textadventure;

int main()
{
	Room1 room;

	TextadventurePlayer player;
	std::vector<std::string> usableWords;
	usableWords.push_back(std::string("TAKE"));
	usableWords.push_back(std::string("BAC"));
	usableWords.push_back(std::string("USE"));
	usableWords.push_back(std::string("LOOKAT"));
	usableWords.push_back(std::string("OPEN"));
	usableWords.push_back(std::string("REDDOOR"));
	usableWords.push_back(std::string("YELLOWFLOWERS"));
	usableWords.push_back(std::string("REDKEY"));
	usableWords.push_back(std::string("WINDOW"));
	usableWords.push_back(std::string("SCISSOR"));
	player.setCurrentRoom(&room);

	char input[256];
	do{
		std::cout << "You are in: ";
		player.getCurrentRoom()->printName();
		player.getCurrentRoom()->printDescription();

		std::cout << "\n\nItems you can interact with:";
		player.getCurrentRoom()->printItemList();

		std::cout << "\n\nItems you have: ";
		player.printItems();

		std::cout << "\n\nActions you can perform: ";
		player.printActions();

		std::cout << "\n\n";

		std::cout << "What do you want to do? >";

		std::cin.getline(input,256);

		Result result;
		Parser::parseString(input,&result,usableWords);

		bool performed = false;

		if(result.getAction() == BACK){
			if(player.getCurrentRoom()->getPreviousRoom() != NULL){
				player.setCurrentRoom(player.getCurrentRoom()->getPreviousRoom());
				performed = true;
			}
		}else if(player.hasAction(result.getAction())){
			if(result.hasInteractableItem()){
				if(player.hasItem(result.getInteractableItem())){
					if(result.hasItem()){
						if(player.getCurrentRoom()->hasItem(result.getItem())){
							Item *item = player.getCurrentRoom()->getItem(result.getItem());
							Item *item2 = player.getItem(result.getInteractableItem());

							ActionResult performResult = item->performAction(Action(result.getAction().c_str()),item2,&player);

							if(performResult == ITEM_TAKEN){
								player.getCurrentRoom()->removeItem(item);
								player.addItem(item);
							}
							performed = true;
						}
					}
				}else if(result.hasItem()){
					if(player.hasItem(result.getItem())){
						Item *playerItem = player.getItem(result.getItem());
						playerItem->performAction(Action(result.getAction().c_str()),&player);
					}else if(player.getCurrentRoom()->hasItem(result.getItem())){
						Item *roomItem = player.getCurrentRoom()->getItem(result.getItem());
						ActionResult performResult = roomItem->performAction(Action(result.getAction().c_str()),&player);

						if(performResult == ITEM_TAKEN){
							player.getCurrentRoom()->removeItem(roomItem);
							player.addItem(roomItem);
						}

						performed = true;
					}
				}
			}else if(result.hasItem()){
				if(player.getCurrentRoom()->hasItem(result.getItem())){
					Item *roomItem = player.getCurrentRoom()->getItem(result.getItem());
					ActionResult performResult = roomItem->performAction(Action(result.getAction().c_str()),&player);

					if(performResult == ITEM_TAKEN){
						player.getCurrentRoom()->removeItem(roomItem);
						player.addItem(roomItem);
					}

					performed = true;
				}
			}
		}

		if(!performed && strcmp(input,"exit") != 0){
			std::cout << "\nUnfortunately that was not possible.";
		}

		std::cin.getline(input,256);

		std::system("cls");
	}while(strcmp(input,"exit") != 0);

}