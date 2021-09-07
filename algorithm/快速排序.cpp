#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;

void q_sort(vector<int>& v, int left, int right){
	if(right <= left){
		return;
	}
	int i = left;
	int j = right;
	int base = v[i];
	while(i < j){
		while(v[j] >= base && i < j)
			j--;
		while(v[i] <= base && i < j)
			i++;	
		if(i < j)
			swap(v[i],v[j]);
	}
	swap(v[left],v[j]);
	q_sort(v,left,j-1);
	q_sort(v,j+1,right);
}

void quick_sort(vector<int>& v){
	int len = v.size();
	q_sort(v,0,len-1);
}


void check(){
	static default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 100);
	vector<int> v1;
	for(int i = 0; i < 1; ++i){
		for(int j = 0; j < 200000; ++j){
			v1.push_back(u(e));
		}
		vector<int> v2(v1);
		sort(v1.begin(),v1.end());
		double start = GetTickCount();
		//quick_sort(v2);
		double end = GetTickCount();
		string s = v1 == v2 ? "Right" : "False";
		cout << s << endl;
		cout << "use time:" << end - start ; 
	}
	
} 

int main(){
	//check();
	vector<int> v{4,3,2,1,4};
	quick_sort(v);
	for(auto i : v){
		cout << i << ' ';
	}	
}
