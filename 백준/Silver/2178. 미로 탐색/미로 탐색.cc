#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#define MAX 101

using namespace std;

int arr[101][101];
int cnt = 0;
int  visited[101][101];
int dist[MAX][MAX];

int x_dir[4] = { 1, -1, 0, 0 }; 
int y_dir[4] = { 0, 0, -1, 1 };

queue<pair<int, int> > q;

int bfs(int startx, int starty, int N, int M) {
	visited[startx][starty] = 1;
	q.push(make_pair(startx, starty));
	dist[startx][starty] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + x_dir[i];
			int ny = y + y_dir[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M && arr[nx][ny] == 1 && !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	return dist[N - 1][M - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	cnt = bfs(0,0 ,N, M);
	cout << cnt;
	return 0;
}