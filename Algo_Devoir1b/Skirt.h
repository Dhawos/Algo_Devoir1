#pragma once
#include "Part.h"
class Skirt :
	public Part
{
private :
	const float TIME_TO_REFINE = 3;
public:
	Skirt() {};
	~Skirt() {};
	void refine() {

	};
	void print(ostream& os) const { os << "Piece(Skirt) - Refined : " << this->isRefined; };
};

