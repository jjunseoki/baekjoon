#include <iostream>
#include <string>
using namespace std;
int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    
    //to_string�Լ��� ����Ÿ���� �����͸� �����ϰ� ��Ʈ�� Ÿ������ ����
    string s1 = to_string(A) + to_string(B);
    string s2 = to_string(C) + to_string(D);
    
    //���ڿ� -> ���� long longŸ��(8byte)���� ��ȯ�ϱ� ���� stoll���
    long long l1 = stoll(s1);
    long long l2 = stoll(s2);

    cout << l1 + l2 << endl;
	return 0;
}