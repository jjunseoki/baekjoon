#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
int arr[MAX];

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
		return b;
	}
	return gcd(b,a%b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;

		for (int i = 0; i < n; i++) 
			cin >> arr[i];

		long long  sum = 0;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				sum += gcd(arr[i], arr[j]);
		cout << sum << endl;
	}
	return 0;
}