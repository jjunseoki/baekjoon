#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T, idx;
	int sum = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<pair<int, int>> v(T);
		cin >> v[i].first >> v[i].second;
		sum = v[i].first + v[i].second;
		idx = i+1;
		cout << "Case " << idx << ": " << sum << endl;

	}
}
