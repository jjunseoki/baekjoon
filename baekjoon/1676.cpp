#include <iostream>
using namespace std;
//뒤에 0이 나오는 경우는 10이 곱해진 경우밖에서 없어서 소인수분해하여
// 5의 개수를 구하면된다.
int main() {
    int ans = 0;
    int n;
    cin >> n;
    //5의 배수 +1. 25의 배수 + 2 ~~
    for (int i = 5; i <= n; i *= 5) {
        ans += n / i;
    }
    cout << ans << '\n';
    return 0;
}