/*
 * Kennel.h
 *
 *  Created on: Feb 2, 2016
 *      Author: matthew
 */

#ifndef KENNEL_H_
#define KENNEL_H_

class Kennel {
public:
	Kennel(size_t elemSize, size_t blockSize = 5);
	~Kennel();
	void* allocate();
	// Get a pointer inside a pre-allocated block for a new object
	void deallocate(void*); // Free an object's slot (push the address on the "free list")
};

#endif /* KENNEL_H_ */
