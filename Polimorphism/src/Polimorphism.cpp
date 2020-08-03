//============================================================================
// Name        : Polimorphism.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
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
			cout << "Shape::area() called!" << endl;
			return 0;
		}
		virtual ~Shape(){}
};

class Rectangle: public Shape {
   public:
	  Rectangle(double w, double h): _width(w), _height(h) {}

	  double area(){
		  double value = _width*_height;
		  cout << "(" << this << ") ";
		  cout << "Rectangle::area() = ";
		  cout << value << endl;
		  return value;
	  }
	  double cost() {
		  return area() * 70;
	  }
	  double width() {
		  return _width;
	  }
	  double height() {
		  return _height;
	  }

   private:
      double _width;
      double _height;
};

class Circle: public Shape {
  public:

   Circle(double radius): _radius(radius) { }

   double area() {
		double value = _radius*_radius*PI;
		cout << "(" << this << ") ";
		cout << "Circle::area() = ";
		cout << value << endl;
		return value;
   }

   double cost() {
	   return area() * 60;
   }

   private:
	  double _radius;
	  static const double PI;
};
const double Circle::PI = 3.141592653589793238463;

class EquilateralTriangle: public Shape {
    public:
	EquilateralTriangle(double width): _width(width) {}

	double area(){
		double value = _width*_width*SQRT3BY4;
		cout << "(" << this << ") ";
		cout << "EquilateralTriangle::area() = ";
		cout << value << endl;
		return value;
	}

	double cost() {
		return area() * 40;
	}

   private:
	   double _width;
	   static const double SQRT3BY4;
};
const double EquilateralTriangle::SQRT3BY4 = 0.433012701892219;

int main(void) {

	cout << "Inheritance and Polymorphism Example" << endl;

	cout << "Creating a collection of shapes!" << endl;
	vector<Shape*> shapes;

	shapes.push_back(new Rectangle(5.0,7.0));
	shapes.push_back(new Rectangle(10.0,25.0));
	shapes.push_back(new Circle(0.25));
	shapes.push_back(new EquilateralTriangle(5));
	shapes.push_back(new Circle(34.25));

	double totalArea = 0;
	for(vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++){
			totalArea += static_cast<Shape*>(*it)->area();
	}

	cout << "The total area of the shapes is: " << totalArea << endl;

   return 0;
}
