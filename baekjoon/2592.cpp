#include<iostream>
using namespace std;
int arr[1001];
int main() {
	int num;
	int avg = 0, sum = 0;
	pair<int, int> res; // (È½¼ö, ¼ö) ÀÌ¸§
	for (int i = 0; i < 10; i++) {
		cin >> num;
		sum += num;
		avg = sum / 10;
		arr[num]++;
		if (res.first < arr[num]) {
			res.first = arr[num];
			res.second = num;
		}
	}
	cout << avg << endl << res.second;
}