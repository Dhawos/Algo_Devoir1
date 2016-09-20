#include "stdafx.h"
#include "War.h"
#include <iostream>

War::War(int nbCardsPerPlayer,Heap<Card> deck, Heap<Card> *playersGainDecks)
{
	this->nbCardsPerPlayer = nbCardsPerPlayer;
	this->deck = deck;
	this->playersDecks[0] = Heap<Card>(this->nbCardsPerPlayer);
	this->playersDecks[1] = Heap<Card>(this->nbCardsPerPlayer);
	this->playersGainDecks = playersGainDecks;
	this->distributeCards();
}

War::War(Heap<Card> *playersGainDecks)
{
	Heap<Card> deckP1 = playersGainDecks[0];
	Heap<Card> deckP2 = playersGainDecks[1];
	if (deckP1.size() <= deckP2.size()) {
		this->nbCardsPerPlayer = deckP1.size();
	}
	else {
		this->nbCardsPerPlayer = deckP2.size();
	}
	this->playersDecks[0] = deckP1;
	this->playersDecks[1] = deckP2;
	delete[] this->playersGainDecks;
	this->playersGainDecks = new Heap<Card>[2];
}

War::~War()
{
}

Heap<Card>* War::startGame() {
	std::cout << "-------------Deck du joueur 1---------------" << std::endl;
	std::cout << playersDecks[0] << std::endl;
	std::cout << "-------------Deck du joueur 2---------------"  << std::endl;
	std::cout << playersDecks[1] << std::endl;
	std::cout << std::endl;
	std::cout << "Les decks sont prets, la partie va commencer" << std::endl;
	system("pause");
	Card card0, card1;
	for (int i = 1; i <= nbCardsPerPlayer; i++) {
		std::cout << "Debut du round " << i << std::endl;
		card0 = playersDecks[0].pop();
		card1 = playersDecks[1].pop();
		std::cout << "Joueur 1 joue : " << card0 << std::endl;
		std::cout << "Joueur 2 joue : " << card1 << std::endl;
		char result = evaluateRound(card0, card1);
		if (result == -1) {
			playersGainDecks[0].push(card0);
			playersGainDecks[1].push(card1);
			std::cout << "Egalite" << std::endl;
		}
		else {
			playersGainDecks[result].push(card0);
			playersGainDecks[result].push(card1);
			std::cout << "Joueur " << result + 1 << " gagne ce round !" << std::endl;
		}
		std::cout << "Fin du round" << std::endl;
		system("pause");
	}
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "-------------Deck de gain du joueur 1---------------" << std::endl;
	std::cout << playersGainDecks[0] << std::endl;
	std::cout << "-------------Deck de gain du joueur 2---------------" << std::endl;
	std::cout << playersGainDecks[1] << std::endl;
	std::cout << std::endl;

	int winner = evaluateGame(playersGainDecks[0], playersGainDecks[1]);
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "------------Resultats--------------" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	if (winner == -1) {
		std::cout << "Egalite ! Les deux joueurs ont : " << finalScores[0] << " points." << std::endl;
	}
	else {
		std::cout << "Score Final :  " << finalScores[0] << " - "  <<  finalScores[1] << std::endl;
		std::cout << "Victoire du joueur  " << winner + 1 << " !" << std::endl;
	}
	return playersGainDecks;
}

void War::distributeCards() {
	for (int i = 1; i <= nbCardsPerPlayer; i++) {
		this->playersDecks[0].push(this->deck.pop());
		this->playersDecks[1].push(this->deck.pop());
	}
}

char War::evaluateRound(Card card0,Card card1) {
	if (card0.getValue() > card1.getValue()) {
		return 0;
	}
	else if(card0.getValue() < card1.getValue()){
		return 1;
	}
	else {
		if (card0.getColor() > card1.getColor()) {
			return 0;
		}
		else if (card0.getColor() < card1.getColor()) {
			return 1;
		}
		else {
			return -1;
		}
	}
}

char War::evaluateGame(Heap<Card> heap0, Heap<Card> heap1) {
	Heap<Card> copyHeap0 = heap0;
	Heap<Card> copyHeap1 = heap1;
	int sum0 = 0;
	int sum1 = 0;
	while (!copyHeap0.isEmpty()) {
		sum0 += copyHeap0.pop().getScore();
	}
	while (!copyHeap1.isEmpty()) {
		sum1 += copyHeap1.pop().getScore();
	}
	finalScores[0] = sum0;
	finalScores[1] = sum1;
	if (sum0 > sum1) {
		return 0;
	}
	else if (sum0 < sum1) {
		return 1;
	}
	else {
		return -1;
	}
}