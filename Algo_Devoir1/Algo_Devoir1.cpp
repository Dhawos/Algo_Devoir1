#include "stdafx.h"
#include <ctime>
#include <string>
#include <iostream>
#include "War.h"


#define MAX_SIZE 100
using namespace std;

int main()
{
	int playerHeapSize;
	string input;
	bool correctInput = false;
	while (!correctInput) {
		std::cout << "Combien de cartes faut-il generer par joueur ? (max 50)" << std::endl;
		std::getline(std::cin, input);
		try {
			playerHeapSize = std::stoi(input);
			if (playerHeapSize > 1 && playerHeapSize <= 50) {
				correctInput = true;
			}
			else {
				std::cout << "Erreur - L'entree doit etre un entier valide compris entre 1 et 50" << std::endl;
			}
		}
		catch (...) {
			std::cout << "Erreur - L'entree doit etre un entier valide compris entre 1 et 50 " << std::endl;
		}
	}
	srand(unsigned(time(NULL))); //Needed in order for cards to be random
	Heap<Card> deck = Heap<Card>(MAX_SIZE);
	for (int i = 0; i < MAX_SIZE ; i++) {
		Card newCard = Card();
		deck.push(newCard);
	}
	std::cout << "----------------Deck de depart----------------" << std::endl;
	std::cout << deck << std::endl;
	bool wantsToPlay = true;
	while (wantsToPlay){
		War game = War(playerHeapSize, deck, 3); //Timeout value not yet implemented
		game.distributeCards();
		/*Heap<Card>* gainDecks = */game.startGame();
		std::cout << "Voulez vous rejouer ? Tapez \"oui\" pour relancer, une autre entree quitte le programme..." << std::endl;
		std::getline(std::cin, input);
		wantsToPlay = input == "oui" || input == "o";
	}
	system("pause");
	return 0;
}

