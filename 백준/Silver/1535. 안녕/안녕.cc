#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int health[21];
int happy[21];
int dp[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> health[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> happy[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 100; j >= health[i]; j--) {
			dp[j] = max(dp[j],dp[j-health[i]] + happy[i]);
		}
	}
	cout << dp[99];
}