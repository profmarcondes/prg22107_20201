/*
 * Player.h
 *
 *  Created on: Mar 23, 2020
 *      Author: hugom
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Hangman.h"
#include <iostream>
using namespace std;

class Player {
public:
	Player(string n);
	void newGame();
	char askLetter();
	void printStats();

private:
	string _name;
	int _score;
	int _wins;
	int _times;
};

#endif /* PLAYER_H_ */
