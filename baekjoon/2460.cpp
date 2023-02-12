#include <iostream>
using namespace std;

int main() {
	int in, out;
	int all = 0, mx = 0;
	for (int i = 0; i < 10; i++) {
		cin >> in >> out;
		all +=  (- in + out);
		if (all > mx)
			mx = all;
	}
	cout << mx;
}