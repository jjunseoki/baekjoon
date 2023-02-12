#include <iostream>

#define R 1000000000
using namespace std;

long long dp[101][10] = {0,};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][9] = dp[i - 1][j - 1];
			}
			else 
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] %= R;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result = (result + dp[N][i]) % R;
	}
	cout << result << "\n";
	return 0;
}