#include <iostream>
using namespace std;

//최대공약수 알고리즘
int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int N, S;
	int gcd_tmp = -1;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		int distance = (S > A) ? (S - A) : (A - S);
		if (gcd_tmp != -1) {
			gcd_tmp = gcd(gcd_tmp, distance);
		}
		else 
		{
			gcd_tmp = distance;
		}
	} 
	cout << gcd_tmp << endl;

	return 0;
}