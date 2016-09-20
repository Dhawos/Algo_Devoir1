#pragma once
#include "Part.h"
#include <thread>
class Piston : public Part
{
private:
	const int TIME_TO_REFINE = 1000;
public:
	Piston() {
		std::this_thread::sleep_for(std::chrono::milliseconds(TIME_TO_REFINE));
		this->isRefined = true;
		std::cout << *this << std::endl;
	};
	~Piston() {};
	void print(ostream& os) const { os << "Piece(Piston) - Refined : " << this->isRefined; };
};

