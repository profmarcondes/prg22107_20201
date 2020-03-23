/*
 * TheRing.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: hugom
 */

#include "TheRing.h"

TheRing * TheRing::_instance = 0;

TheRing::TheRing() {
	// TODO Auto-generated constructor stub

}

TheRing::~TheRing() {
	// TODO Auto-generated destructor stub
}

void TheRing::sayIt(){
	cout << "My precious!!!" << endl;
}

TheRing * TheRing::getInstanceOf(){
	if(_instance == 0)
		_instance = new TheRing();

	return _instance;
}


