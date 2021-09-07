#include<iostream>
using namespace std;

int main(){
	int num;
	cin >> num;
	int div = 3;
	bool res;
	if(num % 2 == 0 && num > 2){
		res = false;
		return res;
	}
	while(div <= num / 2) {
		if(num % div == 0){
			res = false;
			return res;
		}
		div+=2;
	}
	res = true;
	
	return res;
} 
