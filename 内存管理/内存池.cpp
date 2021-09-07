#pragma pack(4)

#include<iostream>
using namespace std;

class A
{
private:
 int data;
public:
 A(int indata) 
  : data(indata) { }
 void print()
 {
  cout << data << endl;
 }
 virtual void func(){
 }
};


int main()
{
 const int size = 10;
 char buf[size * sizeof(A)];
  // 内存分配
 cout << sizeof(A) << endl;
 cout << sizeof(buf) << endl;
 cout << (void*)buf << endl; 
 for (size_t i = 0; i < size; i++)
 {
  new ((void*)buf + sizeof(A) * i) A(i); // 对象构造
 }
 A* arr = (A*)buf;
 for (size_t i = 0; i < size; i++)
 {
  arr[i].print();
  arr[i].~A(); // 对象析构
 }
 // 栈上预分配的内存自动释放
 return 0;
}
