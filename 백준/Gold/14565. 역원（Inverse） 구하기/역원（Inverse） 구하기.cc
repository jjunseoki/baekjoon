#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

long long GCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long result = GCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N, A;
    cin >> N >> A;

    long long iplus = 0, imulti = 0;

    iplus = N - A;
    
    long long x, y;
    imulti = GCD(A, N, x, y);

    if (imulti == 1) {
        imulti = (x % N + N) % N; // 음수일 경우 
    }
    else {
        imulti = -1; 
    }


    cout << iplus << " " << imulti;
    return 0;
}
