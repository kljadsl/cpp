#include<iostream>

 
using namespace std;
 
 
void solution(int i,int N,bool left){
	if(i > N){
		return;
	}
	solution(i+1,N,true);
	if(left){
		cout << "down" << ' ';
	}
	else{
		cout << "up" << ' ';
	}
	solution(i+1,N,false);
} 

void func(int N){
	solution(1,N,true);
} 

int main(){
	int a = 4;
	func(a);
}
