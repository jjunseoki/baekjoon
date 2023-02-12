#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string S;
	string temp[1000];
	cin >> S;
	int n = S.length();
	for (int i = 0; i < n; i++) {
		temp[i] = S.substr(i, n);
	}
	sort(temp, temp + n);
	for (int i = 0; i < n; i++) {
		cout << temp[i] << endl;
	}
}
