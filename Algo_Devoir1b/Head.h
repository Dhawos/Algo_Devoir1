#pragma once
#include "Part.h"
class Head :public Part
{
private:
	const float TIME_TO_REFINE = 2;
public:
	Head() {};
	~Head(){};
	void refine() {};
	void print(ostream& os) const { os << "Piece(Head) - Refined : " << this->isRefined; };
};

