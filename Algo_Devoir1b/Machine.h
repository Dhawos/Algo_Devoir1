#pragma once
#include "Queue.h"
#include "Piston.h"
#include "Head.h"
#include "Axis.h"
#include "Skirt.h"
template<typename T>
class Machine
{
private:
	Queue<T> inQueue[1];
	Queue<T> outQueue[1];
public:
	Machine() {};
	~Machine() {};
	void givePart(T part){ this->inQueue[0].push(part); };
	void process() {}; //TODO
};

template<>
class Machine<Piston>
{
private:
	Queue<Part> inQueue[3];
	Queue<Piston> outQueue[3];
public:
	Machine() {};
	~Machine() {};
	void givePart(Head part) { this->inQueue[0].push(part); };
	void givePart(Skirt part) { this->inQueue[1].push(part); };
	void givePart(Axis part) { this->inQueue[2].push(part); };
	void process() {}; //TODO
};




