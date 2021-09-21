#include"observed.h"

class Observer1 : public Observer{
private:
	Observed* _observed;
public:
	Observer1(Observed*& ob) : _observed(ob){
	}
	
	virtual void Update() {
		cout << _observed->getState() << endl;
	}
};




int main() {
	Observed observed;
	Observed* target = &observed;//创建被观察者 
	
	Observer* ob1 = new Observer1(target);
	Observer* ob2 = new Observer1(target);//创建观察者 
	
	observed.addObserver(ob1);
	observed.addObserver(ob2);//注册观察者（订阅） 
	
	string s1 = "hello";
	string s2 = "goodbye";
	
	observed.setState(s1);//发布 
	observed.delObserver(ob1);
	observed.setState(s2);//发布 
	observed.delObserver(ob2);
	
	delete ob1;
	delete ob2;
}
