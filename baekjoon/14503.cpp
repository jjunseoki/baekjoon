#include<iostream>
#include<vector>

using namespace std;

//1.���� ��ġ�� û���Ѵ�.
//2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
//   a.���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
//   b.���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
//   c.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
//   d.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.

int N, M, r, c, d;
int visited_cnt = 0;
int map[51][51]; 
int visited[51][51]; 

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0  ,-1};


void Dfs(int r, int c, int d, int visited_cnt){

	//2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
	for (int i = 0; i < 4; i++) {
		int next_d = (d + 3 - i) % 4;
		int next_r = r + dx[next_d];
		int next_c = c + dy[next_d];
		//   b.���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
		if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M || map[next_r][next_c] == 1) {
			continue;
		}
		//   a.���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
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
	//   c.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
		
//   d.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
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
	//���� �ڸ� û�� 
	visited[N][M] = 1;
	visited_cnt++;
	Dfs(r, c, d, visited_cnt);

	return 0;
}