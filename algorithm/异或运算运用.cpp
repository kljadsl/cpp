#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;

//��������������a,b���������Σ�����������ż���Σ��ҳ����������ε��� 
void printOddTimesNumber2(vector<int>& v){
	int eor = 0;
	for(int i : v)
		eor ^= i;
	//eor = a ^ b 
	//��Ϊab��ͬ��eor�ض���һλ������1 
	//ab��1��Ӧ��λ�Ͽ϶���ͬ 
	int rightone = eor & (~eor + 1);//��ȡ�����ұߵ�1
	
	int a = 0;
	for(int i : v){
		if((i & rightone) != 0){
			a ^= i;
		}
	}//���������ֳ����࣬rightone��Ϊ1��һ�࣬Ϊ0��һ�� 
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
