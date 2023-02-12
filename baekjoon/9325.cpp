#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int T;
	int sum = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int s, n;
		cin >> s >> n;
		vector<pair<int, int>> v(n);
		sum = s;
		for (int j = 0; j < n; j++) {
			cin >> v[j].first >> v[j].second;
			sum +=v[j].first * v[j].second;
		}
		cout << sum << endl;
	}
}