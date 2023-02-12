#include<iostream>
#include<string>
using namespace std;

int main() {
	int T,num;
	string str;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> num >> str;

		for (int i = 0; i < str.size(); i++) {
			if (i != num - 1) {
				cout << str[i];
			}
		}
		cout << endl;
	}
	return 0;
}