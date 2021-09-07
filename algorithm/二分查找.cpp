#include<iostream>
#include<vector>
#include<random>
#include<algorithm> 
#include<string>
#include<windows.h>
using namespace std;


bool binary_search(vector<int>& v,int target){
	if(v.size() == 0){
		return false;
	}
	sort(v.begin(),v.end());
	int left = 0;
	int right = v.size()-1;
	int mid = 0;
	while(left < right){
		mid = left + ((right - left) >> 1);
		if(v[mid] == target)
			return true;
		else if(v[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return v[left] == target;
}

//寻找大于等于value的最左位置 
int nearestLeft(vector<int>& v,int value){
	if(v.size() == 0){
		return -1;
	}
	int left = 0;
	int right = v.size() - 1;
	int index = -1;
	while(left <= right){
		int mid = left + ((right - left) >> 1);
		if(v[mid] >= value){
			index = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return index;
} 

//无序数组中寻找一个极小值位置（无重复元素） 
int getminimalIndex(vector<int>& v){
	if(v.size() == 0)
		return -1;
	if(v.size() == 1 || v[0] < v[1])
		return 0;
	if(v[v.size-2] > v[v.size()-1])
		return v.size()-1;
	int left = 1;
	int right = v.size() - 2;
	while(left < right){
		int mid = left + ((right - left) >> 1);
		if(v[mid] < v[mid-1] && v[mid] < v[mid+1]){
			return mid;
		}
		else if(v[mid] > v[mid-1]){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return left;
}

int main(){
	vector<int> vec{2,5,56,67,3,34,52,3};
	bool res = binary_search(vec,34);
	cout << res;
}
