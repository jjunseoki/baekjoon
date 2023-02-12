#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<long long> v;
	int N, idx;
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		v.emplace_back(num);
	}
	sort(v.begin(), v.end());
	long long card = v[0];
	int cnt = 0, max = 0;
	for (int i = 1; i < N; i++) {
		if (v[i] == v[i - 1]) {
			cnt++;
		}
		else {
			cnt = 0;
		}
		if (cnt > max) {
			max = cnt;
			card = v[i];
		}
	}
	cout << card << '\n';
	return 0;
}