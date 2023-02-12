#include<iostream>
using namespace std;

int arr[100];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		int sum = 0;
		int big = 0;
		int small = 100;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[i];
			big = max(big, arr[i]);
			small = min(small, arr[i]);
		}
		sum = 2 * (big - small);
		cout << sum << endl;
	}
}