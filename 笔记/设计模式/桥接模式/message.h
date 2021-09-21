#include<iostream>
#include<string>
using namespace std;

class MessagerImp{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;

    virtual ~MessagerImp(){}
};

class Messager{
protected:
    MessagerImp* messagerImp;
public:
    Messager(MessagerImp* p) : messagerImp(p){}

    virtual void Login(string username) = 0;
    virtual void SendMsg(string msg) = 0;

    virtual ~Messager(){}
};

class PCMessagerImp : public MessagerImp{
public:
    virtual void PlaySound() {
        cout << "Play sound on PC." << endl;
    }

    virtual void DrawShape() {
        cout << "Draw Shape on PC." << endl;
    }

    virtual void WriteText() {
        cout << "Write Text on PC." << endl;
    }
};

class MobileMessagerImp : public MessagerImp{
public:
    virtual void PlaySound() {
        cout << "Play sound on Mobile." << endl;
    }

    virtual void DrawShape() {
        cout << "Draw Shape on Mobile." << endl;
    }

    virtual void WriteText() {
        cout << "Write Text on Mobile." << endl;
    }
};

class MessagerLite : public Messager{
public:
    MessagerLite(MessagerImp* p) : Messager(p){}

    virtual void Login(string username) {
        messagerImp->PlaySound();
        cout << "Hello " << username << ". This is lite login." << endl;
    }
    virtual void SendMsg(string msg) {
        messagerImp->WriteText();
        cout << "Lite send :" << msg << endl;
    }
};

class MessagerPerfect : public Messager{
public:
    MessagerPerfect(MessagerImp* p) : Messager(p){}

    virtual void Login(string username) {
        messagerImp->PlaySound();
        cout << "Hello " << username << ". This is perfect login." << endl;
    }
    virtual void SendMsg(string msg) {
        messagerImp->WriteText();
        messagerImp->DrawShape();
        cout << "Perfect send :" << msg << endl;
    }
};
