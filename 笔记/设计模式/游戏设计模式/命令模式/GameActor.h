#include<iostream>
#include<string>
using namespace std;

class GameActor{
private:
    string name;
public:
    GameActor(const string& s) : name(s) {}
    void jump() {
        cout << name << "->jump" << endl;
    }
    void dash() {
        cout << name << "->dash" << endl;
    }
    void swapweapon() {
        cout << name << "->swap weapon" << endl;
    }
    void fire() {
        cout << name << "->fire" << endl;
    }
};