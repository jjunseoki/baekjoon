#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int value[10];

int main() {
	int N, start, end;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		//v.push_back(make_pair(end, begin));
	}
	sort(v.begin(), v.end());
	int cnt = 1;
	int time = v[0].first;
	for (int i = 1; i < N; i++) {
		if (v[i].second >= time) {
			cnt++;
			time = v[i].first;
		}
	}
	cout << cnt;
}