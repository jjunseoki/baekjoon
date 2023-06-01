#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    stack<int> s;
    long long cnt = 0;
    int h;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> h;
        //비어있으면 값 넣기
        if (s.empty()) {
            s.push(h);
            continue;
        }
        //비어있지않거나 더높은 빌딩이면 지우기
        while (!s.empty() && s.top() <= h) {
            s.pop();
        }
        //값 더하기
        cnt += s.size();

        s.push(h);
    }
    cout << cnt;
}