#include<iostream>
#include<string>
using namespace std;

class HasPtr{//自定义带引用计数的字符串类 
	public:
		HasPtr(const string &s = string()):ps(new string(s)),i(0),use(new size_t(1))
		{ }//构造函数，将计数器初始化为1 
		
		HasPtr(const HasPtr &p):ps(p.ps),i(p.i),use(p.use){
			++*use;
		}//拷贝构造，计数器++ 
		
		HasPtr& operator=(const HasPtr& rhs){
			++*rhs.use;//防止自赋值出错，先增再减 
			if(--*use == 0){
				delete ps;
				delete use;
			}
			ps = rhs.ps;
			i = rhs.i;
			use = rhs.use;
			return *this;
		} //拷贝赋值递增右边计数，递减左边计数，检查计数是否为0，做资源回收 
		
		~HasPtr(){
			if(--*use == 0){
				delete ps;
				delete use;
			}
		}//析构递减计数并做检查 
		
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
