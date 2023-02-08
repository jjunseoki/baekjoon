#include<iostream>
#include<algorithm>

using namespace std;

int N, result = 987654321, cnt = 0;
string present, target, tmp;

//스위치 누르는 함수
void Push(int idx) {
    // i - 1 전구
    if (idx > 0) {
        if (tmp[idx - 1] == '0') {
            tmp[idx - 1] = '1';
        }
        else {
            tmp[idx - 1] = '0';
        }
    }
    // i 번째 전구
    if (tmp[idx] == '0') {
        tmp[idx] = '1';
    }else {
        tmp[idx] = '0';
    }
    // i + 1 전구
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
    //임시적으로 tmp에 저장
    tmp = present;
    cnt = 0;
    // 첫번째코드를 키고 시작하는 경우
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
    //전구를 하나씩 키는 상태, i는 1부터 시작한다!
    for (int i = 1; i < N; i++) {
        if (tmp[i - 1] != target[i - 1]) {
            Push(i);
            cnt++;
        }
    }
    //만약 전구를 킨 횟수가 result값보다 작을 경우 다시 갱신한다.
    if (tmp == target)
        result = min(result, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	cin >> N >> present >> target;
    //첫번째 전구를 키고 시작하는 경우
	solve(0);
    //두번째 전구를 키고 시작하는 경우
	solve(1);
    //result값이 새로 갱신되었으면 바로 출력
	if (result != 987654321)
		cout << result;
	// 불가능한 경우에는 -1을 출력한다. 
	else
		cout << -1;
}