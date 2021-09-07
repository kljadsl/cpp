#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;

void the_Netherlands_flag_issue(vector<int>& v,int value){
	int less = -1;
	int greater = v.size();
	int index = 0;
	while(index < greater){
		if(v[index] < value){
			swap(v[index++],v[++less]);
		}
		else if(v[index] > value){
			swap(v[index],v[--greater]);
		}
		else{
			index++;
		}
	}
}

int main(){
	vector<int> vec{3,4,6,7,34,3,6,7,8,9,3,2,6,87,5,4,4,0,1};
	the_Netherlands_flag_issue(vec,4);
	for(auto i : vec){
		cout << i << ' ';
	}
}
