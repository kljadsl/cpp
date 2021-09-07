#include<iostream>
#include<vector>
#include<list>
#include<algorithm>//后面用到copy函数和heap相关函数
#include<iterator>//后面用到迭代器ostream_iterator
#include<functional>//后面用到了一个比较的仿函数greater<T>
using namespace std;
typedef vector<int> Vint;
void print(const Vint& vec)//输出当前vector容器中的元素
{
	cout<<"容器内的元素为:";
	copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));//将容器内的元素输出到标准输出设备上
	cout<<endl;
	cout<<"容器内元素的个数为:"<<vec.size()<<endl<<endl;;
}
 
bool cmp(const int &a,const int &b)
{
	return a>b;//大顶堆，则cmp相等于greater<int>(),注意不是greater<int>，前者是一个对象，后者是一个类
}
int main()
{
	int arr[]={3,2,1,9,4,12,15,7};
	vector<int>vec(arr,arr+sizeof(arr)/sizeof(int));//创建一个vector容器对象，将数组的副本压入到该容器中
	cout<<"-----------初始状态---------------"<<endl;
	print(vec);//将最初的vector容器的内容输出
 
	cout<<"-------------建堆----------------"<<endl;
	make_heap(vec.begin(),vec.end(),cmp);//新建一个小顶堆
	//上行代码等价于make_heap(vec.begin(),vec.end(),greater<int>()
	print(vec);
	
	cout<<"----------弹出堆顶元素-----------"<<endl;
	pop_heap(vec.begin(),vec.end(),cmp);//这里也要加cmp，因为弹出之后要给出向下调整的规则，否则系统会调用默认的最大堆调整方法
	print(vec);
	
	cout<<"----------弹出堆顶元素-----------"<<endl;
	pop_heap(vec.begin(),vec.end()-1,cmp);//这里也要加cmp，因为弹出之后要给出向下调整的规则，否则系统会调用默认的最大堆调整方法
	print(vec);
	
	cout<<"----------弹出堆顶元素-----------"<<endl;
	pop_heap(vec.begin(),vec.end()-2,cmp);//这里也要加cmp，因为弹出之后要给出向下调整的规则，否则系统会调用默认的最大堆调整方法
	print(vec);
	
	cout<<"----------弹出堆顶元素-----------"<<endl;
	pop_heap(vec.begin(),vec.end()-3,cmp);//这里也要加cmp，因为弹出之后要给出向下调整的规则，否则系统会调用默认的最大堆调整方法
	print(vec);
	
	cout<<"----------弹出堆顶元素-----------"<<endl;
	pop_heap(vec.begin(),vec.end()-4,cmp);//这里也要加cmp，因为弹出之后要给出向下调整的规则，否则系统会调用默认的最大堆调整方法
	print(vec);
	
	cout<<"----------弹出堆顶元素-----------"<<endl;
	pop_heap(vec.begin(),vec.end()-5,cmp);//这里也要加cmp，因为弹出之后要给出向下调整的规则，否则系统会调用默认的最大堆调整方法
	print(vec);
 
	cout<<"--------向堆中插入值6的方法--------"<<endl;
	vec.push_back(6);//先将待插入的值放在容器的末尾
	push_heap(vec.begin(),vec.end(),cmp);//再最堆进行向下调整
	print(vec);
 
	cout<<"----------执行堆排序--------------"<<endl;
	sort_heap(vec.begin(),vec.end(),cmp);
	print(vec);
	return 0;
}
