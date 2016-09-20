#pragma once
#include <list>
using std::list;

template<typename T>
class Queue
{
private: //Implmentation model
	const static int DEFAULT_SIZE = 100;
	list<T> array;
	int max_size;
public: // constructeurs et destructeurs:
	Queue();
	Queue(const Queue &);
	~Queue();
	// modificateurs
	void push(const T&);
	T pop();
	// sélecteurs
	int size() const;
	bool isEmpty() const;
	bool isFull() const;
	const T& first() const; // tête de la file
	const T& last() const; // queue de la file
							  // surcharges d'opérateurs
	const Queue<T>& operator = (const Queue<T>&);
	template <typename U> friend std::ostream& operator << (std::ostream& f, const Queue<U>& q);
};

template<typename T> Queue<T>::Queue()
{
	this->array = list<T>();
	this->max_size = DEFAULT_SIZE;
}

template<typename T>
 Queue<T>::Queue(const Queue & other)
{
	 this->array = other.array;
	 this->max_size = other.max_size;
}

template<typename T>
 Queue<T>::~Queue()
{
	 //Nothing to do
}

template<typename T>
 void Queue<T>::push(const T & element)
{
	 if (this->isFull()) {
		 throw std::length_error("Queue is empty, cannot pop object");
	 }
	 this->array.push_back(element);
}

template<typename T>
 T Queue<T>::pop()
{
	 if (this->isEmpty()) {
		 throw std::length_error("Queue is empty, cannot pop object");
	}
	T element = this->array.front();
	this->array.pop_front();
	return element;
}

template<typename T>
 int Queue<T>::size() const
{
	return this->array.size();
}

template<typename T>
 bool Queue<T>::isEmpty() const
{
	return this->array.empty();
}

template<typename T>
 bool Queue<T>::isFull() const
{
	 return this->array.size() >= this->max_size;
}

template<typename T>
 const T & Queue<T>::first() const
{
	 return this->array.front();
}

template<typename T>
 const T & Queue<T>::last() const
{
	 return this->array.back();
}

template<typename T>
 const Queue<T>& Queue<T>::operator=(const Queue<T>&)
{
	 this->array = other.array;
	 return *this;
}

template<typename U>
 std::ostream & operator<<(std::ostream & f, const Queue<U>& q)
{
	 for (int i = q.size() - 1; i >= 0; i--) {
		 f << q.array[i];
	 }
	 return f;
}
