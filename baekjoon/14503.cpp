#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// ����ũ��: N, ���� ũ�� M
// �κ�û�ұⰡ �ִ� ĭ�� ��ǥ (r, c)
// �ٶ󺸴� ���� d
int N, M, r, c, d;
int visited_cnt = 0;
int map[51][51]; // ����
int visited[51][51]; // û�ұ� ���, �湮������ 1

// ��, ��, ��, ��
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 1. ���� ��ġ�� û���Ѵ�.
// 2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
//a. ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
//b. ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
//c. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
//d. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.


//��� ��带 �湮�ϰ��� �ϴ� ����̱⿡ dfs�˰��� ���
void Dfs(int r, int c, int d, int visted_cnt) {
	// 2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�. - d = 0(��, ��), 1(������, ��), 2(�Ʒ�, ��), 3(����, ��)
	for (int i = 0; i < 4; i++) { 
		int next_d = (d + 3 - i) % 4;
		int next_r = r + dx[next_d];
		int next_c = c + dy[next_d];

		//b. ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
		if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M || map[next_r][next_c] == 1) {
			continue;
		}

		//a. ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
		if (visited[next_r][next_c] == 0 && map[next_r][next_c] == 0) {
			visited[next_r][next_c] = 1; //���� ��ġ û��
			r = next_r;
			c = next_c;
			d = next_d;
			visited_cnt++;
			Dfs(next_r, next_c, next_d, visited_cnt);
		}
	}
	int back_dir = (d+2) % 4; //�������� 0 -> 2, 1 ->3, 2 -> 0, 3 -> 0 
	int back_r = r + dx[back_dir];
	int back_c = c + dy[back_dir];
	//c. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
	if (0 <= back_r && back_r <= N && 0 <= back_c && back_c <= M) {
		if (map[back_r][back_c] == 0) {   //���� ���e �� �ƴϾ ������ �� ���� ��
			Dfs(back_r, back_c, d, visited_cnt);  //��ĭ ����
		}
		//d. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
		else {   //���� ���� ���̶� ���� ���� ��
			cout << visited_cnt << endl;
			exit(0);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//�Է� �κ�
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	// 1. ���� ��ġ�� û���Ѵ�.
	visited[r][c] = 1;
	visited_cnt++;
	Dfs(r, c, d, visited_cnt);

	return 0;
}