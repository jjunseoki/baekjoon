#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 17
using namespace std;

vector<pair<int,int>> v(MAX);
int dp[MAX] = {0,};

int main() {
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> v[i].first >> v[i].second;
    }
    for(int i = N; i > 0; i--){
        int time =v[i].first;
        int pay = v[i].second;
        int nexti = i + time;

        // 상담 기간이 퇴사일을 넘지 않는 경우
        if(nexti <= N + 1){
            dp[i] = max(pay + dp[nexti], dp[i + 1]);
        } else { // 상담이 불가능한 경우
            dp[i] = dp[i + 1];
        }
    }

    // 첫째 날에 시작할 수 있는 최대 이익 출력
    cout << dp[1];
    return 0;
}