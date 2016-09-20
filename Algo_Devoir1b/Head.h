#pragma once
#include "Part.h"
class Head :public Part
{
private:
	const short TIME_TO_REFINE = 2000;
public:
	Head() {};
	~Head(){};
	void refine()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(TIME_TO_REFINE));
		std::cout << this << std::endl;
	};
	void print(ostream& os) const { os << "Piece(Head) - Refined : " << this->isRefined; };
};

