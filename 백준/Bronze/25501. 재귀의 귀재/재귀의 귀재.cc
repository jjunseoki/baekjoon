#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
# define MAX 1001 

using namespace std;

int cnt = 0;

//
int recursion(const char* s, int i, int r) {
    cnt++;
    if (i >= r) return 1;
    else if (s[i] != s[r]) return 0;
    else return recursion(s, i + 1, r - 1);
}

//어떤 문자열이 팰린드롬인지 여부를 판단
int isPalindrome(const char* s) {
    cout << recursion(s, 0, strlen(s) - 1) << " ";
    int returnNum = cnt;
    cnt = 0;
    return returnNum;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        char str[MAX];
        cin >> str;
        cout << isPalindrome(str) << '\n';
    }
}