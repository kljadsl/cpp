#include<iostream>

using namespace std;
typedef long long ll;

int main(){
	int n,m,num;
	cin >> n >> m >> num;
	int map[n][m];
	int dp[n][m];
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			map[i][j] = 0;
			dp[i][j] = 0;
		}
	}
	
	for(int i = 0; i < num; ++i){
		int x,y;
		cin >> x >> y;
		map[x-1][y-1] = 1;
	}
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(map[i][j] == 0){
				if(i == 0 && j != 0){
					dp[i][j] = dp[i][j-1];
				}
				else if(i != 0 && j == 0){
					dp[i][j] = dp[i-1][j];
				}
				else if(i != 0 && j != 0){
					dp[i][j] = dp[i][j-1] + dp[i-1][j];
				}
				else{
					dp[i][j] = 1;
				}
			}
			else{
				dp[i][j] = 0;
			}
		}
	}

	cout << endl;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
} 
