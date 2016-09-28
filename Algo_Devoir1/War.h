#pragma once
#include "Card.h"
#include "Stack.h"

class War
{
public:
	War(int nbCardsPerPlayer, Stack<Card> deck, Stack<Card> *playersGainDecks); //Constructor used for first game
	War(Stack<Card> *playersGainDecks); //Constructor used for subsequent games
	~War();
	Stack<Card>* startGame();
	void distributeCards();
private:
	char evaluateRound(Card,Card); //Returns the number associated to the player who won that round
	char evaluateGame(Stack<Card>,Stack<Card>); //Checks who won the game
	int nbCardsPerPlayer;
	Stack<Card> deck;
	bool finished;
	Stack<Card> playersDecks[2];
	Stack<Card> *playersGainDecks;
	int finalScores[2];
};

