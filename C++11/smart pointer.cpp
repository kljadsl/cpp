#include<iostream>
#include<memory>//ÖÇÄÜÖ¸Õë
#include<utility>//std::move 

using namespace std;

class Entity{
	public:
		Entity(){
			cout << "Entity created!" << endl;
		}
		~Entity(){
			cout << "Entity destoryed!" << endl;
		}
}; 

// *************unique_ptr******************
void ex1(){
	cout << "----------------" << endl;
	cout << "Entering ex1" << endl;
	{
		cout << "Entering ex1::scope1" << endl;
		auto e1 = make_unique<Entity>();
		cout << "Leaving ex1::scope1" << endl;
	}
	cout << "Leaving ex1" << endl;
}

void foo(unique_ptr<Entity>){
	cout << "Entering foo" << endl;
	cout << "Leaving foo" << endl;
}

void ex2(){
	cout << "----------" << endl;
	cout << "Entering ex2" << endl;
	auto e1 = make_unique<Entity>();
	foo(std::move(e1));
	cout << "Leaving ex2" << endl;
}

//***************shared_ptr******************

void ex3(){
	cout << "----------------" << endl;
	cout << "Entering ex3" << endl;
	auto e1 = make_shared<Entity>();
	cout << e1.use_count() << endl;
	{
		cout << "Entering ex3::scope1" << endl;
		auto e2 = e1;//use_count++
		cout << e1.use_count() << endl;
		auto e3 = std::move(e2);//use_count remains
		cout << e1.use_count() << endl;
		cout << "Leaving ex3::scope1" << endl;
	}
	cout << e1.use_count() << endl;
	cout << "Leaving ex1" << endl;
}
	
int main(){
	ex1();
	ex2();
	ex3();
	return 0;
}


