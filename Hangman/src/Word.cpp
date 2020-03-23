/*
 * Word.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: hugom
 */

#include "Word.h"

Word::Word(string name, string hint): _word(name), _hint(hint) {
	_visible.resize(_word.size(), '-');
}

bool Word::hasLetter(char a){
	std::size_t found = _word.find(a);
	if (found != std::string::npos){
		while(found != std::string::npos){
			_visible[found] = a;
			found = _word.find(a, found+1);
		}
		return true;
	} else {
		return false;
	}
}

int Word::missing(){
	int count = 0;
	std::size_t found = _visible.find('-');
	while(found != std::string::npos){
		count++;
		found = _visible.find('-', found + 1);
	}
	return count;
}

void Word::print(){
	cout << _visible;
}
void Word::reset(){
	_visible.clear();
	_visible.resize(_word.size(), '-');
}
