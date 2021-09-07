#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k,vector<vector<int>>& size) {
	//matΪԭ����kΪ�뾶�����صľ�����matÿ��Ԫ��k�����ڵĺ� 
        int n = mat.size(); 
        int m = mat[0].size();//��ȡ���д�С 
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));//����һ��0����������� 
        vector<vector<int>> res(n,vector<int>(m,0));//������� 
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]; 
            }
        }//����ǰ׺��dp���� 
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                int row1 = max(i-k-1,0);
                int col1 = max(j-k-1,0);
                int row2 = min(i+k,n);
                int col2 = min(j+k,m);//�������� 
                res[i-1][j-1] = dp[row2][col2] - dp[row2][col1] - dp[row1][col2] + dp[row1][col1];
                size[i-1][j-1] = (row2-row1) * (col2-col1);
            }
        }
        return res;
    }
    
};

int main(){
	vector<vector<int>> mat{{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> res;
	vector<vector<int>> size{{0,0,0},{0,0,0},{0,0,0}};//���ÿ��Ԫ��������ʵ��Ԫ������ 
	int k = 2;
	Solution s;
	res = s.matrixBlockSum(mat,k,size);
	for(auto i = res.begin(); i != res.end(); ++i){
		for(auto j = (*i).begin(); j != (*i).end(); ++j){
			cout << *j << ' ';
		}
		cout << endl;
	} 
	for(auto i = size.begin(); i != size.end(); ++i){
		for(auto j = (*i).begin(); j != (*i).end(); ++j){
			cout << *j << ' ';
		}
		cout << endl;
	} 
} 
