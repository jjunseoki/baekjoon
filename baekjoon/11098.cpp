#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		int max = 0;
		string name;
		//<pair<int, string>>�ڷ����� vector p�� ����
		vector<pair<int, string>> v(p);
		for (int j = 0; j < p; j++) {
			cin >> v[j].first >> v[j].second;
			if(max < v[j].first) {
				max = v[j].first;
				name = v[j].second;
			}
		}
		cout << name << endl;
	}
}