#include<iostream>
#include<string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;
	int cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == ',') {
			cnt++;
		}
	}
	cout << cnt+1;
}
