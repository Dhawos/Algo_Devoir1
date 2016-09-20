#pragma once
class Part
{
private:
	bool isRefined = false;
public:
	Part() {};
	virtual ~Part() {};
	virtual void refine() = 0;
};

