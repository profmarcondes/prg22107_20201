/*
 * Player.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: hugom
 */

#include "Player.h"

Player::Player(string n): _name(n) {
	_wins = 0;
	_times = 0;
	_score = 0;
}

void Player::newGame() {
	_times++;
	Hangman game(this);
	if(game.run())
		_wins++;
	_score += game.gameScore();
}

char Player::askLetter() {
	string input;
	cout << "Say a letter: ";
	getline(cin,input);
	return tolower(input[0]);
}

void Player::printStats() {
	cout << endl << "Stats for player " << _name << endl;
	cout << "Games played " << _times << endl;
	cout << "Wins " << _wins << endl;
	cout << "Win Percentage " << (double)_wins/_times << endl;
	cout << "Player Points " << _score << endl;
}
