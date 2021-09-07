#include<iostream>
using namespace std;

long quickpow(int x, int n, int mod) {
	long long res = 1;
	long long t = x;
	while (n > 0) {
		if ((n & 1) == 1) {//按位与，求奇偶
			res *= t;
			res %= mod;
		}
		t *= t;
		t %= mod;
		n /= 2;
	}
	return res;
}

int main() {
	long res = 0;
	res = quickpow(3, 40, 1000000007);
	cout << res;
	return 0;
}
