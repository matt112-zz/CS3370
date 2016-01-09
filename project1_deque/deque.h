/*
 * deque.h
 *
 *  Created on: Jan 8, 2016
 *      Author: matt
 */

#ifndef DEQUE_H_
#define DEQUE_H_

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
	void push_front(int); // Adds new element to the front (left end)
	void push_back(int); // Adds new element to the (right) end
	int& front(); // Throws (a logic_error) if deque is empty
	int& back(); // Throws if deque is empty
	int& at(int pos); // Throws if pos is out of the range [0,d.size()-1]
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

#endif /* DEQUE_H_ */
