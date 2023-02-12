#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; 
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<int> v;
		int Q;
		cin >> Q;
		for (int j = 0; j < Q; j++) {

			char c; int num;
			cin >> c >> num;
			if (c == 'I') {
				v.push_back(num);
				sort(v.begin(), v.end());
			}
			else {
				if (v.size() == 0) {
					continue;
				}
				if (num == 1) {
					v.erase(v.begin() + (v.size() - 1));
				}
				if (num == -1) {
					v.erase(v.begin());
				}
			}
		}
		if (v.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << *(--v.end()) << " " << *(v.begin()) << "\n";
		}
	}
}