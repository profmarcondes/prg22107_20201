//============================================================================
// Name        : DiceGame.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Dice {
private:
	int faceValue;

public:
	Dice() {
		srand(time(NULL));
		roll();
	}

	void roll(){
		faceValue = (rand() % 6) + 1;
	}
	int  getFaceValue(){
		return faceValue;
	}
};

class DiceGame {
private:
	Dice dice1;
	Dice dice2;

public:
	int play(){
		dice1.roll();
		int fv1 = dice1.getFaceValue();
		dice2.roll();
		int fv2 = dice2.getFaceValue();

		return fv1 + fv2;
	}
};


int main() {
	cout << "Dice Game" << endl; // prints !!!Hello World!!!

	DiceGame game;

	int result = game.play();

	if(result == 7){
		cout << "Congrats! You win (" << result << ")" << endl;
	} else {
		cout << "Sorry! You lose (" << result << ")" << endl;
	}

	cout << "Running win percentage simulation!" << endl;
	const int times = 1000000;
	int wins = 0;
	for (int i = 0; i < times; i++) {
		if(game.play() == 7)
			wins++;
	}
	cout << " Win percentage after " << times << "times is " << ((float)wins/times)*100 << "%" << endl;

	return 0;
}
