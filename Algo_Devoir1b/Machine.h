#pragma once
#include "Queue.h"
#include "Piston.h"
#include <thread>

template<typename T>
class Machine
{
private:
	Queue<T> inQueue[1];
	Queue<T> outQueue[1];
	const short EMPTY_QUEUE_PROCESS_TIMEOUT = 1;
public:
	Machine() {};
	~Machine() {};
	void process(); //TODO
};

template<typename T>
void Machine<T>::process()
{
	if (inQueue->isEmpty())
	{
		std::this_thread::sleep_for(std::chrono::seconds(EMPTY_QUEUE_PROCESS_TIMEOUT));
	}
	else
	{
		Part* part = inQueue->pop();
		part->refine();
		outQueue->push(part);
	}

}

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




