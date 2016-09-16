// Algo_Devoir1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Card.h"
#include <iostream>
#include <ctime>

int main()
{
	srand(unsigned(time(NULL)));
	Card card = Card();
	std::cout << "Value : " << card.getValue() << " Bonus : " << card.getBonus() << " Color : " << card.getColor() << " Playing Value : " << card.getPlayingValue() << std::endl;
	system("pause");
	return 0;
}

