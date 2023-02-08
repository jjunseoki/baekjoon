#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v1;
	vector<int> v2 = {1, 1, 2, 2, 2, 8};

	for (int i = 0; i < 6; i++) {
		int num; 
		cin >> num;
		int num2 = v2[i] - num;
		v1.emplace_back(num2);
	}
	for (int i = 0; i < 6; i++) {
		cout << v1[i] << " ";
	}
}