#include<iostream>
#include<vector>

using namespace std;

//1.현재 위치를 청소한다.
//2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
//   a.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
//   b.왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
//   c.네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
//   d.네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.

int N, M, r, c, d;
int visited_cnt = 0;
int map[51][51]; 
int visited[51][51]; 

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0  ,-1};


void Dfs(int r, int c, int d, int visited_cnt){

	//2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
	for (int i = 0; i < 4; i++) {
		int next_d = (d + 3 - i) % 4;
		int next_r = r + dx[next_d];
		int next_c = c + dy[next_d];
		//   b.왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M || map[next_r][next_c] == 1) {
			continue;
		}
		//   a.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		if (map[next_r][next_c] == 0 || visited[next_r][next_c] == 0) {
			visited[next_r][next_c] = 1;
			r = next_r;
			c = next_c;
			d = next_d;
			visited_cnt++;
			Dfs(next_r, next_c, next_d, visited_cnt);
		}
	}
	int back_idx = d + 2 < 4 ? d + 2 : d - 2;
	int back_r = r + dx[back_idx];
	int back_c = c + dy[back_idx];
	//   c.네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		
//   d.네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//현재 자리 청소 
	visited[N][M] = 1;
	visited_cnt++;
	Dfs(r, c, d, visited_cnt);

	return 0;
}