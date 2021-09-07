#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;

//数组里有两个数a,b出现奇数次，其他数出现偶数次，找出出现奇数次的数 
void printOddTimesNumber2(vector<int>& v){
	int eor = 0;
	for(int i : v)
		eor ^= i;
	//eor = a ^ b 
	//因为ab不同，eor必定有一位置上是1 
	//ab在1对应的位上肯定不同 
	int rightone = eor & (~eor + 1);//提取出最右边的1
	
	int a = 0;
	for(int i : v){
		if((i & rightone) != 0){
			a ^= i;
		}
	}//将两个数分成两类，rightone上为1的一类，为0的一类 
	int b = eor ^ a;
	cout << a << ' ' << b;
} 

int bit1count(int n){
	int count = 0;
	while(n){
		int rightone = n & (~n + 1);
		count++;
		n ^= rightone;
	}
	return count;
} 

int main(){
	vector<int> vec{2,2,3,3,4,4,4,5,6,6,6,6};
	printOddTimesNumber2(vec);
	cout << endl;
	int r = bit1count(15);
	cout << r;
}
