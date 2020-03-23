/*
 * main.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: hugom
 */

#include "Player.h"
#include <iostream>
using namespace std;

int main() {
	string input;
	cout << "Welcome Player! What is your name ? ";
	getline(cin, input);
	Player * p = new Player(input);

	char op = 'y';
	while(tolower(op) == 'y') {
	   p->newGame();
	   p->printStats();
	   cout << endl << "Would you like to play again ? (y/n) ";
       op = cin.get();
       cin.ignore();
	}

	return 0;
}

