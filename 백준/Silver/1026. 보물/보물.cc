#include <iostream>
#include <algorithm>
#include <string>
#define MAX 51
using namespace std;

int A[MAX], B[MAX];

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }

    sort(A, A+N);
    sort(B, B+N, greater<>());

    int result = 0;
    for(int i = 0; i < N; i++){ 
        result += A[i] * B[i];  
    }
    cout << result;
    return 0;
}
