//============================================================================
// Name        : Hangman.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Hangman.h"
using namespace std;

Hangman::Hangman(Player * p): _player(p), _hang_word(0) {

}

bool Hangman::run(){
	char guess;
	_hang_word = _vocabulary.select_word();
	_hang_word->reset();
	_wrong_tries.clear();
	cout << "Welcome to Hangman Game! Enjoy this beauty" << endl;
	cout << endl << "Your secret word has " <<  _hang_word->size();
	cout << " letters and is a kind of " << _hang_word->hint() << endl;
	_hang_word->print();
	cout << endl;

	while(_wrong_tries.size() < 5 && _hang_word->missing()){
		guess = _player->askLetter();
		if(!_hang_word->hasLetter(guess)){
			if (std::find(_wrong_tries.begin(), _wrong_tries.end(), guess) == _wrong_tries.end())
				_wrong_tries.push_back(guess);
		}
		printStatus();
		cout  << endl;
	}

	if(!_hang_word->missing()) {
		cout << endl << "Congrats! You found the secret word " << _hang_word->str() << "!" << endl;
		return true;
	} else {
		cout << endl << "Game OVER ! You didn't found the secret word (" << _hang_word->str() << ")" << endl;
		return false;
	}
}

int Hangman::gameScore(){
	int score = 0;
	if (!_hang_word->missing()) {
		score = _hang_word->size() - _wrong_tries.size();
	}
	if (score < 0) score = 0;
	return score;
}


void Hangman::printStatus(){

	cout << endl << "Secret Word: " << _hang_word->visible() << "(" << _hang_word->missing() << "/" << _hang_word->size() << ")" << endl;

	if(_wrong_tries.size() > 0){
		cout << "Wrong tries: ";
		for (vector<char>::iterator vi=_wrong_tries.begin(); vi!=_wrong_tries.end(); vi++)
			 cout << *vi << " ";
		cout << endl;
	}

}
