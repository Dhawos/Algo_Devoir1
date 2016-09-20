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
	Heap<Card>* gainDecks = new Heap<Card>[2];
	while (wantsToPlay){
		if (gainDecks[0].size() == 0 && gainDecks[1].size() == 0) {
			War game = War(playerHeapSize, deck,gainDecks);
			gainDecks = game.startGame();
		}
		else {
			War game = War(gainDecks);
			gainDecks = game.startGame();
		}
		std::cout << std::endl;
		std::cout << "-------------Nouveau Deck du joueur 1---------------" << std::endl;
		std::cout << gainDecks[0] << std::endl;
		std::cout << "-------------Nouveau Deck du joueur 2---------------" << std::endl;
		std::cout << gainDecks[1] << std::endl;
		if (gainDecks[0].size() == 0 || gainDecks[1].size() == 0) {
			std::cout << "L'un des deux joueurs n'a plus de cartes, fin de la partie" << std::endl;
			wantsToPlay = false;
		}
		else {
			std::cout << "Voulez vous rejouer ? Tapez \"oui\" pour relancer, une autre entree quitte le programme..." << std::endl;
			std::getline(std::cin, input);
			wantsToPlay = input == "oui" || input == "o";
		}
	}
	delete [] gainDecks;
	system("pause");
	return 0;
}

