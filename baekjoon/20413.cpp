#include <iostream>
#include <string>
using namespace std;

int N;
int s, g, p, d, pay[36];
int result = 0;
char str;

int cal(int idx, char C) {
	if (idx == 0) {
		if (C == 'B')
			return s - 1;
		else if (C == 'S')
			return g - 1;
		else if (C == 'G')
			return p - 1;
		else if (C == 'P')
			return d - 1;
		else if (C == 'D')
			return d;
	}
	else {
		int pPay = pay[idx - 1];
		if (C == 'B')
			return s - 1 - pPay;
		else if (C == 'S')
			return g - 1 - pPay;
		else if (C == 'G')
			return p - 1 - pPay;
		else if (C == 'P')
			return d - 1 - pPay;
		else if (C == 'D')
			return d;
	}
}


int main() {
	cin >> N >> s >> g >> p >> d;

	for (int i = 0; i < N; i++) {
		cin >> str;
		pay[i] = cal(i, str);
		result += pay[i];
	}	
	cout << result;
	return 0;
}