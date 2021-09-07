#include<iostream>
#include<map>
#include<string>
#include<functional>
using namespace std;

int main(){
	map<int,string,greater<int>> m;
	m.insert(pair<int,string>(1,"apple"));//���ظ�����Ч 
	m[2] = "banana";//�ظ��ɸ��� 
	m.insert(map<int,string>::value_type (3,"cat"));//���ظ�����Ч 
	m[4] = "banana";
	auto iter = m.find(2);
	m.erase(iter);
	
	for(auto i = m.begin();i != m.end(); ++i){
		cout << i->first << " " << i->second << endl; 
	}
	cout << m.count(1);
	
	return 0;
} 
