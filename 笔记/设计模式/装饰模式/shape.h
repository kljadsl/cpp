#include<iostream>
#include<string>
using namespace std;

class Shape{
public:
    virtual void draw() = 0;
    virtual ~Shape(){}
};

class Rectangle : public Shape{
public:
    virtual void draw() {
        cout << "This is a rectangle." << endl;
    }
};

class Circle : public Shape{
public:
    virtual void draw() {
        cout << "This is a circle." << endl;
    }
};

class ShapeDecorator : public Shape{
protected:
    Shape* shape;
public:
    ShapeDecorator(Shape* sp) : shape(sp){}
};

class ColorShapeDecorator : public ShapeDecorator{
private: 
	string color;
public:
    ColorShapeDecorator(Shape* sp, string& s) : ShapeDecorator(sp), color(s){}

    virtual void draw() {
        shape->draw();
        cout << "It's color is " << this->color << "." << endl;
    }
};
