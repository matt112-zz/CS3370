/*
 * Cat.h
 *
 *  Created on: Feb 2, 2016
 *      Author: matthew
 */

#ifndef CAT_H_
#define CAT_H_

#include <string>
#include "Animal.h"
#include "Kennel.h"

using namespace std;

class Cat{

private:
	int id;
	string name;
	static Kennel k(sizeof(Cat))

	Cat(int i, const string& nm): name(nm) {
		id = i;
	}


public:
	static Cat* create(int id, const string& name) {
		return new Cat(id, name);
	}

	void* operator new() {
		Kennel::allocate();
	}

	void operator delete() {
		Kennel::deallocate();
	}
};

#endif /* CAT_H_ */
