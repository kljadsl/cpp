#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int helper(const vector<int>& weight, const vector<int>& value, int index, int rest_capacity){
    if(rest_capacity < 0)
        return -1;
    if(index == weight.size())
        return 0;
    int p1 = helper(weight,value,index+1,rest_capacity);
    int p2 = -1;
    int p2next = helper(weight,value,index+1,rest_capacity-weight[index]);
    if(p2next != -1){
        p2 = value[index] + p2next;
    }
    return max(p1,p2);
}

int main(){
    vector<int> weight{1,2,5,6,7};
    vector<int> value{1,6,18,22,28};
    int bag = 11;
    int res = 0;
    res = helper(weight,value,0,bag);
    cout << res;
    getchar();
}