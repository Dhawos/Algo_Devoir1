#include <iostream>
#include <vector>
using std::vector;

template <typename T>
class Stack
{
private: //Implmentation model
	const static int MAX_PILE = 100;
	vector<T> array;
public:
	//constructor and destructor
	Stack(int max = MAX_PILE); //Constructor
	Stack(const Stack&); //Copy Constructor
	~Stack(); //Destructor
	//Modificators
	void push(const T&);
	T pop();
	//Selectors
	bool isEmpty() const;
	int size() const;
	const T& top() const; //reads the top element
	//Operators overrides
	const Stack<T>& operator= (const Stack<T>);
	template <typename U> friend std::ostream& operator<< (std::ostream&, const Stack<U>);
};

template <typename T>
Stack<T>::Stack(int max = MAX_PILE)
{
	if (max < 1 || max > MAX_PILE) {
		throw std::invalid_argument("Stack size cannot exceed threshold");
	}
	this->array = vector<T>();
	this->array.reserve(max);
}

template <typename T>
Stack<T>::Stack(const Stack& other)
{
	this->array = other.array;
}

template <typename T>
Stack<T>::~Stack()
{
	//Nothing to do
}

template <typename T>
void Stack<T>::push(const T& element)
{
	if (this->array.size() >= MAX_PILE) {
		throw std::length_error("Stack capacity already at its maximum, cannot push object");
	}
	this->array.push_back(element);
}

template <typename T>
T Stack<T>::pop()
{
	if (this->array.empty()) {
		throw std::length_error("Stack is empty, cannot pop object");
	}
	T element = this->array.back();
	this->array.pop_back();
	return element;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return this->array.empty();
}

template <typename T>
int Stack<T>::size() const
{
	return this->array.size();
}

template <typename T>
const T& Stack<T>::top() const
{
	if (this->array.empty()) {
		throw std::length_error("Stack is empty, cannot read object");
	}
	return this->array.back();
}

template <typename T>
const Stack<T>& Stack<T>::operator=(const Stack<T> other)
{
	this->array = other.array;
	return *this;
}

template<typename U>
std::ostream & operator<<(std::ostream & stream, const Stack<U> Stack)
{
	for (int i = Stack.size() - 1; i >= 0; i--) {
		stream << Stack.array[i];
	}
	return stream;
}
