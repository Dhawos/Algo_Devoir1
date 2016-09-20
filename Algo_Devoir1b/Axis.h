#pragma once
#include "Part.h"
class Axis : public Part
{
private:
	const float TIME_TO_REFINE = 2.5;
public:
	Axis() {};
	~Axis() {};
	void refine() {};
	void print(ostream& os) const { os << "Piece(Axis) - Refined : " << this->isRefined; };
};

