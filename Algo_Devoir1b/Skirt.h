#pragma once
#include "Part.h"
#include <thread>

class Skirt :
	public Part
{
private :
	const int TIME_TO_REFINE = 3000;
public:
	Skirt() {};
	~Skirt() {};
	void refine()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(TIME_TO_REFINE));
		this->isRefined = true;
		std::cout << *this << std::endl;
	};
	void print(ostream& os) const { os << "Piece(Skirt) - Refined : " << this->isRefined; };
};

