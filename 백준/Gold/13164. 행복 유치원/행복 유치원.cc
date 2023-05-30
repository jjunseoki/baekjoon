#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

vector<int> v;
vector<int> diff;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K;
	int answer = 0, temp = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N - 1; i++) {
		temp = v[i + 1] - v[i];
		diff.emplace_back(temp);
	}

	sort(diff.begin(), diff.end());

	for (int i = 0; i < N - K; i++) {
		answer += diff[i];
	}
	cout << answer;
	return 0;
}