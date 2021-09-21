#include"Shape.h"

class ShapeFactory{
public:
    virtual Shape* getShape() = 0;
    virtual ~ShapeFactory(){}
};

class CircleFactory : public ShapeFactory{
public:
    virtual Shape* getShape() {
        return new Circle();
    }
};

class RectangleFactory : public ShapeFactory{
public:
    virtual Shape* getShape() {
        return new Rectangle();
    }
};

class TriangleFactory : public ShapeFactory{
public:
    virtual Shape* getShape() {
        return new Triangle();
    }
};
