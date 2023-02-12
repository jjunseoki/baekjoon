#include<iostream>
using namespace std;

int arr[201];

int main() {
	int N, v;
	int  cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		}
	cin >> v;
	for (int i = 0; i < N; i++) {
		if (arr[i] == v) cnt++;
	}
	cout << cnt;
	return 0;
}