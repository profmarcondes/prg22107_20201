/*
 * TheRing.h
 *
 *  Created on: Mar 23, 2020
 *      Author: hugom
 */

#ifndef THERING_H_
#define THERING_H_

#include <iostream>
using namespace std;

class TheRing {
private:
	static TheRing * _instance;

private:
	TheRing();
	virtual ~TheRing();

public:
	void sayIt();

	static TheRing * getInstanceOf();
};

#endif /* THERING_H_ */
