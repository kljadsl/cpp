#include<iostream>
using namespace std;

class Singleton{
private:
    int v;
    Singleton(int a) : v(a){} // ctor hidden
	Singleton(Singleton const&); // copy ctor hidden
	Singleton& operator=(Singleton const&); // assign op. hidden
	~Singleton(){} // dtor hidden
public:
    static Singleton& getInstance() {
        static Singleton instance(1);
        return instance;
    }

    void show() {
        cout << v << endl;
    }

    void increase() {
        v++;
    }
    
};

int main() {
    Singleton::getInstance().show();
    Singleton::getInstance().increase();
    Singleton::getInstance().show();
}
