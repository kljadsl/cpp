#include<iostream>
#include<bitset>
using namespace std;

void print()
{
}//�����߽�����������Ϊ�գ� 

template<typename T,typename... Types>
void print(const T& firstArg, const Types&... args)
{
	cout << firstArg << endl; //�����һ������
	print(args...);//���� print() ���ʣ�²��� 
}

int main(){
	print(7.5,"hello",bitset<16>(377),42);
	return 0;
}