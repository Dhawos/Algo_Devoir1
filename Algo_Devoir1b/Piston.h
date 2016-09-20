#pragma once
#include "Part.h"
class Piston : public Part
{
private:
	const float TIME_TO_REFINE = 1;
public:
	Piston() {};
	~Piston() {};
	void refine() {
	};
	void print(ostream& os) const { os << "Piece(Piston) - Refined : " << this->isRefined; };
};

