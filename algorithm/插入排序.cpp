#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
using namespace std;
template<typename T>
void insert_sort(vector<T>& v){
	int n = v.size();
	for(int i = 1; i < n ; ++i){
		T tmp = v[i];
		int j = i;
		while(j > 0 && v[j-1] > tmp){
			v[j] = v[j-1];
			j--;
		}
		v[j] = tmp;
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
		insert_sort(v2);
		string s = v1 == v2 ? "Right" : "False";
		cout << s << endl;
	}
	
} 

int main(){
	check();
}
