#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;
template<typename T>
void shell_sort(vector<T>& v){
	int n = v.size();
	int gap = 1;
	while(gap <= n/3){
		gap = gap * 3 + 1;
	}
	for(int gap; gap > 0; gap = (gap-1)/3){
		for(int i = gap; i < n ; ++i){
			T tmp = v[i];
			int j = i;
			while(j > gap-1 && v[j-gap] > tmp){
				v[j] = v[j-gap];
				j -= gap;
			}
			v[j] = tmp;
		}
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
		double start = GetTickCount();
		shell_sort(v2);
		double end = GetTickCount();
		string s = v1 == v2 ? "Right" : "False";
		cout << s << endl;
		cout << "use time:" << end - start ; 
	}
	
} 

int main(){
	check();
}
