#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A;
	cin >> A;
	
	vector<int> v = {1000000};
	for (int i = 0; i < A; i++) {
		int num;
		cin >> num;
		if(num > v.back())
			v.emplace_back(num);
		else {
			//lower_bound: 찾으려는 key값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
			int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
			v[idx] = num;
		}
	}
	cout << v.size();
}