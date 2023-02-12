#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// 세로크기: N, 가로 크기 M
// 로봇청소기가 있는 칸의 좌표 (r, c)
// 바라보는 방향 d
int N, M, r, c, d;
int visited_cnt = 0;
int map[51][51]; // 지도
int visited[51][51]; // 청소기 경로, 방문했으면 1

// 북, 동, 남, 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 1. 현재 위치를 청소한다.
// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
//a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
//b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
//c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
//d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.


//모든 노드를 방문하고자 하는 경우이기에 dfs알고리즘 사용
void Dfs(int r, int c, int d, int visted_cnt) {
	// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다. - d = 0(위, 북), 1(오른쪽, 동), 2(아래, 남), 3(왼쪽, 서)
	for (int i = 0; i < 4; i++) { 
		int next_d = (d + 3 - i) % 4;
		int next_r = r + dx[next_d];
		int next_c = c + dy[next_d];

		//b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M || map[next_r][next_c] == 1) {
			continue;
		}

		//a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		if (visited[next_r][next_c] == 0 && map[next_r][next_c] == 0) {
			visited[next_r][next_c] = 1; //현재 위치 청소
			r = next_r;
			c = next_c;
			d = next_d;
			visited_cnt++;
			Dfs(next_r, next_c, next_d, visited_cnt);
		}
	}
	int back_dir = (d+2) % 4; //후진방향 0 -> 2, 1 ->3, 2 -> 0, 3 -> 0 
	int back_r = r + dx[back_dir];
	int back_c = c + dy[back_dir];
	//c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
	if (0 <= back_r && back_r <= N && 0 <= back_c && back_c <= M) {
		if (map[back_r][back_c] == 0) {   //뒤쪽 방햑 벽 아니어서 후진할 수 있을 때
			Dfs(back_r, back_c, d, visited_cnt);  //한칸 후진
		}
		//d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
		else {   //뒤쪽 방향 벽이라 후진 못할 때
			cout << visited_cnt << endl;
			exit(0);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//입력 부분
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	// 1. 현재 위치를 청소한다.
	visited[r][c] = 1;
	visited_cnt++;
	Dfs(r, c, d, visited_cnt);

	return 0;
}