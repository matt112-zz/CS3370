#ifndef DEQUE_H_
#define DEQUE_H_

#include <stdexcept>
#include <iostream>
#include <cstddef>

template<typename T>
class Deque {
	enum {CHUNK = 10};
	int _capacity;
	T _data;
	int _front;
	int _back;
	T *arr;
public:
	Deque();
	~Deque();
	void push_front(T); // Adds new element to the front (left end)
	void push_back(T); // Adds new element to the (right) end
	T& front(); // Throws (a std::logic_error) if deque is empty
	T& back(); // Throws if deque is empty
	T& at(size_t pos); // Throws if pos is out of the range [0,d.size()-1]
	void pop_front(); // Removes first logical deque element
	void pop_back(); // Removes last logical deque element
	size_t size() const; // NOTE: size_t is defined in <cstddef>
	bool empty() const;
	size_t capacity() const;
	T* begin();
	T* end();
	void debug_display();
	void display_n_dashes(int n);
	void resize();
};

template<typename T>
Deque<T>::Deque() {
	_capacity = CHUNK;
	_front = _back = _capacity/2;
	//std::cout << "middle is " << _front << std::endl;
	arr = new T[_capacity];
	debug_display();
}

template<typename T>
Deque<T>::~Deque() {
	delete [] arr;
	arr = nullptr;
}

// Adds new element to the front (left end)
template<typename T>
void Deque<T>::push_front(T a) {
	if(_front <= 0) resize();

	_front = _front-1;
	arr[_front] = a;
	debug_display();
}

// Adds new element to the (right) end
template<typename T>
void Deque<T>::push_back(T a) {
	if(_back > _capacity-1) resize();

	arr[_back] = a;
	_back = _back+1;
	debug_display();
}

template<typename T>
T& Deque<T>::front(){
	if(empty()) throw std::logic_error("Array is empty");

	return arr[_front];
}

// Throws (a std::logic_error) if deque is empty
template<typename T>
T& Deque<T>::back() {
	if(empty()) throw std::logic_error("Array is empty");

	return arr[_back-1];
}

// Throws if deque is empty
template<typename T>
T& Deque<T>::at(size_t pos) {
	if(empty()) throw std::logic_error("Arrary is empty");
	return arr[_front + pos];
}

 // Throws if pos is out of the range [0,d.capacity()-1]
template<typename T>
void Deque<T>::pop_front() {
	if(size()) _front++;
	debug_display();
}

// Removes first logical deque element
template<typename T>
void Deque<T>::pop_back() {
	if(size()) _back--;
	debug_display();
}

// Removes last logical deque element
template<typename T>
size_t Deque<T>::size() const{
	return _back - _front;
}

template<typename T>
size_t Deque<T>::capacity() const{
	return _capacity;
}

template<typename T>
void Deque<T>::resize(){
	T *temp = arr;
	_capacity = _capacity + CHUNK;
	arr = new T[_capacity];
	int oldback = _back;
	int oldfront = _front;
	//std::cout << "old back is " << _back << std::endl;
	//std::cout << "old front is " << _front << std::endl;
	int oldmiddle = (oldfront + ((oldback - oldfront) / 2)) - 1;
	//std::cout << "Old middle is " << oldmiddle << std::endl;

	_front = _back = _capacity / 2;
	//std::cout << "new middle is " << _front << std::endl;
	for(int i = oldmiddle; i >= oldfront; --i) {
		push_front(temp[i]);
	}
	for(int i = oldmiddle+1; i < oldback; ++i) {
		push_back(temp[i]);
	}

	delete [] temp;
	temp = nullptr;
}

template<typename T>
bool Deque<T>::empty() const{
	return size() == 0;
}

// Returns a pointer to the first element
template<typename T>
T* Deque<T>::begin() {
	return arr + _front;
}

// Returns a pointer to one position past the last element
template<typename T>
T* Deque<T>::end() {
	return arr + _back;
}

template<typename T>
void Deque<T>::display_n_dashes(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << " -";
    }
}

template<typename T>
void Deque<T>::debug_display() {
    std::cout << "deque: [";

   display_n_dashes(_front);

    for (T t : *this) {
        std::cout << ' ' << t;
    }

    display_n_dashes(capacity()-(_back));

    std::cout <<" ]" << std::endl;
}

#endif /* DEQUE_H_ */
