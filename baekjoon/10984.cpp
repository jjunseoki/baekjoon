#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		int C, C_sum = 0;
		float G, G_sum = 0;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> C >> G;
			C_sum += C;
			G_sum += C * G;
		}
	cout << fixed;
	cout.precision(1);
	cout << C_sum << " " << G_sum / C_sum << endl;
	}
}