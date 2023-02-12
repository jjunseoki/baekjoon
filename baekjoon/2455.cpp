#include<iostream>
#include<vector>
using namespace std;

int main() {
	int f_num = 0;
	int s_num = 0;
	int t_num = 0;
	int ff_num = 0;
	int big = 0;
	vector<pair<int, int>> v(4);
	for (int i = 0; i < 4; i++) {
		cin >> v[i].first >> v[i].second;
	}
	f_num = v[0].second - v[0].first;
	s_num = f_num + v[1].second - v[1].first;
	t_num = s_num + v[2].second - v[2].first;
	ff_num = t_num + v[3].second - v[3].first;
	big = max(big, f_num);
	big = max(big, s_num);
	big = max(big, t_num);
	big = max(big, ff_num);
	cout << big;
}