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
	Queue<T> outQueue;
	const static short EMPTY_QUEUE_PROCESS_TIMEOUT = 1;
	bool isRunning = true;
public:
	Machine() {};
	~Machine() {};
	void process();
	Queue<T>& getOutQueue() { return this->outQueue; };
	void givePart(T part) { this->inQueue[0].push(part); };
	void run();
	void stop();
};

template<typename T>
void Machine<T>::process()
{
	while (isRunning)
	{
		if (inQueue->isEmpty())
		{
			std::this_thread::sleep_for(std::chrono::seconds(EMPTY_QUEUE_PROCESS_TIMEOUT));
		}
		else
		{
			T part = inQueue->pop();

			short isMachineBroken = rand() % 4;
			if (isMachineBroken == 0)
			{
				short repairMachineTime = (rand() % 6 + 5);
				std::cout << "Machine for " << typeid(T).name() << " is broken, time to repair: " << repairMachineTime << " minutes." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(repairMachineTime * 60*;
				std::cout << "Machine for " << typeid(T).name() << " is repaired." << std::endl;
			}

			part.refine();
			outQueue.push(part);
		}
	}

}

template<typename T>
void Machine<T>::run()
{
	std::thread t(&Machine<T>::process, this);
	t.detach();
}

template<typename T>
void Machine<T>::stop()
{
	isRunning = false;
}

template<>
class Machine<Piston>
{
private:
	Queue<Head>* qHead;
	Queue<Skirt>* qSkirt;
	Queue<Axis>* qAxis;
	Queue<Piston> outQueue;
	const static short EMPTY_QUEUE_PROCESS_TIMEOUT = 1;
	bool isRunning = true;
public:
	Machine(Queue<Head>* q0, Queue<Skirt>* q1, Queue<Axis>* q2) {
		qHead = q0;
		qSkirt = q1;
		qAxis = q2;
	};
	~Machine() {};
	Queue<Piston>& getOutQueue() { return this->outQueue; };
	void process() {
		while (isRunning)
		{
			if (qHead->isEmpty() || qSkirt->isEmpty() || qAxis->isEmpty())
			{
				std::this_thread::sleep_for(std::chrono::seconds(EMPTY_QUEUE_PROCESS_TIMEOUT));
			}
			else
			{
				Head head = qHead->pop();
				Skirt skirt = qSkirt->pop();
				Axis axis = qAxis->pop();

				short isMachineBroken = rand() % 4;
				if (isMachineBroken == 0)
				{
					short repairMachineTime = (rand() % 6 + 5);
					std::cout << "Machine for Piston is broken, time to repair: " << repairMachineTime << " minutes." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(repairMachineTime * 60));
					std::cout << "Machine for Piston is repaired." << std::endl;
				}

				Piston piston;
				outQueue.push(piston);
			}
		}
	};
	void run() {
		std::thread t(&Machine<Piston>::process, this);
		t.detach();
	}
	void stop()
	{
		isRunning = false;
	}
};





