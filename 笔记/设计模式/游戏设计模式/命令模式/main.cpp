#include"Command.h"

int main() {
    GameActor player("Mario");
    Button bx, by, ba, bb;
    Button* X = &bx;
    Button* Y = &by;
    Button* A = &ba;
    Button* B = &bb;
    Command* jump = new JumpCommand();
    Command* fire = new FireCommand();
    Command* dash = new DashCommand();
    Command* swap = new SwapWeaponCommand();
    InputHandler inputHandler(jump, fire, dash, swap, X, Y, A, B);
    //Start()

    bb.press();
    Command* command = inputHandler.handleInput();
    if (command) {
        command->execute(player);
    }
    //Update()


    delete jump;
    delete fire;
    delete dash;
    delete swap;
}
