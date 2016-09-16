#include <iostream>
#include <vector>
using std::vector;

template <typename T>
class Heap
{
private: //Implmentation model
	const static int MAX_PILE = 100;
	vector<T> array;
public:
	//constructor and destructor
	Heap(int max = MAX_PILE); //Constructor
	Heap(const Heap&); //Copy Constructor
	~Heap(); //Destructor
	//Modificators
	void push(const T&);
	T pop();
	//Selectors
	bool isEmpty() const;
	int size() const;
	const T& top() const; //reads the top element
	//Operators overrides
	const Heap<T>& operator= (const Heap<T>);
	template <typename U> friend std::ostream& operator<< (std::ostream&, const Heap<U>);
};

template <typename T>
Heap<T>::Heap(int max = MAX_PILE)
{
	this->array = vector<T>(max);
}

template <typename T>
Heap<T>::Heap(const Heap& other)
{
	this->array = other.array;
}

template <typename T>
Heap<T>::~Heap()
{
	//Nothing to do
}

template <typename T>
void Heap<T>::push(const T& element)
{
	this->array.push_back(element);
}

template <typename T>
T Heap<T>::pop()
{
	T element = this->array.back();
	this->array.pop_back;
	return element;
}

template <typename T>
bool Heap<T>::isEmpty() const
{
	return this->array.empty();
}

template <typename T>
int Heap<T>::size() const
{
	return this->array.size();
}

template <typename T>
const T& Heap<T>::top() const
{
	return this->array.back();
}

template <typename T>
const Heap<T>& Heap<T>::operator=(const Heap<T>)
{
	return Heap<T>(this)&;
}

template<typename U>
std::ostream & operator<<(std::ostream & stream, const Heap<U> heap)
{
	for (int i = heap.size() - 1; i >= 0; i--) {
		stream << heap.array[i];
	}
	return stream;
}
