#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[1001];
vector<int> graph[1001];
int N, M;

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) {
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}