#pragma once
#include "Card.h"
#include "Heap.h"

class War
{
public:
	War(int nbCardsPerPlayer, Heap<Card> deck, Heap<Card> *playersGainDecks); //Constructor used for first game
	War(Heap<Card> *playersGainDecks); //Constructor used for subsequent games
	~War();
	Heap<Card>* startGame();
	void distributeCards();
private:
	char evaluateRound(Card,Card); //Returns the number associated to the player who won that round
	char evaluateGame(Heap<Card>,Heap<Card>); //Checks who won the game
	int nbCardsPerPlayer;
	Heap<Card> deck;
	bool finished;
	Heap<Card> playersDecks[2];
	Heap<Card> *playersGainDecks;
	int finalScores[2];
};

