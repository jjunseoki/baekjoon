#include <iostream>
using namespace std;
//�ڿ� 0�� ������ ���� 10�� ������ ���ۿ��� ��� ���μ������Ͽ�
// 5�� ������ ���ϸ�ȴ�.
int main() {
    int ans = 0;
    int n;
    cin >> n;
    //5�� ��� +1. 25�� ��� + 2 ~~
    for (int i = 5; i <= n; i *= 5) {
        ans += n / i;
    }
    cout << ans << '\n';
    return 0;
}