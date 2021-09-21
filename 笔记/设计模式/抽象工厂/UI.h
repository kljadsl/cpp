#include<iostream>
using namespace std;

class Button{
public:
    virtual void click() = 0;
    virtual ~Button(){}
};

class WinButton : public Button{
public:
    virtual void click() {
        cout << "This is a WinButton." << endl;
    }
};

class MacButton : public Button{
public:
    virtual void click() {
        cout << "This is a MacButton." << endl;
    }
};

class CheckBox{
public:
    virtual void tap() = 0;
    virtual ~CheckBox(){}
};

class WinCheckBox : public CheckBox {
public:
    virtual void tap() {
        cout << "This is a WinCheckBox." << endl;
    }
};

class MacCheckBox : public CheckBox {
public:
    virtual void tap() {
        cout << "This is a MacCheckBox." << endl;
    }
};
