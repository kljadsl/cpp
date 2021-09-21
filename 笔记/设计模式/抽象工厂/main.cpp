#include"UIFactory.h"

class Application{
private:
    UIFactory* f;
public:
    Application(UIFactory* p) : f(p){}
    void getUI() {
        Button* button = f->createButton();
        CheckBox* checkbox = f->createCheckBox();
        button->click();
        checkbox->tap();
        delete button;
        delete checkbox;
    }
};

int main() {
    UIFactory* f1 = new WinUIFactory();
    UIFactory* f2 = new MacUIFactory();

    Application a1(f1);
    Application a2(f2);

    a1.getUI();
    a2.getUI();

    delete f1;
    delete f2;
}