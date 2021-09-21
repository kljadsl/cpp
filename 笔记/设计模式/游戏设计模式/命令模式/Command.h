#include"GameActor.h"
#include"Button.h"
class Command{
public:
    virtual ~Command(){}
    virtual void execute(GameActor& actor) = 0;
};

class JumpCommand : public Command{
public:
    virtual void execute(GameActor& actor) {
        actor.jump();
    }
};

class FireCommand : public Command{
public:
    virtual void execute(GameActor& actor) {
        actor.fire();
    }
};

class SwapWeaponCommand : public Command{
public:
    virtual void execute(GameActor& actor) {
        actor.swapweapon();
    }
};

class DashCommand : public Command{
public:
    virtual void execute(GameActor& actor) {
        actor.dash();
    }
};

class InputHandler{
private:
    Command* buttonX;
    Command* buttonY;
    Command* buttonA;
    Command* buttonB;
    Button* bX;
    Button* bY;
    Button* bA;
    Button* bB;
public:
    InputHandler(Command* cX, Command* cY, Command* cA, Command* cB, Button* X, Button* Y, Button* A, Button* B)
     : buttonX(cX), buttonY(cY), buttonA(cA), buttonB(cB), bX(X), bY(Y), bA(A), bB(B) {}
    Command* handleInput(){
        if (isPressed(bX)) return buttonX;
        if (isPressed(bY)) return buttonY;
        if (isPressed(bA)) return buttonA;
        if (isPressed(bB)) return buttonB;
        return NULL;
    }
};



