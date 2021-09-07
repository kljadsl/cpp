#include<iostream>
#include<vector>
using namespace std;


void solution_down_to_up(int length,vector<int>& price){
	vector<int> res(length,0);
	for(int i = 1; i <= length; ++i){
		int tmp = 0;
		for(int j = 1; j <= i ; ++j){
			int max = price[j] + res[i-j];//¹Ø¼ü 
			if(max > tmp)
				tmp = max;
		}
		res[i] = tmp;
	}
	for(auto i : res){
		cout << i << ", ";
	}
}






int main(){
	vector<int> price = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 ,0,0,0,0,0};
	int n = 16; 
	solution_down_to_up(n,price);
	
	return 0;
} 
