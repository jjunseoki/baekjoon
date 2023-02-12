#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int len = s.length();
	int i = 0;
	if (len % 3 == 1) {
		cout << s[0];
		i = 1;
	}
	else if (len % 3 == 2) {
		cout << ((s[0] - '0') * 2) + (s[0] - '0');
		i = 2;
	}
	for (; i < len; i += 3) {
		cout << ((s[i] - '0') * 4) + ((s[i + 1] - '0') * 2) + (s[i + 2] - '0');
	}
	cout << endl;
	return 0;
}