// Algo_Devoir1b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Machine.h"
#include "Head.h"
#include "Skirt.h"
#include "Axis.h"
#include "Piston.h"

int main()
{
	//Initialize machines
	Machine<Head> MT;
	Machine<Skirt> MJ;
	Machine<Axis> MA;
	Machine<Piston> MP;
	//Trier les pièces qui arrivent du dock
	//Les envoyer dans la bonne machine
	//Des qu'une pièce de chaque est prête envoyer sur la machine principal
	//Récupérer l'assemblage et incrémenter un compteur
    return 0;
}

