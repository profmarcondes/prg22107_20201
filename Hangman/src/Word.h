/*
 * Word.h
 *
 *  Created on: Mar 23, 2020
 *      Author: hugom
 */

#ifndef WORD_H_
#define WORD_H_

#include <iostream>
#include <string>
using namespace std;

class Word {
private:
	string _word;
	string _hint;
	string _visible;

public:
	Word(string name, string hint);

	bool hasLetter(char a);
	int missing();
	string str() { return _word; }
	string hint() { return _hint; }
	string visible() { return _visible; }
	int size() { return _word.size(); }
	void print();
	void reset();

};

#endif /* WORD_H_ */
