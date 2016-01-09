/*
 * deque.h
 *
 *  Created on: Jan 8, 2016
 *      Author: matt
 */

#ifndef DEQUE_H_
#define DEQUE_H_

#include <exception>
#include <iostream>

using namespace std;

template<typename T>
class Deque {
	// Disallow copy and assignment
	Deque(const Deque&) = delete;
	Deque& operator=(const Deque&) = delete;
	int _capacity;
	int _size;
	const int CHUNK = 10;
	int _front;
	int _back;
	int *arr;
public:
	Deque();
	~Deque();
	void push_front(T); // Adds new element to the front (left end)
	void push_back(T); // Adds new element to the (right) end
	T& front(); // Throws (a logic_error) if deque is empty
	T& back(); // Throws if deque is empty
	T& at(T pos); // Throws if pos is out of the range [0,d.size()-1]
	void pop_front(); // Removes first logical deque element
	void pop_back(); // Removes last logical deque element
	int size(); // NOTE: size_t is defined in <cstddef>
				   //  int* begin(); // Returns a pointer to the first element
				   //  int* end(); // Returns a pointer to one position past the last element
	void print();
	void resize();
	bool empty();
	int capacity();
};

template<typename T>
Deque<T>::Deque() {
	_capacity = CHUNK;
	_front = _back = _capacity / 2;
	arr = new int[_capacity];
	_size = 0;
}

template<typename T>
Deque<T>::~Deque() {
	delete [] arr;
}

template<typename T>
void Deque<T>::push_front(T a) {
	if(_front <= 0) resize();

	_front--;
	arr[_front] = a;
}
// Adds new element to the front (left end)
template<typename T>
void Deque<T>::push_back(T a) {
	if(_back > _capacity-1) resize();

	arr[_back] = a;
	_back++;

}
 // Adds new element to the (right) end
template<typename T>
T& Deque<T>::front(){
	if(empty()) throw logic_error("Array is empty");

	return arr[_front];
}
 // Throws (a logic_error) if deque is empty
template<typename T>
T& Deque<T>::back() {
	if(empty()) throw logic_error("Array is empty");

	return arr[_back-1];
}
 // Throws if deque is empty
template<typename T>
T& Deque<T>::at(T pos) {
	return arr[pos];
}
 // Throws if pos is out of the range [0,d.capacity()-1]
template<typename T>
void Deque<T>::pop_front() {
	if(_front == _back) throw logic_error("Array is empty");

	arr[_front] = 0;
	_front++;
}
 // Removes first logical deque element
template<typename T>
void Deque<T>::pop_back() {
	if(empty()) throw logic_error("Array is empty");

	_back--;
	arr[_back] = 0;
}
 // Removes last logical deque element
template<typename T>
int Deque<T>::size() {
	return _back - _front;
}
 // NOTE: size_t is defined in <cstddef>
			   //  int* begin(); // Returns a pointer to the first element
			   //  int* end(); // Returns a pointer to one position past the last element
template<typename T>
void Deque<T>::print() {
	for(int i = _front; i < _back; ++i) {
		cout << arr[i] << " ";
	}
}

template<typename T>
int Deque<T>::capacity() {
	return _capacity;
}

template<typename T>
void Deque<T>::resize(){
	int *temp = arr;
	_capacity = _capacity + CHUNK;
	arr = new int[_capacity];
	int oldback = _back;
	int oldfront = _front;
	int oldmiddle = oldfront + ((oldback - oldfront) / 2);

	_front = _back = _capacity / 2;
	for(int i = oldmiddle; i >= oldfront; --i) {
		cout << temp[i] << endl;
		push_front(temp[i]);
	}
	for(int i = oldmiddle+1; i < oldback; ++i) {
		cout << temp[i] << endl;
		push_back(temp[i]);
	}

	delete [] temp;
}

template<typename T>
bool Deque<T>::empty() {
	return size() == 0;
}





#endif /* DEQUE_H_ */
