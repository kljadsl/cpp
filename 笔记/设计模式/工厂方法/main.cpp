#include"ShapeFactory.h"

class MainForm{
private:
    ShapeFactory* sf;
public:
    MainForm(ShapeFactory* p) : sf(p){}
    void click() {
        Shape* sp = sf->getShape();//¶àÌ¬´´½¨ 
        sp->draw();
        delete sp;
    }
};

int main() {
    ShapeFactory* s1 = new TriangleFactory();
    ShapeFactory* s2 = new RectangleFactory();
    MainForm m1(s1);
    MainForm m2(s2);
    m1.click();
    m2.click();
    delete s1;
    delete s2;
}
