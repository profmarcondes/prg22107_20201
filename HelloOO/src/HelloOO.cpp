//============================================================================
// Name        : HelloOO.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "World.h"
#include "TheRing.h"
#include <iostream>
using namespace std;

void run();

World global_obj("Global World");

World * obj_ptr;
World * ptr2;

int main() {
	cout << "Entering main function" << endl;

	obj_ptr = new World("Dynamic World");

	ptr2 = obj_ptr;

	ptr2->sayHi();

	ptr2 = &global_obj;
	cout << "Accessing global_obj through pointer" << endl;

	ptr2->sayHi();

	global_obj.sayHi();

	TheRing * myPrecious = TheRing::getInstanceOf();

	myPrecious->sayIt();

	run();

	global_obj.sayHi();

	delete obj_ptr;

	return 0;
}

void run() {
	World local_obj;
	local_obj.sayHi();

	TheRing * obj = TheRing::getInstanceOf();
	obj->sayIt();
}
