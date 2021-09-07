#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;


vector<int> count_sort(vector<int>& v,int lower_bound,int upper_bound){
	vector<int> count(upper_bound - lower_bound + 1,0);
	for(auto i : v){
		count[i-lower_bound]++;
	}
	vector<int> index(count.size(),0);
	for(int i = 1; i < index.size(); ++i){
		index[i] = count[i-1] + index[i-1]; 
	}
	vector<int> res(v.size());
	for(auto i : v){
		res[index[i-lower_bound]++] = i;
	}
	return res;
}


void check(){
	static default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 100);
	vector<int> v1;
	for(int i = 0; i < 1; ++i){
		for(int j = 0; j < 2000000; ++j){
			v1.push_back(u(e));
		}
		vector<int> v2(v1);
		sort(v1.begin(),v1.end());
		double start = GetTickCount();
		v2 = count_sort(v2,0,100);
		double end = GetTickCount();
		string s = v1 == v2 ? "Right" : "False";
		cout << s << endl;
		cout << "use time:" << end - start ; 
	}
	
} 

int main(){
	check();
//	vector<int> v{4,3,2,1,4,3,3,2,2,4};
//	vector<int> v2 = count_sort(v,1,4);
//	for(auto i : v2){
//		cout << i << ' ';
//	}	
}
