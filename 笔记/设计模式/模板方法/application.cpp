#include"library.h"

class Application : public Library {
protected:
	virtual void Step3() {
		cout << "my step3" << endl;
	}
	
	virtual void Step5() {
		cout << "my step5" << endl;
	}
};

int main() {
	Library* myLib = new Application();
	myLib->run();
	delete myLib;
}
