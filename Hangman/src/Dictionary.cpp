/*
 * Dictionary.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: hugom
 */

#include "Dictionary.h"

Dictionary::Dictionary() {
	srand(time(NULL));
	add_word(new Word("tubarao","animal"));
	_word_list.push_back(new Word("amarelo","cor"));
	_word_list.push_back(new Word("azul","cor"));
	_word_list.push_back(new Word("vermelho","cor"));
	_word_list.push_back(new Word("tartaruga","animal"));
	_word_list.push_back(new Word("polvo","animal"));
	_word_list.push_back(new Word("pente","objeto"));
	_word_list.push_back(new Word("verde","cor"));
	_word_list.push_back(new Word("recife","cidade"));
	_word_list.push_back(new Word("florianopolis","cidade"));
	_word_list.push_back(new Word("marrom","cor"));
	_word_list.push_back(new Word("andar","verbo"));
	_word_list.push_back(new Word("dormir","verbo"));
	_word_list.push_back(new Word("correr","verbo"));
	_word_list.push_back(new Word("pular","verbo"));
}

Dictionary::~Dictionary() {
	while (!_word_list.empty()) {
	   delete _word_list.back();
	   _word_list.pop_back();
	}
}

void Dictionary::add_word(Word* p1){
	_word_list.push_back(p1);
}

Word* Dictionary::select_word(){
	int idx = rand() % _word_list.size();
	return _word_list[idx];

}
