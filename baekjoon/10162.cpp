#include <iostream>
using namespace std;

int main() {
	int T;
	int A_cnt, B_cnt, C_cnt;
	cin >> T;
	
	if (T % 10 != 0) cout << -1;
	else {
		A_cnt = T / 300;
		B_cnt = (T - A_cnt*300) / 60;
		C_cnt = ((T - (A_cnt * 300) - (B_cnt * 60))) / 10;
		cout << A_cnt << " " << B_cnt << " " << C_cnt;
	}
	return 0;
}