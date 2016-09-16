// Algo_Devoir1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Card.h"
#include "Heap.h"
#include <iostream>
#include <ctime>

int main()
{
	srand(unsigned(time(NULL))); //Needed in order for cards to be random
	Heap<Card> deck = Heap<Card>();
	std::cout << deck << std::endl;
	system("pause");
	return 0;
}

