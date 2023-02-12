#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N-i; j++) {
			cout << " ";
		}
		for (int k = 0; k < i*2 + 1; k++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cout << " ";
		}
		for (int k = 0; k < (N - i-1) * 2 - 1; k++) {
			cout << "*";
		}
		cout << endl;
	}
}