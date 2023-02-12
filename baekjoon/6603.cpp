#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int S[13];
int lotto[6];
int K;

void getcombi(int start, int idx) {
	if (idx == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < K; i++) {
		lotto[idx] = S[i];
		getcombi(i + 1, idx + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	
	while (1) {
		cin >> K;
		if (K == 0) break;
		for (int i = 0; i < K; i++) {
			cin >> S[i];
		}
		getcombi(0, 0);
		cout << '\n';
	}
}