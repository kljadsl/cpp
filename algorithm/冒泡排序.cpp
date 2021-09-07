#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
using namespace std;
template<typename T>
void bubble_sort(vector<T>& v){
	int n = v.size();
	for(int i = 1; i < n ; ++i){
		int flag = 0;
		for(int j = 0 ; j < n-i; ++j){
			if(v[j] > v[j+1]){
				T tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}
} 


void check(){
	static default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 100);
	vector<int> v1;
	for(int i = 0; i < 1; ++i){
		for(int j = 0; j < 10000; ++j){
			v1.push_back(u(e));
		}
		vector<int> v2(v1);
		sort(v1.begin(),v1.end());
		bubble_sort(v2);
		string s = v1 == v2 ? "Right" : "False";
		cout << s << endl;
	}
	
} 

int main(){
	check();
}
