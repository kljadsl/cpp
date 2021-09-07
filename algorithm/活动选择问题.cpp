#include <iostream>
#include <vector>
 
using namespace std;
 
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
 
int Adjust_Arr(int* a, int* b, int start, int end) {
 
	int p = start;
	int q = end;
	int i = p - 1;
	int j = p;
 
	int key = a[q];
 
	while (j < q) {
		if (a[j] >= key) {
			j++;
			continue;
		} else {
			i++;
			swap(a + i, a + j);
			swap(b + i, b + j);
			j++;
		}
	}
 
	i++;
	swap(a + i, a + q);
	swap(b + i, b + q);
	return i;
}
 
void Quick_Sort(int* a, int* b, int start, int end) {
	if (start < end) {
		int mid = Adjust_Arr(a, b, start, end);
		Quick_Sort(a, b, start, mid - 1);
		Quick_Sort(a, b, mid + 1, end);
	}
}
 
void Print_Arr(int* a, int len) {
	for (int i = 0; i < len; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}
 
/*
 * 递归版本
 */
void Recursive_Activity_Selector(vector<int>* A, int* s, int* f, int k, int n) {
 
	int m = k + 1;
	while (m <= n && s[m] < f[k]) {
		m++;
	}
 
	if (m <= n) {
		A->push_back(m);
		Recursive_Activity_Selector(A, s, f, m, n);
	}
}
 
/*
 * 迭代版本
 */
vector<int>* Greedy_Activity_Selector(int*s, int*f, int n) {
	vector<int>* A = new vector<int>;
 
	int k = 1;
	A->push_back(k);
 
	for (int m = 2; m <= n; m++) {
		if (s[m] >= f[k]) {
			A->push_back(m);
			k = m;
		}
	}
 
	return A;
}
 
int main() {
 
	int s[12] = { 0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
 
	int f[12] = { 0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16 };
 
	//先将f按从小到大排序，s的位置随f而动
	Quick_Sort(f, s, 0, 12 - 1);
 
//	vector<int>* A = new vector<int>;
//	Recursive_Activity_Selector(A, s, f, 0, 12 - 1); //这里实际上下标只能取到11
 
	vector<int>* A = Greedy_Activity_Selector(s, f, 12 - 1);
 
	cout << "===========" << endl;
	vector<int>::iterator iter;
 
	for (iter = A->begin(); iter != A->end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl << "===========" << endl;
 
	delete A;
 
	return 0;
}
