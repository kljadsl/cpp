#include<iostream>
#include<bitset>
using namespace std;

void print()
{
}//处理边界条件（参数为空） 

template<typename T,typename... Types>
void print(const T& firstArg, const Types&... args)
{
	cout << firstArg << endl; //输出第一个参数
	print(args...);//调用 print() 输出剩下参数 
}

int main(){
	print(7.5,"hello",bitset<16>(377),42);
	return 0;
}
