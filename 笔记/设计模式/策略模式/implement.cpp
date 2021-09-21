#include"strategy.h"

class MyCaculator {
private:
	CaculateStrategy* strategy;
	
public:
	MyCaculator(CaculateStrategy*& s) {
		strategy = s;
	}
	
	~MyCaculator() {
		delete strategy;
	}
	
	int caculate(const int& lhs, const int& rhs) {
		return strategy->Caculate(lhs, rhs);
	}
};

int main() {
	CaculateStrategy* myStrategy = new Division();
	MyCaculator mc(myStrategy);
	mc.caculate(12, 4);
}
