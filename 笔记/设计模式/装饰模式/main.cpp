#include"shape.h"

int main(){
	Shape* s1 = new Circle();
	Shape* s2 = new Rectangle();
	
	s1->draw();
	s2->draw();
	
	string c1 = "red";
	string c2 = "blue";
	ShapeDecorator* sd1 = new ColorShapeDecorator(s1, c1);
	ShapeDecorator* sd2 = new ColorShapeDecorator(s2, c2);
	
	sd1->draw();
	sd2->draw();
	
	delete s1;
	delete s2;
	delete sd1;
	delete sd2;
	return 0;
}
