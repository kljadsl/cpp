#include<iostream>
using namespace std;

class CaculateStrategy{
public:
	virtual int Caculate(const int& lhs, const int& rhs) = 0;
	virtual ~CaculateStrategy(){
	}
};

class Plus : public CaculateStrategy {
public:
	virtual int Caculate(const int& lhs, const int& rhs) {
		cout << lhs + rhs << endl;
	}
};

class Minus : public CaculateStrategy {
public:
	virtual int Caculate(const int& lhs, const int& rhs) {
		cout << lhs - rhs << endl;
	}
};

class Multiply : public CaculateStrategy {
public:
	virtual int Caculate(const int& lhs, const int& rhs) {
		cout << lhs * rhs << endl;
	}
};

class Division : public CaculateStrategy {
public:
	virtual int Caculate(const int& lhs, const int& rhs) {
		cout << lhs / rhs << endl;
	}
};
