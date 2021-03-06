#include "stdafx.h"
#include "Card.h"

using std::string;

//Constructors
Card::Card()
{
}


//Destructor
Card::~Card()
{
}

//Getters
short Card::getValue() const {
	return this->value;
}

string Card::getColor() const {
	if (this->color == Color::Red) {
		return "Red";
	}
	else {
		return "Black";
	}
}

int Card::getColorAsInt() const {
	return this->color;
}

short Card::getBonus() const {
	return this->bonus;
}

float Card::getScore() const {
	float playingValue = 1;
	playingValue *= this->value * this->bonus;
	if (this->color == Color::Red) {
		playingValue *= 1.5;
	}
	return playingValue;
}

std::ostream& operator<< (std::ostream& stream, const Card card) {
	stream << "Value : " << card.getValue() << " Bonus : " << card.getBonus() << " Color : " << card.getColor() << " Playing Value : " << card.getScore() << std::endl;
	return stream;
}

