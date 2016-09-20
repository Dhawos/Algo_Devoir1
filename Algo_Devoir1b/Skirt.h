#pragma once
#include "Part.h"
class Skirt :
	public Part
{
private :
	const short TIME_TO_REFINE = 3000;
public:
	Skirt() {};
	~Skirt() {};
	void refine()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(TIME_TO_REFINE));
		std::cout << this << std::endl;
	};
	void print(ostream& os) const { os << "Piece(Skirt) - Refined : " << this->isRefined; };
};

