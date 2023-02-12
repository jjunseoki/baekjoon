#include <iostream>

using namespace std;

long long dp[101] = {0,1,1,1,2,2};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		for (int i = 6; i <= 100; i++) {
			dp[i] = dp[i - 3] + dp[i - 2];
		}
		cout << dp[N] << '\n';
	}
}