#include<iostream>

#define MAX 301
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int dp[MAX];
	int stair[MAX];
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stair[i];
	}
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[2] + stair[1] , stair[2]+ stair[0]);
	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i -3] + stair[i-1] + stair[i], dp[i - 2] + stair[i]);
	}
	cout << dp[N - 1] << '\n';
	return 0;
}