#include<iostream>
using namespace std;

class Library {
public:
	void run() {
		Step1();
		Step2();
		Step3();
		Step4();
		Step5();
	}
	
	virtual ~Library(){
	}
	
protected:
	virtual void Step1() {
		cout << "step1" << endl;
	}
	
	virtual void Step2() {
		cout << "step2" << endl;
	}
	
	virtual void Step3() = 0;
	
	virtual void Step4() {
		cout << "step4" << endl;
	}
	
	virtual void Step5() = 0;
}; 


