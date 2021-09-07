#include<iostream>
#include<string>
#include<cstring>//memset() 
#include<algorithm>//max()
#include<stack>
using namespace std;

int main(){
	string s1;
	string s2;
	getline(cin,s1);
	getline(cin,s2);
	int m = s1.size()+1;
	int n = s2.size()+1;
	int dp[m][n];
	memset(dp,0,sizeof(dp));//全部置0 
	
	for(int i = 1; i < m; ++i){
		for(int j = 1; j < n; ++j){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}//构建dp数组 
	
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}//输出dp数组 
	
	stack<char> res;//储存路径 
 	int i = s1.size();
 	int j = s2.size();
	while(dp[i][j] != 0){
		if(dp[i][j] == dp[i-1][j]){
			i--;
		}
		else if(dp[i][j] == dp[i][j-1]){
			j--;
		}
		else{
			res.push(s1[i-1]);
			i--;
			j--;
		}
	}//逆向求出路径 
	while(!res.empty()){
		char x = res.top();
		cout << x;
		res.pop();
	}//打印结果 
	
	return 0;
} 
