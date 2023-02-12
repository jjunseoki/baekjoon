#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i= 0; i < T; i++) {
		int sum = 0;
		vector<int> v(5);
		for (int j = 0; j < 5; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());
		if (v[3] - v[1] >= 4) {
			cout << "KIN" << endl;
		}
		else {
			sum = v[1] + v[2] + v[3];
			cout << sum << endl;
		}
	}
}