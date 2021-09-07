#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;


void adjust(vector<int>& v,int parent,int length){
	int child = 2 * parent + 1;//选择左子节点 
	while(child < length){
		if(child + 1 < length && v[child] < v[child + 1])//如果右子节点存在且大于左子节点，选择右子节点 
			child++;
		if(v[child] <= v[parent])//如果父节点已大于子节点则结束循环 
			break;
		swap(v[child],v[parent]);
		parent = child;
		child = child * 2 + 1;//继续深入 
	}
}

void heap_sort(vector<int>& v){
	for(int i = v.size() / 2; i >= 0; --i)//调整数组为堆 
		adjust(v,i,v.size());
		
	for(int i = v.size()-1; i > 0; --i){//每次取出第一个元素放入数组后部 
		swap(v[i],v[0]);
		adjust(v,0,i);
	}
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
		heap_sort(v2);
		double end = GetTickCount();
		string s = v1 == v2 ? "Right" : "False";
		cout << s << endl;
		cout << "use time:" << end - start ; 
	}
	
} 

int main(){
	check();
//	vector<int> v{4,3,2,1,4,3,3,2,2,4};
//	heap_sort(v);
//	for(auto i : v){
//		cout << i << ' ';
//	}	
}
