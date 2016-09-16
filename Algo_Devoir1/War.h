#pragma once
#include "Card.h"
#include "Heap.h"

class War
{
public:
	War(int nbCardsPerPlayer, Heap<Card> deck,int delay);
	~War();
	Heap<Card>* startGame();
	void distributeCards();
private:
	char evaluateRound(Card,Card); //Returns the number associated to the player who won that round
	char evaluateGame(Heap<Card>,Heap<Card>); //Checks who won the game
	char turn;
	int delay;
	int nbCardsPerPlayer;
	Heap<Card> deck;
	bool finished;
	Heap<Card> playersDecks[2];
	Heap<Card> playersGainDecks[2];
	int finalScores[2];
};

