#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void recur(int i, int j, int N) {
	if ((i / N) % 3 == 1 && (j / N) % 3 == 1) {
		cout << ' ';
	}
	else {
		if (N /3 == 0) {
			cout << "*";
		}
		else {
			recur(i, j, N / 3);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	//ют╥б
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			recur(i, j, N);
		}
		cout << "\n";
	}
}