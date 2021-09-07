#include<iostream>
#include<vector>
#include<list>
#include<algorithm>//�����õ�copy������heap��غ���
#include<iterator>//�����õ�������ostream_iterator
#include<functional>//�����õ���һ���Ƚϵķº���greater<T>
using namespace std;
typedef vector<int> Vint;
void print(const Vint& vec)//�����ǰvector�����е�Ԫ��
{
	cout<<"�����ڵ�Ԫ��Ϊ:";
	copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));//�������ڵ�Ԫ���������׼����豸��
	cout<<endl;
	cout<<"������Ԫ�صĸ���Ϊ:"<<vec.size()<<endl<<endl;;
}
 
bool cmp(const int &a,const int &b)
{
	return a>b;//�󶥶ѣ���cmp�����greater<int>(),ע�ⲻ��greater<int>��ǰ����һ�����󣬺�����һ����
}
int main()
{
	int arr[]={3,2,1,9,4,12,15,7};
	vector<int>vec(arr,arr+sizeof(arr)/sizeof(int));//����һ��vector�������󣬽�����ĸ���ѹ�뵽��������
	cout<<"-----------��ʼ״̬---------------"<<endl;
	print(vec);//�������vector�������������
 
	cout<<"-------------����----------------"<<endl;
	make_heap(vec.begin(),vec.end(),cmp);//�½�һ��С����
	//���д���ȼ���make_heap(vec.begin(),vec.end(),greater<int>()
	print(vec);
	
	cout<<"----------�����Ѷ�Ԫ��-----------"<<endl;
	pop_heap(vec.begin(),vec.end(),cmp);//����ҲҪ��cmp����Ϊ����֮��Ҫ�������µ����Ĺ��򣬷���ϵͳ�����Ĭ�ϵ����ѵ�������
	print(vec);
	
	cout<<"----------�����Ѷ�Ԫ��-----------"<<endl;
	pop_heap(vec.begin(),vec.end()-1,cmp);//����ҲҪ��cmp����Ϊ����֮��Ҫ�������µ����Ĺ��򣬷���ϵͳ�����Ĭ�ϵ����ѵ�������
	print(vec);
	
	cout<<"----------�����Ѷ�Ԫ��-----------"<<endl;
	pop_heap(vec.begin(),vec.end()-2,cmp);//����ҲҪ��cmp����Ϊ����֮��Ҫ�������µ����Ĺ��򣬷���ϵͳ�����Ĭ�ϵ����ѵ�������
	print(vec);
	
	cout<<"----------�����Ѷ�Ԫ��-----------"<<endl;
	pop_heap(vec.begin(),vec.end()-3,cmp);//����ҲҪ��cmp����Ϊ����֮��Ҫ�������µ����Ĺ��򣬷���ϵͳ�����Ĭ�ϵ����ѵ�������
	print(vec);
	
	cout<<"----------�����Ѷ�Ԫ��-----------"<<endl;
	pop_heap(vec.begin(),vec.end()-4,cmp);//����ҲҪ��cmp����Ϊ����֮��Ҫ�������µ����Ĺ��򣬷���ϵͳ�����Ĭ�ϵ����ѵ�������
	print(vec);
	
	cout<<"----------�����Ѷ�Ԫ��-----------"<<endl;
	pop_heap(vec.begin(),vec.end()-5,cmp);//����ҲҪ��cmp����Ϊ����֮��Ҫ�������µ����Ĺ��򣬷���ϵͳ�����Ĭ�ϵ����ѵ�������
	print(vec);
 
	cout<<"--------����в���ֵ6�ķ���--------"<<endl;
	vec.push_back(6);//�Ƚ��������ֵ����������ĩβ
	push_heap(vec.begin(),vec.end(),cmp);//����ѽ������µ���
	print(vec);
 
	cout<<"----------ִ�ж�����--------------"<<endl;
	sort_heap(vec.begin(),vec.end(),cmp);
	print(vec);
	return 0;
}
