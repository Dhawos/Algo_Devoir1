#pragma once
#include "Part.h"
#include <thread>

class Axis : public Part
{
private:
	const int TIME_TO_REFINE = 2500;
public:
	Axis() {};
	~Axis() {};
	void refine()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(TIME_TO_REFINE));
		this->isRefined = true;
		std::cout << *this << std::endl;
	};
	void print(ostream& os) const { os << "Piece(Axis) - Refined : " << this->isRefined; };
};

