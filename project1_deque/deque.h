/*
 * deque.h
 *
 *  Created on: Jan 8, 2016
 *      Author: matt
 */

#ifndef DEQUE_H_
#define DEQUE_H_

#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Deque {
	// Disallow copy and assignment
	Deque(const Deque&) = delete;
	Deque& operator=(const Deque&) = delete;
	int _capacity;
	T _data;
	const int CHUNK = 10;
	int _front;
	int _back;
	T *arr;
public:
	Deque();
	~Deque();
	void push_front(T); // Adds new element to the front (left end)
	void push_back(T); // Adds new element to the (right) end
	T& front(); // Throws (a logic_error) if deque is empty
	T& back(); // Throws if deque is empty
	T& at(size_t pos); // Throws if pos is out of the range [0,d.size()-1]
	void pop_front(); // Removes first logical deque element
	void pop_back(); // Removes last logical deque element
	size_t size() const; // NOTE: size_t is defined in <cstddef>
	bool empty();
	size_t capacity() const;
	   //  int* begin(); // Returns a pointer to the first element
				   //  int* end(); // Returns a pointer to one position past the last element
	T* begin();
	T* end();

	void print();
	void resize();
};

template<typename T>
Deque<T>::Deque() {
	_capacity = CHUNK;
	_front = _back = _capacity / 2;
	cout << "middle is " << _front << endl;
	arr = new T[_capacity];
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
T& Deque<T>::at(size_t pos) {
	//if(_front + pos < _front || _back + pos >= _back) throw logic_error("Out of range");
	if(empty()) throw logic_error("Arrary is empty");
	cout << "Calling at " << arr[_front + pos] << endl;
	return arr[_front + pos];
}
 // Throws if pos is out of the range [0,d.capacity()-1]
template<typename T>
void Deque<T>::pop_front() {
	if(size()) _front++;
}
 // Removes first logical deque element
template<typename T>
void Deque<T>::pop_back() {
	if(size()) _back--;
}
 // Removes last logical deque element
template<typename T>
size_t Deque<T>::size() const{
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
	cout << "old back is " << _back << endl;
	cout << "old front is " << _front << endl;
	int oldmiddle = (oldfront + ((oldback - oldfront) / 2)) - 1;
	cout << "Old middle is " << oldmiddle << endl;

	for(int i = _front; i < _back; ++i) {
		cout << temp[i] << " ";
	}
	cout << endl;

	_front = _back = _capacity / 2;
	cout << "new middle is " << _front << endl;
	for(int i = oldmiddle; i >= oldfront; --i) {
		//cout << temp[i] << endl;
		push_front(temp[i]);
	}
	for(int i = oldmiddle+1; i < oldback; ++i) {
		//cout << temp[i] << endl;
		push_back(temp[i]);
	}

	delete [] temp;
}

template<typename T>
bool Deque<T>::empty() {
	return size() == 0;
}

template<typename T>
T* Deque<T>::begin() {
	return arr + _front;
}

template<typename T>
T* Deque<T>::end() {
	return arr + _back;
}



#endif /* DEQUE_H_ */
