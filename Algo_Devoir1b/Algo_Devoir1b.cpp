// Algo_Devoir1b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Part.h"
#include "Machine.h"
#include "Head.h"
#include "Skirt.h"
#include "Axis.h"
#include "Piston.h"
#include <ctime>
#include <thread>
#include <typeinfo>

#define SPAWN_PART_TIMEOUT 500
#define NB_PISTONS_TO_BUILD 10
void spawnPart(int timeout, Part** newPart, bool* newPieceAvailable){
	while (true) {
		int typeofpiece = rand() % 3 + 1;
		if (typeofpiece == 1) {
			*newPart = new Head();
		}
		else if (typeofpiece == 2) {
			*newPart = new Skirt();
		}
		else {
			*newPart = new Axis();
		}
		std::cout << "A new piece has been spawned : " << **newPart << std::endl;
		*newPieceAvailable = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
	}
	
}

int main()
{
	srand(unsigned(time(NULL))); //Needed to have random part arriving
	//Initialize machines
	Machine<Head> MT;
	Machine<Skirt> MJ;
	Machine<Axis> MA;
	Machine<Piston> MP = Machine<Piston>(&MT.getOutQueue(),&MJ.getOutQueue(),&MA.getOutQueue());

	//Initializing slot for new parts arriving
	Part* part = NULL;
	bool newPieceAvailable = false; //This will be set to true each time we receive a new piece

	auto start = std::chrono::system_clock::now();

	//This will simulate a part that we get from the dock
	//Since we do not know what piece it will be, it's going to be a random part
	std::thread spawningThread(spawnPart, SPAWN_PART_TIMEOUT,&part,&newPieceAvailable);
	
	//start machine processes
	MT.run();
	MJ.run();
	MA.run();
	MP.run();

	//Sort pieces arriving from the dock
	while (MP.getOutQueue().size() <= NB_PISTONS_TO_BUILD) {
		if (newPieceAvailable) {
			newPieceAvailable = false;
			Head* pHead = dynamic_cast<Head*>(part);
			if (pHead == NULL) { //The part is not a Head
				Skirt* pSkirt = dynamic_cast<Skirt*>(part);
				if (pSkirt == NULL) { //The part is not a Skirt
					Axis* pAxis = dynamic_cast<Axis*>(part);
					if (pAxis == NULL) { throw std::bad_cast(); }
					else { //The part is an Axis
						MA.givePart(*pAxis);
					}
				}
				else {//The part is a skirt
					MJ.givePart(*pSkirt);
				}
			}
			else { //The part is a Head
				MT.givePart(*pHead);
			}
			free(part);
		}
	};
	auto end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	std::cout << "Il a fallu " << elapsed.count() << " secondes pour obtenir les " << NB_PISTONS_TO_BUILD << " pistons" << std::endl;
	system("pause");
    return 0;
}

