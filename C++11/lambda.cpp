#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

int main(){
//	int id = 0;
//	auto f = [&id]() mutable{
//		cout << "id:" << id << endl;
//		++id;
//	};
//	
//	id = 42;
//	f();
//	f();
//	f();
//	cout << "id:" << id << endl;
	
	vector<int> v{1,2,3,4,5,6,7,8,9,10};
	int x = 1;
	int y = 10;
	v.erase(remove_if(v.begin(),v.end(),[x,y](int n){return x<n&&n<y;}),v.end());
	for(auto i:v)
		cout << i << ' ';
	
	return 0;
}
