//============================================================================
// Name        : Heranca.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


// Base class Shape
class Shape {
   public:
		virtual double area() {
			cout << "Shape::area() called!" << endl;
			return 0;
		}
		virtual double cost() {
			cout << "Shape::cost() called!" << endl;
			return 10;
		}
};

// Derived class
class Rectangle: public Shape {
   public:
	  Rectangle(double w, double h): _width(w), _height(h) {
	      cout << "(" << this << ") Rectangle("<< _width << "," << _height << ") Constructed!" << endl;
	  }

      double area() {
         return _width * _height;
      }

      double cost() {
    	  return area() * 70;
      }

      double width() { return _width; }
      double height() { return _height; }

      ~Rectangle(){
    	  cout << "(" << this << ") Rectangle("<< _width << "," << _height << ") Destroyed!" << endl;
      }
   private:
      double _width;
      double _height;
};

int main(void) {
   Rectangle obj(5,7);

   cout << "Rectangle (" << obj.width() << "," << obj.height() << ")" << endl;

   // Print the area of the object.
   cout << "Total area: " << obj.area() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $";
   cout << obj.cost() << endl;

   Shape * ptr = &obj;

   cout << "Accessing Rectangle obj through Shape ptr." << endl;

   // Print the area of the object.
   cout << "Total area: " << ptr->area() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $";
   cout << ptr->cost() << endl;


   return 0;
}
