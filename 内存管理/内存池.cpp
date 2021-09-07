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
  // �ڴ����
 cout << sizeof(A) << endl;
 cout << sizeof(buf) << endl;
 cout << (void*)buf << endl; 
 for (size_t i = 0; i < size; i++)
 {
  new ((void*)buf + sizeof(A) * i) A(i); // ������
 }
 A* arr = (A*)buf;
 for (size_t i = 0; i < size; i++)
 {
  arr[i].print();
  arr[i].~A(); // ��������
 }
 // ջ��Ԥ������ڴ��Զ��ͷ�
 return 0;
}
