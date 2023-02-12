#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j > i; j--) {
			cout << " ";
		}
		for (int k = 0; k < i+1; k++) {
			if (i % 2 == 0) {
				cout << "* ";
			}
			if (i % 2 == 1) {
				cout << "* ";
			}
		}
		cout << endl;
	}
}