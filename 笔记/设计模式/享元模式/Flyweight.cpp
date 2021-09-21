#include<iostream>
#include<map>
#include<string>
using namespace std;

class Bullet{
private:
    string type;
public:
    Bullet(const string& t) : type(t){
        cout << "Create a " << type << " bullet." << endl;
    }
};

class BulletPool{
private:
    map<string,Bullet*> pool;
public:
    Bullet* getBullet(const string& s) {
        if (pool.find(s) != pool.end()) {
        	cout << s << " has found in pool." << endl; 
            return pool[s];
        }
        else {
            Bullet* bullet = new Bullet(s);
            pool[s] = bullet;
            return bullet;
        }
    }

    void clear() {
        for (auto i = pool.begin(); i != pool.end(); ++i) {
            delete (*i).second;
        }
    }
};

int main() {
    BulletPool p;
    p.getBullet("762");
    p.getBullet("556");
    p.getBullet("762");
    p.getBullet("9mm");
    p.getBullet("556");
    p.clear();
}
