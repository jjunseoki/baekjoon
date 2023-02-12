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
	int num1, num2;
	cin >> num1 >> num2;
	cout << gcd(num1, num2) << endl << lcm(num1, num2);
}