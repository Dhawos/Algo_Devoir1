#pragma once
#include "Queue.h"
#include "Piston.h"
#include "Head.h"
#include "Axis.h"
#include "Skirt.h"
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
	void givePart(T part) { this->inQueue[0].push(part); };
	void run();
};

template<typename T>
void Machine<T>::process()
{
	while (true)
	{
		if (inQueue->isEmpty())
		{
			std::this_thread::sleep_for(std::chrono::seconds(EMPTY_QUEUE_PROCESS_TIMEOUT));
		}
		else
		{
			T part = inQueue->pop();
			part.refine();
			outQueue->push(part);
		}
	}

}

template<typename T>
void Machine<T>::run()
{
	std::thread t(&Machine<T>::process, this);
}

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




