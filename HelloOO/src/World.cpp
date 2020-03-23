/*
 * World.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: hugom
 */

#include "World.h"

World::World() {
	_nome = "World";
	sayHello();
	cout << _nome << " has " << _nome.size() << " letters" << endl;
}

World::World(string str) {
	_nome = str;
	sayHello();
}

void World::sayHello(){
	say("Hello");
}

void World::sayGoodbye(){
	say("Goodbye");
}

void World::sayHi(){
	say("Hi");
}

void World::say(string str){
	cout << str << " " << _nome << endl;
}

World::~World() {
	sayGoodbye();
}

