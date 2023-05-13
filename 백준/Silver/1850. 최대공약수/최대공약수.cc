#include <iostream>
#include<queue>
#include<string>
using namespace std;

long long GCD(long long A, long long B) {
	return (A % B == 0 ? B : GCD(B, A % B));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	long long A, B;
	cin >> A >> B;
	long long result = GCD(A, B);
	while (result--) {
		cout << 1;
	}
}