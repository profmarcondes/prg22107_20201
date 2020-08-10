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

typedef unsigned char byte;

// Base class Shape

class Shape {
	public:
		virtual double area() = 0;
		virtual double cost() = 0;
		virtual ~Shape(){}
};

class PaintCost{
	public:
		struct TintCost{
			TintCost(const double base,
				     const double red,
					 const double green,
				     const double blue) : base(base),
									   	  red(red),
									      green(green),
										  blue(blue) {}

			const double base;
			const double red;
			const double green;
			const double blue;
		};

		class Color {
			public:
				Color() : _red(0), _green(0), _blue(0) {}
				Color(byte r, byte g, byte b): _red(r),_green(g), _blue(b) {}
				double redFactor() { return _red/255.0; }
				double greenFactor() { return _green/255.0; }
				double blueFactor() { return _blue/255.0; }
			private:
				byte _red;
				byte _green;
				byte _blue;
		};

		PaintCost(Color c): _color(c), _pigmentCost(10.0, 4.0, 1.5, 2.0) {}
		PaintCost(Color c, TintCost p): _color(c), _pigmentCost(p) {}

		virtual double cost() {
			double totalCost = _pigmentCost.base;
			totalCost += _color.redFactor()*_pigmentCost.red;
			totalCost += _color.greenFactor()*_pigmentCost.green;
			totalCost += _color.blueFactor()*_pigmentCost.blue;
			cout << "(" << this << ") ";
			cout << "PaintCost::cost() = ";
			cout << totalCost << endl;
			return totalCost;
		}

		virtual ~PaintCost() {}

	private:
		Color _color;
		TintCost _pigmentCost;
};

class Rectangle: public Shape, public PaintCost {
   public:
	  Rectangle(double w, double h, Color c = Color(0,0,0)): PaintCost(c), _width(w), _height(h) {}
	  Rectangle(double w, double h, Color c, TintCost cost): PaintCost(c, cost), _width(w), _height(h) {}

	  double area(){
		  double value = _width*_height;
		  cout << "(" << this << ") ";
		  cout << "Rectangle::area() = ";
		  cout << value << endl;
		  return value;
	  }
	  double cost() {
		  return area() * PaintCost::cost();
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

class Circle: public Shape, public PaintCost {
  public:

   Circle(double radius, Color c = Color(0,0,0)): PaintCost(c), _radius(radius) { }
   Circle(double radius, Color c, TintCost cost): PaintCost(c, cost), _radius(radius) { }

   double area() {
		double value = _radius*_radius*PI;
		cout << "(" << this << ") ";
		cout << "Circle::area() = ";
		cout << value << endl;
		return value;
   }

   double cost() {
	   return area() * PaintCost::cost();
   }

   private:
	  double _radius;
	  static const double PI;
};
const double Circle::PI = 3.141592653589793238463;

class EquilateralTriangle: public Shape, public PaintCost {
    public:
	EquilateralTriangle(double width, Color c = Color(0,0,0)): PaintCost(c), _width(width) {}
	EquilateralTriangle(double width, Color c, TintCost cost): PaintCost(c, cost), _width(width) {}

	double area(){
		double value = _width*_width*SQRT3BY4;
		cout << "(" << this << ") ";
		cout << "EquilateralTriangle::area() = ";
		cout << value << endl;
		return value;
	}

	double cost() {
		return area() * PaintCost::cost();
	}

   private:
	   double _width;
	   static const double SQRT3BY4;
};
const double EquilateralTriangle::SQRT3BY4 = 0.433012701892219;

typedef vector<Shape*> ShapeVector;

int main(void) {

	cout << "Inheritance and Polymorphism Example" << endl;

	cout << "Creating a collection of shapes!" << endl;
	ShapeVector shapes;

	shapes.push_back(new Rectangle(10,10, PaintCost::Color(255,45,10)));
	shapes.push_back(new Rectangle(10,10, PaintCost::Color(255,45,10), PaintCost::TintCost(5.0,1.0,1.0,1.0)));
	shapes.push_back(new Circle(5, PaintCost::Color(255,0,0)));
	shapes.push_back(new Rectangle(2.4,5.3, PaintCost::Color(0,255,0)));
	shapes.push_back(new EquilateralTriangle(2, PaintCost::Color(0,0,255)));
	shapes.push_back(new Circle(4.6, PaintCost::Color(128,4,100)));
	shapes.push_back(new EquilateralTriangle(1.75, PaintCost::Color(30,198,255)));

	cout << "Now, I will calculated the total area of all the shapes created!" << endl;

	double totalArea = 0;
	for(ShapeVector::iterator it = shapes.begin(); it != shapes.end(); it++){
		totalArea += static_cast<Shape*>(*it)->area();
	}
	cout << "The total area of the shapes is: " << totalArea << endl;

	cout << "Now I will calculate the painting cost of the shapes!" << endl;

	double totalCost = 0;
	for(ShapeVector::iterator it = shapes.begin(); it != shapes.end(); it++){
		totalCost += static_cast<Shape*>(*it)->cost();
	}

	cout << "The total painting cost of the shapes is: $" << totalCost << endl;


}
