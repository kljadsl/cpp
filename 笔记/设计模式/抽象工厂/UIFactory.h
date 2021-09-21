#include"UI.h"

class UIFactory{
public:
    virtual Button* createButton() = 0;
    virtual CheckBox* createCheckBox() = 0;
    virtual ~UIFactory(){}
};

class WinUIFactory : public UIFactory{
public:
    virtual Button* createButton() {
        return new WinButton();
    }
    virtual CheckBox* createCheckBox() {
        return new WinCheckBox();
    }
};

class MacUIFactory : public UIFactory{
public:
    virtual Button* createButton() {
        return new MacButton();
    }
    virtual CheckBox* createCheckBox() {
        return new MacCheckBox();
    }
};