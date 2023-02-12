#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N , M;

	cin >> N;
	vector<int>card(N, 0);
	for (int i = 0; i < N; ++i) 
		cin >> card[i];
	sort(card.begin(), card.end());
	

	cin >> M;

	vector<int>check(M, 0);
	vector<int>result(M, 0);

	for (int i = 0; i < M; ++i) {
		cin >> check[i];
		//ÀÌºÐ Å½»ö
		int left = 0;
		int right = N - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (card[mid] == check[i]) {
				result[i]++;
				break;
			}
			else if (card[mid] < check[i])
				left = mid + 1;
			else if (card[mid] > check[i])
				right = mid - 1;
		}
	}
	for (int i = 0; i < M; ++i) 
		cout << result[i] << " ";
}