#include <iostream>
#include <algorithm>
using namespace std;

//소인수분해
long long func(int n, int x)
{
	int num = 0;

	for (long long i = x; n / i >= 1; i *= x) {
		num += n / i;
	}

	return num;
}

int main() {
	long long two = 0, five = 0;
	long long N, M;
	cin >> N >> M;
	
	five = func(N, 5) - func(N - M, 5) - func(M, 5);
	two = func(N, 2) - func(N - M, 2) - func(M, 2);

	//소인수 2와 5의 최소개수가 0의 개수
	cout << min(five, two) << endl;

	return 0;
}