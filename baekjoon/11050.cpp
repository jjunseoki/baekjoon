#include <iostream>
#define R 10007

using namespace std;

long long dp[1001][10] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, K, result = 0;
	cin >> N >> K;
	if (K < 0) {
		cout << 0;
	}
	else if (K > N) {
		cout << 0;
	}
	else {
		int tmp1 = 1;
		int tmp2 = 1;
		int tmp3 = 1;
		for (int i = 1; i <= N; i++) {
			tmp1 *= i;
		}
		for (int i = 1; i <= K; i++) {
			int tmp = 1;
			tmp2 *= i;
		}
		for (int i = 1; i <= (N-K); i++) {
			int tmp = 1;
			tmp3 *= i;
		}
		cout << (tmp1 / (tmp2 * tmp3));
	}
}