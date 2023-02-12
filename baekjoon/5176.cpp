#include<iostream>
#include<vector>
using namespace std;

int main() {
	int K;
	cin >> K;
	vector<pair<int, int>> v(K);
	for (int i = 0; i < K; i++) {
		cin >> v[i].first >> v[i].second;
		bool arr[501] = {};
		int cnt = 0;
		for (int j = 0; j < v[i].first; j++) {
			int num;
			cin >> num;

			if (arr[num]) cnt++;
			else arr[num] = 1;
		}
		cout << cnt << endl;
	}
}