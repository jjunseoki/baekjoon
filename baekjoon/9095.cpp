#include<iostream>
using namespace std;

int pluscount(int n) {
	int dp[1001];
	int cnt = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int j = 4; j <= n; j++) {
		dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
	}
	return dp[n];
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		n = pluscount(n);
		cout << n << '\n';
	}
}