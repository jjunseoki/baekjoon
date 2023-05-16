#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int B, C, D;
	int result = 0;
	int result2 = 0;
	int result3 = 0;
	cin >> B >> C >> D;
	vector<int> b(B), c(C), d(D);
	for (int i = 0; i < B; i++) {
		int burger;
		cin >> burger;
		result += burger;
		b.emplace_back(burger);
	}
	for (int i = 0; i < C; i++) {
		int side;
		cin >> side;
		result += side;
		c.emplace_back(side);
	}
	for (int i = 0; i < D; i++) {
		int drink;
		cin >> drink;
		result += drink;
		d.emplace_back(drink);
	}
	sort(b.rbegin(), b.rend());
	sort(c.rbegin(), c.rend());
	sort(d.rbegin(), d.rend());

	int mmin = min(B, min(C, D));
	for (int i = 0; i < mmin; i++) {
		result2 += b[i] + c[i] + d[i];
	}
	result2 *= 0.9;

	for (int i = mmin; i < B; i++) {
		result3 += b[i];
	}
	for (int i = mmin; i < C; i++) {
		result3 += c[i];
	}
	for (int i = mmin; i < D; i++) {
		result3 += d[i];
	}
	cout << result << '\n' << result2 + result3;
}