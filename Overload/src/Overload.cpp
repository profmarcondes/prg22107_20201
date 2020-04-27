//============================================================================
// Name        : Overload.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Box {
public:
	Box(double length, double breadth, double height){
		this->length = length;
		this->breadth = breadth;
		this->height = height;
	}

	Box(): Box(1.0,1.0,1.0) { }

	double getVolume() const {
		return height * breadth * length;
	}

	Box operator+(const Box &b){
		Box result;
		result.breadth = this->breadth + b.breadth;
		result.height = this->height + b.height;
		result.length = this->length + b.length;
		return result;
	}

	bool operator<(const Box& b) const {
		return this->getVolume() < b.getVolume();
	}

	friend ostream& operator<<(ostream &output, const Box &b){
		output << "Box(" << b.length << ",";
		output << b.breadth << "," << b.height << ")";
		output << " Volume = " << b.getVolume();
		output << endl;
		return output;
	}

	friend istream& operator>>(istream &input, Box &b) {
		cout << "Input length: ";
		input >> b.length;
		cout << "Input breadth: ";
		input >> b.breadth;
		cout << "Input height: ";
		input >> b.height;

		return input;
	}

private:
	double length;
	double breadth;
	double height;
};

int main() {
	vector<Box> vBox;

	Box b1(6.0, 5.0, 12.0);
	Box b2;
	Box b3;

	cout << "cin >> b2:" << endl;

	cin >> b2;

	cout << "=================" << endl;

	vBox.push_back(b2);
	vBox.push_back(b3);
	vBox.push_back(b1);

	for(vector<Box>::iterator i = vBox.begin(); i != vBox.end() ; i++){
		cout << *i;
	}

	cout << "=================" << endl;

	cout << "Box01 volume is " << b1.getVolume() << endl;
	cout << "Box02 volume is " << b2.getVolume() << endl;
	cout << "Box03 volume is " << b3.getVolume() << endl;

	cout << "= Vector Sort ================" << endl;

	sort(vBox.begin(), vBox.end());

	for(vector<Box>::iterator i = vBox.begin(); i != vBox.end() ; i++){
		cout << *i;
	}

	cout << "=================" << endl;

	b3 = b1 + b2;

	for(vector<Box>::iterator i = vBox.begin(); i != vBox.end() ; i++){
			cout << *i;
	}

	cout << "=================" << endl;

	cout << b3;

	return 0;
}
