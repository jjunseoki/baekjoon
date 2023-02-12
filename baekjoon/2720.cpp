#include<iostream>
using namespace std;

int coin[] = {25, 10, 5, 1};
int cnt = 0;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int C;
		cin >> C;
	for (int i = 0; i < 4; i++) {
		cnt += C / coin[i];
		C %= coin[i];
	}
	cout << 1;
}