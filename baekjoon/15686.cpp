#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
//���Ʈ���� �˰���, ����, ��Ʈ��ŷ
using namespace std;

int N, M;
int arr[50][50];// N
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int min_sum = 987654321;
bool check[13]; //M


//dfs
void Find_Min_Dist() {
	int result = 0;
	for (int i = 0; i < house.size(); i++) {// �� �����κ���
		int min_dist = 987654321;
		for (int j = 0; j < chicken.size(); j++) {// ��� �� ġŲ���� ����
			if (check[j] == 0) continue;
			else {
				int x = abs(house[i].first - chicken[j].first);
				int y = abs(house[i].second - chicken[j].second);
				min_dist = min(min_dist, x + y);
			}
		}
		result += min_dist; // �ּ� ������ ġŲ�Ÿ� ����
	}
	min_sum = min(min_sum, result);
}

void select(int start, int cnt) {
	// M�� ��ŭ ġŲ���� �������
	if (cnt == M) {
		//�Ÿ� ���
		Find_Min_Dist();
		return;
	}
	else {
		//������� ���� ġŲ�� ����
		for (int i = start; i < chicken.size(); i++) {
			if (check[i] == 0) {
				check[i] = true;
				select(i + 1, cnt + 1);
				check[i] = false;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.push_back(make_pair(i, j));
			else if (arr[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}
	select(0, 0);
	cout << min_sum;
	return 0;
}