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

#define SPAWN_PART_TIMEOUT 1
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
		std::cout << "A new piece has been spawned" << std::endl;
		*newPieceAvailable = true;
		std::this_thread::sleep_for(std::chrono::seconds(timeout));
	}
	
}

int main()
{
	srand(unsigned(time(NULL))); //Needed to have random part arriving
	//Initialize machines
	Machine<Head> MT;
	Machine<Skirt> MJ;
	Machine<Axis> MA;
	Machine<Piston> MP;

	//Initializing slot for new parts arriving
	Part* part = NULL;
	bool* newPieceAvailable = new bool(false); //This will be set to true each time we receive a new piece
	//This will simulate a part that we get from the dock
	//Since we do not know what piece it will be, it's going to be a random part
	std::thread spawningThread(spawnPart, SPAWN_PART_TIMEOUT,&part,newPieceAvailable);
	
	//Sort pieces arriving from the dock
	while (true) {
		if (*newPieceAvailable) {
			*newPieceAvailable = false;
			std::cout << *part << std::endl;
			free(part);
		}
	};

	//Les envoyer dans la bonne machine
	//Des qu'une pièce de chaque est prête envoyer sur la machine principal
	//Récupérer l'assemblage et incrémenter un compteur
	free(newPieceAvailable);
    return 0;
}

