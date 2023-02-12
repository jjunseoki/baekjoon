#include <iostream>
#include <queue>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K;
	queue<int> q;
	cin >> N >> K;

	for (int i = 1; i < N+1; i++) {
		q.push(i);
	}
	cout << "<";
	while (q.size()>1) {
		for (int i = 1; i < K; i++) {
			int tmp = q.front();
			q.pop(); //앞에서 빼서
			q.push(tmp); //뒤에 다시 넣는다
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">\n";
}