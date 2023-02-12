#include<iostream>
#include<vector>

using namespace std;

int n;
int a[1000001];
int sum = 0;

int plus(void) {
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	
}