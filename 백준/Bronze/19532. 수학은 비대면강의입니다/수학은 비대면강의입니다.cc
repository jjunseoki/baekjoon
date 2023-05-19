#include <iostream>
#include<algorithm>
#include<string>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,b,c,d,e,f;
	int x = 0, y = 0;
	cin >> a >> b >> c >> d >> e >> f;
	for (int i = -999; i < 1000; i++) {
		for (int j = -999; j < 1000; j++) {
			if (a * i + b * j == c) {
				if (d * i + e * j == f) {
					cout << i << " " << j;
					break;
				}
			}
		}
	}
}