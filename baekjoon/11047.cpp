#include <iostream>
using namespace std;

int main() {
	int N,K;
	int coin[11];
	cin >> N >> K;
	for (int i=0; i < N; i++) 
		cin >> coin[i];
	int sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		sum += K / coin[i];
		K = K % coin[i];
	}
	cout << sum << endl;
}