#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;

void merge(vector<int>& v,vector<int>& tmp){
	int right = v.size()-1;
	int len = 2;
	while(len <= v.size()*2){
		for(int left = 0; left <= right; left += len){
			int lptr = left;
			int j = left;
			int rbound = min(lptr+len-1,right);
			int rptr = min(lptr+len/2,rbound);
			int mid = min(lptr+len/2-1,rbound);
			int i = lptr;
			while(lptr <= mid && rptr <= rbound){
				if(v[lptr] <= v[rptr]){
					tmp[i++] = v[lptr++];
				}else{
					tmp[i++] = v[rptr++];
				}
			}
			while(lptr <= mid) tmp[i++] = v[lptr++];
			while(rptr <= rbound) tmp[i++] = v[rptr++];
			for(j; j <= rbound; j++){
				v[j] = tmp[j];
			}
		}
		len *= 2;
	} 
}


void merge_sort(vector<int>& v){
	int len = v.size();
	vector<int> tmp(len,0);
	merge(v,tmp);
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
		merge_sort(v2);
		double end = GetTickCount();
		string s = v1 == v2 ? "Right" : "False";
		cout << s << endl;
		cout << "use time:" << end - start ; 
	}
	
} 

int main(){
	check();
//	vector<int> v{4,3,2,1,4};
//	merge_sort(v);
//	for(auto i : v){
//		cout << i << ' ';
//	}	
}
