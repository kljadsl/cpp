#include<iostream>
#include<string>
using namespace std;

class HasPtr{//�Զ�������ü������ַ����� 
	public:
		HasPtr(const string &s = string()):ps(new string(s)),i(0),use(new size_t(1))
		{ }//���캯��������������ʼ��Ϊ1 
		
		HasPtr(const HasPtr &p):ps(p.ps),i(p.i),use(p.use){
			++*use;
		}//�������죬������++ 
		
		HasPtr& operator=(const HasPtr& rhs){
			++*rhs.use;//��ֹ�Ը�ֵ���������ټ� 
			if(--*use == 0){
				delete ps;
				delete use;
			}
			ps = rhs.ps;
			i = rhs.i;
			use = rhs.use;
			return *this;
		} //������ֵ�����ұ߼������ݼ���߼������������Ƿ�Ϊ0������Դ���� 
		
		~HasPtr(){
			if(--*use == 0){
				delete ps;
				delete use;
			}
		}//�����ݼ������������ 
		
		size_t use_count(){
			return *use;
		}
		
		string& show(){
			return *ps;
		}
	private:
		string* ps;
		int i;
		size_t* use;
};


int main(){
	HasPtr p1("hello");
	HasPtr p2(p1);
	HasPtr p3 = p1;
	cout << p3.use_count() << endl;
	cout << p2.show() << endl;
	return 0;
}
