#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<pair<int, int>> v(N);
		cin >> v[i].first >> v[i].second;
		sum += (v[i].second % v[i].first);
	}
	cout << sum;
}