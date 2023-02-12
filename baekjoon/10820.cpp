#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	while (getline(cin, S)) {
		int lower = 0;
		int upper = 0;
		int number = 0;
		int space = 0;
		for (char sentence : S) {
			if (sentence >= 'a' && sentence <= 'z') {
				lower += 1;
			}
			else if (sentence >= 'A' && sentence <= 'Z') {
				upper += 1;
			}
			else if (sentence >= '0' && sentence <= '9') {
				number += 1;
			}
			else if (sentence == ' ') {
				space += 1;
			}
		}
		cout << lower << " " << upper << " " << number << " " << space << endl;
	}
	return 0;
}