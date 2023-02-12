#include <iostream>
#include <string>
using namespace std;
int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    
    //to_string함수는 숫자타입의 데이터를 안전하게 스트링 타입으로 변경
    string s1 = to_string(A) + to_string(B);
    string s2 = to_string(C) + to_string(D);
    
    //문자열 -> 정수 long long타입(8byte)으로 변환하기 위해 stoll사용
    long long l1 = stoll(s1);
    long long l2 = stoll(s2);

    cout << l1 + l2 << endl;
	return 0;
}