#include<iostream>
#include<algorithm>

using namespace std;

int N, result = 987654321, cnt = 0;
string present, target, tmp;

//����ġ ������ �Լ�
void Push(int idx) {
    // i - 1 ����
    if (idx > 0) {
        if (tmp[idx - 1] == '0') {
            tmp[idx - 1] = '1';
        }
        else {
            tmp[idx - 1] = '0';
        }
    }
    // i ��° ����
    if (tmp[idx] == '0') {
        tmp[idx] = '1';
    }else {
        tmp[idx] = '0';
    }
    // i + 1 ����
    if (idx < N-1) {
        if (tmp[idx + 1] == '0') {
            tmp[idx + 1] = '1';
        }
        else {
            tmp[idx + 1] = '0';
        } 
    }
}

void solve(int first) {
    //�ӽ������� tmp�� ����
    tmp = present;
    cnt = 0;
    // ù��°�ڵ带 Ű�� �����ϴ� ���
    if (first == 0) {
        if (tmp[0] == '0') {
            tmp[0] = '1';
        }else { 
            tmp[0] = '0'; }
        if (tmp[1] == '0') {
            tmp[1] = '1';
        }else {
            tmp[1] = '0';
        }
        cnt++;
    }
    //������ �ϳ��� Ű�� ����, i�� 1���� �����Ѵ�!
    for (int i = 1; i < N; i++) {
        if (tmp[i - 1] != target[i - 1]) {
            Push(i);
            cnt++;
        }
    }
    //���� ������ Ų Ƚ���� result������ ���� ��� �ٽ� �����Ѵ�.
    if (tmp == target)
        result = min(result, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�Է�
	cin >> N >> present >> target;
    //ù��° ������ Ű�� �����ϴ� ���
	solve(0);
    //�ι�° ������ Ű�� �����ϴ� ���
	solve(1);
    //result���� ���� ���ŵǾ����� �ٷ� ���
	if (result != 987654321)
		cout << result;
	// �Ұ����� ��쿡�� -1�� ����Ѵ�. 
	else
		cout << -1;
}