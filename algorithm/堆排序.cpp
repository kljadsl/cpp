#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;


void adjust(vector<int>& v,int parent,int length){
	int child = 2 * parent + 1;//ѡ�����ӽڵ� 
	while(child < length){
		if(child + 1 < length && v[child] < v[child + 1])//������ӽڵ�����Ҵ������ӽڵ㣬ѡ�����ӽڵ� 
			child++;
		if(v[child] <= v[parent])//������ڵ��Ѵ����ӽڵ������ѭ�� 
			break;
		swap(v[child],v[parent]);
		parent = child;
		child = child * 2 + 1;//�������� 
	}
}

void heap_sort(vector<int>& v){
	for(int i = v.size() / 2; i >= 0; --i)//��������Ϊ�� 
		adjust(v,i,v.size());
		
	for(int i = v.size()-1; i > 0; --i){//ÿ��ȡ����һ��Ԫ�ط�������� 
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
