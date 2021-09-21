#include<iostream>
#include<cstring>
using namespace std;

class Prototype{
public:
    virtual Prototype* clone() = 0;
    virtual ~Prototype(){}
};

class People : public Prototype{
protected:
    char* name;
    int age;
public:
    People(const char* c, int a) {
        age = a;
        if (c == nullptr) {
            name = new char[1];
            name[0] = '\0';
        }
        else {
            name = new char[strlen(c) + 1];
            strcpy(name, c);
        }
        cout << "ctor has called." << endl; 
    }

    People(const People& rhs) {
        age = rhs.age;
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
        cout << "copy ctor has called." << endl;
    }

    People& operator= (const People& rhs) {
        if (this == &rhs) return *this;
        delete[] name;
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
        age = rhs.age;
        cout << "=ctor has called." << endl;
        return *this;
    }

    virtual People* clone() {
        cout << "clone 1 time" << endl;
        return new People(*this);
    }

    void show() {
        cout << name << ' ' << age << endl;
    }

    ~People() {
        delete[] name;
        cout << "dtor has called." << endl;
    }
};

int main() {
	People* p1 = new People("cjs", 21);
	People* p2 = p1->clone();
	p2->show();
	delete p1;
	delete p2;
}
