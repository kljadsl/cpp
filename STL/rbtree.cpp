#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
	_Rb_tree<int,int,_Identity<int>,less<int>> tree;
	cout << tree.empty() << endl;//1
	cout << tree.size() << endl;//0
	
	tree._M_insert_unique(3);
	tree._M_insert_unique(4);
	tree._M_insert_unique(6);
	tree._M_insert_unique(8);
	tree._M_insert_unique(24);
	tree._M_insert_unique(12);
	cout << tree.empty() << endl;//0
	cout << tree.size() << endl;//6
	cout << tree.count(6) << endl;//1
	
	tree._M_insert_equal(6);
	tree._M_insert_equal(6);
	cout << tree.size() << endl;//8
	cout << tree.count(6) << endl;//3
	
	return 0;
} 
