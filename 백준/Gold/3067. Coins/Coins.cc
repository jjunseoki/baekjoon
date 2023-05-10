#include <iostream>
#include<cstring>
using namespace std;

int dp[10001];
int coin[21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int  T; 
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N; 
		//memset 함수는 메모리의 값을 원하는 크기만큼 특정 값으로 세팅할 수 있다.
		memset(dp, 0, sizeof(dp));
		memset(coin, 0, sizeof(coin));
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> coin[j];
		}
		int target;
		cin >> target;
		
		dp[0] = 1;
		for (int j = 0; j < N; j++) {
			for (int k = coin[j]; k <= target; k++) {
				dp[k] += dp[k - coin[j]];
			}
		}
		cout << dp[target] << '\n';
	}
	return 0;
}