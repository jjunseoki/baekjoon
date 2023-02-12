#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int N, M, cnt = 0;
string target;
vector<string> v;
vector<string> answer;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.emplace_back(str);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		string target;
		cin >> target;
		if (binary_search(v.begin(), v.end(), target)) {
			answer.emplace_back(target);
		}
	}
	sort(answer.begin(), answer.end());
	
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}