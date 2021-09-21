class Button{
private:
    bool isPressed;
public:
    virtual ~Button(){}

    Button() {
        isPressed = false;
    }

    void press() {
        isPressed = true;
    }

    void release() {
        isPressed = false;
    }

    bool getState() {
        return isPressed;
    }
};

bool isPressed(Button* button) {
    return button->getState();
}