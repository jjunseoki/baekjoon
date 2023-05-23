#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[100001];
bool visited[100001] = {0,};  //
int result[100001] = {0, };
int cnt = 0;

void bfs(int R) {
	queue<int> q;
	q.push(R); // 시작
	visited[R] = true; //방문처리
	cnt++; // 방문 -> +1
	result[R] = cnt;

	//큐가 빌 때까지 반복	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]){
				cnt++;
				q.push(y);
				visited[y] = true;
				result[y] = cnt;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].emplace_back(num2);
		graph[num2].emplace_back(num1);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	bfs(R);

	for (int i = 1; i <= N; i++) {
		cout << result[i] << '\n';
	}
	return 0;
}