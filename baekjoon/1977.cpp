#include<iostream>
using namespace std;

int main() {
	int M, N;
	int psn[10000];
	int sum = 0;
	int mini = 10000;
	//입력
	cin >> M;
	cin >> N;
	//psn배열에 제곱수 전체 넣어버리기
	for (int i = 1; i <= N; i++) {
		psn[i] = i * i;
	}
	//조건문으로 완전제곱수 찾기
	for (int i = 1; i <= N; i++) {
		if (M <= psn[i] && psn[i] <= N) {
			sum += psn[i];
			mini = min(mini, psn[i]);
		}
	}
	//예외처리
	if (sum == 0) {
		cout << "-1\n";
	} else {
		cout << sum << endl;
		cout << mini << endl;
	}
	return 0;
}