#include<iostream>
using namespace std;

int main() {
	int N;
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		cnt += p;	
	}
	cnt -= (N - 1);
	cout << cnt;
}