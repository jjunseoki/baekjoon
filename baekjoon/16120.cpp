#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string p;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int one = 0;
	cin >> p;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 'P') {
			one++;
			continue; //else 안쓰고 시간 절약
		}
		if (one >= 2 && p[i+1] == 'P') {
			one--;
			i++;
		}
		else {
			cout << "NP";
			return 0;
		}
	}
	if (one == 1) cout << "PPAP";
	else cout << "NP";
	return 0;
}