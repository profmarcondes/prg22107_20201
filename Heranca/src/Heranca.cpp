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
	  Shape(int w, int h): _width(w), _height(h) {}
      int width() {
         return _width;
      }
      int height() {
         return _height;
      }
   private:
      int _width;
      int _height;
};

// Base class PaintCost
class PaintCost {
   public:
      int getCost(int area) {
         return area * 70;
      }
};

// Derived class
class Rectangle: public Shape, public PaintCost {
   public:
	  Rectangle(int w, int h): Shape(w,h) {
	      cout << "(" << this << ") Rectangle Constructed!" << endl;
	  }
      int getArea() {
         return width() * height();
      }
      ~Rectangle(){
    	  cout << "(" << this << ") Rectangle Destroyed!" << endl;
      }
};

int main(void) {
   Rectangle Rect(5,7);
   int area;

   cout << "Rectangle (" << Rect.width() << "," << Rect.height() << ")" << endl;

   area = Rect.getArea();
   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $";
   cout << Rect.getCost(area) << endl;

   return 0;
}
