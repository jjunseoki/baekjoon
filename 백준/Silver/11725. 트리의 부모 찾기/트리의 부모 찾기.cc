#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#define MAX 100001
using namespace std;

int N;
int ans[MAX];
bool visited[MAX];
vector<int> graph[MAX];

void bfs() {
	queue<int> q;
	visited[1] = true;
	q.push(1);

	while (!q.empty()) {
		int parent = q.front();
		q.pop();

		for (int i = 0; i < graph[parent].size(); i++) {
			int child = graph[parent][i];
			if (!visited[child]) {
				ans[child] = parent;
				visited[child] = true;
				q.push(child);
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bfs();

	for (int i = 2; i <= N; i++)
		cout << ans[i] << "\n";

	return 0;
}