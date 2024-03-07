#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
#define MAX 101
using namespace std;

int N;
int cnt = 0;
char RGB[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y){
	visited[x][y] = true;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if(!visited[nx][ny] && RGB[x][y] == RGB[nx][ny])
			dfs(nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> RGB[i];
	}

	//normal
	for(int i = 0; i< N; i++){
		for(int j = 0; j < N; j++){
			if(!visited[i][j]){
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt  << " ";

	//disable
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (RGB[i][j] == 'G') RGB[i][j] = 'R';
			else RGB[i][j] = RGB[i][j];
		}
	}

	memset(visited, false, sizeof(visited));

	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;

    return 0;
}
