#include<iostream>
using namespace std;


class Singleton {
	private:
		~Singleton(){cout << "dtor" << endl;}
		Singleton(){cout << "ctor" << endl;}
	public:
		static Singleton* getInstance(){
			static Singleton instance;
			return &instance;
		}
};


int main(){
	Singleton* instance1 = Singleton::getInstance();
	return 0;
}
