#include<iostream>
#include<map>
#include<string>
#include<functional>
#include<algorithm>
using namespace std;

int main(){
	multimap<int,string,less<int>> m;
	m.insert(pair<int,string>(1,"apple1")); 
	m.insert(pair<int,string>(1,"apple2")); 
	m.insert(pair<int,string>(1,"apple3")); 
	m.insert(pair<int,string>(1,"apple4")); 
	m.insert(pair<int,string>(2,"banana")); 
	m.insert(multimap<int,string>::value_type (3,"cat"));
//	int cnt = m.count(1);
//	for(int t = 0;t<cnt;++t){
//		auto iter = m.find(1);
//		m.erase(iter);
//	}
	
	auto iter = m.upper_bound(2);
	cout << "upper_bound " << iter->first << " " << iter->second << endl;
	
	for(auto i = m.begin();i != m.end(); ++i){
		cout << i->first << " " << i->second << endl; 
	}
	cout << m.count(1);
	
	return 0;
} 
