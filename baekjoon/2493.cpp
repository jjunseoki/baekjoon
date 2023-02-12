#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>


using namespace std;

int N;
stack<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int height;
		cin >> height;
		
		//스택이 비어있지않으면
		while (!v.empty()) {
			if (v.top().second > height) {
				cout << v.top().first << " ";
				break;
			}
			v.pop();
		}
		if (v.empty()) cout << "0 ";
		v.push({ i, height });
	}
}