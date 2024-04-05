#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int t;
	cin >> t;
	for (int i = 0 ; i < t ; ++i)
	{
		int N; cin >> N;
		vector<int> stock;
		for (int j = 0 ; j < N ; ++j)
		{
			int temp;
			cin >> temp;
			stock.push_back(temp);
		}
		
		// Greedy Solve
		int mx = -1;
		unsigned long long result = 0;
		for (int k = N - 1 ; k >= 0 ; k--)
		{
			mx = max(mx, stock[k]);
			result += mx - stock[k];
		}
		
		cout << result << "\n";
	}
	
	return 0;
}