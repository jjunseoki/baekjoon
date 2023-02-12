#include <iostream>
#include <string>
using namespace std;

int fib(int n) {
    if (n == 1 or n == 2)
        return 1;
    else return (fib(n - 1) + fib(n - 2));
}


int main() {
    int n;
    cin >> n;
    cout << fib(n)<< " " << n - 2;
}