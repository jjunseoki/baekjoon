#include<iostream>
using namespace std;

int main() {
	int M, N;
	int psn[10000];
	int sum = 0;
	int mini = 10000;
	//�Է�
	cin >> M;
	cin >> N;
	//psn�迭�� ������ ��ü �־������
	for (int i = 1; i <= N; i++) {
		psn[i] = i * i;
	}
	//���ǹ����� ���������� ã��
	for (int i = 1; i <= N; i++) {
		if (M <= psn[i] && psn[i] <= N) {
			sum += psn[i];
			mini = min(mini, psn[i]);
		}
	}
	//����ó��
	if (sum == 0) {
		cout << "-1\n";
	} else {
		cout << sum << endl;
		cout << mini << endl;
	}
	return 0;
}