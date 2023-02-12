#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K;
	vector<int> v;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.emplace_back(num);
	}
	sort(v.begin(), v.end());

	cout << v[K-1];
}