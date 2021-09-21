#include<iostream>
#include<list>
#include<string>
using namespace std; 

class Observer{
public:
	virtual void Update() = 0;
	virtual ~Observer(){
	}
};

class Observed{
private:
	list<Observer*> obList;
	string _state;
public:
	void addObserver(Observer* ob) {
		obList.push_back(ob);
	}
	
	void delObserver(Observer* ob) {
		for (auto it = this->obList.begin(); it != this->obList.end(); it++) {
			if ((*it) == ob) {
				this->obList.erase(it);
			}
		}
	}
	
	void Notify() {
		for (auto i : this->obList) {
			i->Update();
		}
	}
	
	void setState(string& s) {
		this->_state = s;
		Notify();
	}
	
	string getState() {
		return this->_state;
	}
};
