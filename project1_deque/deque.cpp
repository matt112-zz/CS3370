/*
 * deque.cpp
 *
 *  Created on: Jan 8, 2016
 *      Author: matt
 */
#include <exception>
#include <iostream>
#include "deque.h"

using namespace std;

Deque::Deque() {
	_capacity = CHUNK;
	_front = _back = _capacity / 2;
	arr = new int[_capacity];
	_size = 0;
}

Deque::~Deque() {
	delete [] arr;
}

void Deque::push_front(int a) {
	if(_front <= 0) resize();

	_front--;
	arr[_front] = a;
}
// Adds new element to the front (left end)
void Deque::push_back(int a) {
	if(_back > _capacity-1) resize();

	arr[_back] = a;
	_back++;

}
 // Adds new element to the (right) end
int& Deque::front(){
	if(empty()) throw logic_error("Array is empty");

	return arr[_front];
}
 // Throws (a logic_error) if deque is empty
int& Deque::back() {
	if(empty()) throw logic_error("Array is empty");

	return arr[_back-1];
}
 // Throws if deque is empty
int& Deque::at(int pos) {
	return arr[pos];
}
 // Throws if pos is out of the range [0,d.capacity()-1]
void Deque::pop_front() {
	if(_front == _back) throw logic_error("Array is empty");

	arr[_front] = 0;
	_front++;
}
 // Removes first logical deque element
void Deque::pop_back() {
	if(empty()) throw logic_error("Array is empty");

	_back--;
	arr[_back] = 0;
}
 // Removes last logical deque element
int Deque::size() {
	return _back - _front;
}
 // NOTE: size_t is defined in <cstddef>
			   //  int* begin(); // Returns a pointer to the first element
			   //  int* end(); // Returns a pointer to one position past the last element

void Deque::print() {
	for(int i = _front; i < _back; ++i) {
		cout << arr[i] << " ";
	}
}

int Deque::capacity() {
	return _capacity;
}

void Deque::resize(){
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

bool Deque::empty() {
	return size() == 0;
}

