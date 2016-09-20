#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;
class Part
{
public:
	bool isRefined = false;
	Part() {};
	virtual ~Part() {};
	virtual void refine() {};
	virtual void print(ostream& os) const { os << "Piece - Refined : " << this->isRefined; };
	friend std::ostream& operator<< (ostream& os, const Part &part) {
		part.print(os);
		return os;
	}
};

