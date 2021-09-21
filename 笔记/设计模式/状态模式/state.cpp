#include<iostream>
using namespace std;

class State{
public:
    virtual void show() = 0;
    virtual ~State(){}
};

class Idle : public State{
public:
    virtual void show() {
        cout << "Playing animation idle." << endl;
    }
};

class Running : public State{
public:
    virtual void show() {
        cout << "Playing animation running." << endl;
    }
};

class Jumping : public State{
public:
    virtual void show() {
        cout << "Playing animation jumping." << endl;
    }
};

class Context{
private:
    State* state;
public:
    Context() {
        state = nullptr;
    }

    void setState(State* s) {
        state = s;
    }

    void play() {
        state->show();
    }
};


int main() {
    Context context;
    State* idle = new Idle();
    State* running = new Running();
    State* jumping = new Jumping();
    context.setState(idle);
    context.play();
    context.setState(running);
    context.play();
    context.setState(jumping);
    context.play();
    delete idle;
    delete running;
    delete jumping;
}