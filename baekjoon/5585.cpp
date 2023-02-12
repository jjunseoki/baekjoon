#include <iostream>
using namespace std;

int M;
int cnt;
int M_last;
int Coin[6] = { 500, 100, 50, 10, 5 , 1 };

int main() {
	cin >> M;
	M_last = 1000 - M;
	for (int i = 0; i < 6; i++) {
		cnt += M_last / Coin[i];
		M_last %= Coin[i];
	}
	cout << cnt;
}
