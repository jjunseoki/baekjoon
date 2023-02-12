#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	int cnt = 0, bonus = 0;
	int ans[100];
	cin >>  N;
	for (int i = 1; i < N+1; i++) {
		cin >> ans[i];
		if (ans[i] == 1) {
			cnt++;
			if (ans[i-1] == 1) {
				bonus++;
				cnt += bonus;
			}else {
				bonus = 0;
			}
		}
	}
	cout << cnt;
}