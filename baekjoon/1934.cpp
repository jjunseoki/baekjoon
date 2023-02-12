#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	int T;
	int A, B;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B ;
		cout << lcm(A, B) << endl;
	}
}