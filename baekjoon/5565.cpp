#include<iostream>
using namespace std;

int main() {
	int total, indiv;
	int one_price;
	cin >> total;
	for (int i = 0; i < 9; i++) {
		cin >> indiv;
		one_price = total - indiv;
		total = one_price;
	}
	cout << one_price;
}
