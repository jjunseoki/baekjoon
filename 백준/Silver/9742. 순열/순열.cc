#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int factorial(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}

void findPermutation(string str, int num) {
	if (num > factorial(str.length())) {
		cout << "No permutation" << '\n';
		return;
	}
	while (str.length() > 1) {
		int f = factorial(str.length() - 1);
		int pos = num / f;
		num %= f;
		if (num == 0) {
			cout << str[pos - 1];
			str.erase(str.begin() + pos - 1);
			reverse(str.begin(), str.end());
			cout << str << '\n';
			return;
		}
		cout << str[pos];
		str.erase(str.begin() + pos);
	}
	cout << str[0] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int num;

	while (cin >> str >> num) {
		cout << str << " " << num << " = ";
		findPermutation(str, num);
	}
	return 0;
}