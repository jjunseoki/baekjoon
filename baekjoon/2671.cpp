#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <regex>  //정규표현식 헤더

using namespace std;
// regex_match  정규표현식일 떄 사용
string str[151];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	string ptn = "(100+1+|01)+";
	if (regex_match(str, regex(ptn))) cout << "SUBMARINE";
	else cout << "NOISE";
	return 0;
	/*int i = 0;
	int s = str.length();

	while (i < s) {
		if (str[i] == '0') {
			if (str[i + 1] == '0') {
				cout << "NOISE";
			}
			else if (str[i + 1] == '1') {
				i += 2;
			}
		}
		else {
			if (str[i + 1] == '0' && str[i + 2] == '0')
			i++;
			cout << "SUBMARINE";
		}
	}*/
}