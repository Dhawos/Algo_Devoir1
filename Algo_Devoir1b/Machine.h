#pragma once
#include "Queue.h"
#include "Piston.h"
template<typename T>
class Machine
{
private:
	Queue<T> inQueue[1];
	Queue<T> outQueue[1];
public:
	Machine() {};
	~Machine() {};
	void process() {}; //TODO
};

template<>
class Machine<Piston>
{
private:
	Queue<Piston> inQueue[3];
	Queue<Piston> outQueue[3];
public:
	Machine() {};
	~Machine() {};
	void process() {}; //TODO
};




