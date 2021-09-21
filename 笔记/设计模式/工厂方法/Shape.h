#include<iostream>
using namespace std;

class Shape{
public:
    virtual void draw() = 0;
    virtual ~Shape(){}
};

class Circle : public Shape{
public:
    virtual void draw() {
        cout << "This is a circle." << endl;
    }
};

class Rectangle : public Shape{
public:
    virtual void draw() {
        cout << "This is a rectangle." << endl;
    }
};

class Triangle : public Shape{
public:
    virtual void draw() {
        cout << "This is a triangle." << endl;
    }
};
