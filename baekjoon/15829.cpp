#include<iostream>
#include<stack>
#include<string>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L;
	char a;
	long long M = 1234567891; // ���μ� M
	string str;
	long long hash = 0;
	cin >> L >> str;

	long long r = 1;
	for (int i = 0; i < L; i++) {
		a = str[i];
		hash = (hash + (a - 96) * r) % M; // (a * r) mod M
		r = (r * 31) % M; // pow(r, n); -> ���� �ʹ� Ŀ���ϱ� ��� mod M ���ش�.
	}

	cout << hash;
	return 0;
}