#include<iostream>
using namespace std;

int main() {
	int N, sum =0;
	for (int i = 0; i < 5; i++) {
		cin >> N;
		sum += N;
	}
	cout << sum;
}