#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
int arr[1001];
int DP[1001];

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void Solution() {
	int answer = 1;
	for (int i = 0; i < N; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		answer = max(answer, DP[i]);
	}
	cout << answer;
}

void Solve(){
	Input();
	Solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Solve();
	
	return 0;
}