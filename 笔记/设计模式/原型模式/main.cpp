#include <iostream>
#include <cstring>
using namespace std;
 
class Resume
{
public:
	Resume(){}
 
	virtual Resume* clone() =0;
	virtual void show() {};
 
	virtual ~Resume(){}
 
protected:
	char*name;
};
 
class ResumeA : public Resume
{
public:
 
	ResumeA(){}
 
	ResumeA(const char *str)  //构造函数  
	{
		if (str == NULL)
		{
			name = new char[1];
			name[0] = '\0';
		}
		else
		{
			name = new char[strlen(str) + 1];
			strcpy(name, str);
		}
	}
 
	ResumeA(const ResumeA &rhs) //拷贝构造函数  
	{
		name = new char[strlen(rhs.name) + 1];
		strcpy(name, rhs.name);
	}
                
	ResumeA& operator=(const ResumeA& rhs)
	{
		if (this == &rhs)
			return *this;
		delete[] name;
		int len = strlen(rhs.name);
		name = new char[len + 1];
		strcpy(name, rhs.name);
		return *this;
	}
 
	virtual ResumeA* clone() override	
	{
		cout << "ResumeA name : " << name << endl;
		return new ResumeA(this->name);
	}

	virtual void show() {
		cout << name << endl;
	}
 
	~ResumeA()
	 {
		delete[] name;
	 }
};
 
int main()
{
	Resume *r = new ResumeA("a");
 
	Resume *r1 = r->clone();
	r1->show(); 
	delete r1;
	r1 = NULL;
 
}
