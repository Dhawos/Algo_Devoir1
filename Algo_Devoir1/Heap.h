#include <iostream>
template <typename T>
class Heap
{
private: //Implmentation model
	const static MAX_PILE = 100
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

}

template <typename T>
Heap<T>::Heap(const Heap&)
{

}

template <typename T>
Heap<T>::~Heap()
{

}

template <typename T>
void Heap<T>::push(const T&)
{

}

template <typename T>
Heap<T>::pop()
{

}

template <typename T>
bool Heap<T>::isEmpty() const
{

}

template <typename T>
int Heap<T>::size() const
{

}

template <typename T>
const T& Heap<T>::top() const
{

}

template <typename T>
const Heap<T> Heap<T>::operator=(const Heap<T>)
{

}

template<typename U>
std::ostream & operator<<(std::ostream &, const Heap<U>)
{
	
}
