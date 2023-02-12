#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void sol() {
	int ans = 1;
	while (!q.empty()) {
		if (q.front().first < pq.top()) {
			q.push(q.front());
			q.pop();
		}
		else {
			if (q.front().second == target) {
				cout << ans << endl;
			}
			else {
				q.pop();
				pq.pop();
				ans++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	queue<pair<int,int>> q;
	priority_queue<int> pq;
	int T, result = 0;
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int inf;
			cin >> inf;
			q.push({inf, i});
			pq.push(inf);
		}		
	}
	while (t--) {
		sol();
	}
}