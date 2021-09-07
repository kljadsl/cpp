#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;

void merges(vector<int>& v,vector<int>& tmp,int left,int right){
	if(left >= right){
		return;
	}
	int mid = left + (right - left) / 2;
	int rightptr = mid + 1;
	int leftptr = left;
	merges(v,tmp,left,mid);
	merges(v,tmp,mid+1,right);
	
	int i = leftptr;
	while(leftptr <= mid && rightptr <= right){
		if(v[leftptr] <= v[rightptr]){
			tmp[i++] = v[leftptr++];
		}else{
			tmp[i++] = v[rightptr++];
		}
	}
	
	while(leftptr <= mid){
		tmp[i++] = v[leftptr++];
	}
	while(rightptr <= right){
		tmp[i++] = v[rightptr++];
	}
	for(int x = left; x <= right; ++x){
		v[x] = tmp[x];
	} 
}


void merge_sort(vector<int>& v){
	int len = v.size();
	vector<int> tmp(len,0);
	merges(v,tmp,0,len - 1);
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
}
