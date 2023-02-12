#include<iostream>
using namespace std;

int main() {
	int T;
	int cnt = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int V, E;
		cin >> V >> E;
		cnt = E - V + 2;
		cout << cnt << endl;
	}
}