#include<iostream>
using namespace std;

int main() {
	int day;
	int cnt = 0;
	cin >> day;
	for (int i = 0; i < 5; i++) {
		int car;
		cin >> car;
		if (day == car) {
			cnt++;
		}
	}
	cout << cnt;
}