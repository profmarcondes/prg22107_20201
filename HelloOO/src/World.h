/*
 * World.h
 *
 *  Created on: Mar 23, 2020
 *      Author: hugom
 */

#ifndef WORLD_H_
#define WORLD_H_


#include <iostream>
using namespace std;

class World {
private:
	string _nome;

	void say(string str);

public:
	World();
	World(string str);

	void sayHello();
	void sayGoodbye();
	void sayHi();

	virtual ~World();
};

#endif /* WORLD_H_ */
