#include <iostream>
#include <vector>
using namespace std;



int main() {
	int K, num;
	vector<int> v(100001);

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num != 0) {
			v.emplace_back(num);
		}
		else {
			v.pop_back();
		}
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v.back();
		v.pop_back();
	}
	cout << sum;
}