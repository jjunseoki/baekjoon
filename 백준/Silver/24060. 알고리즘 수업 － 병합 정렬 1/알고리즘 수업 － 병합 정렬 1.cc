#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int* tmp;
int cnt = 0;

void merge(int A[], int p, int q, int r, int K) {
    int i = p; int j = q + 1; int t = 1;
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        }
        else {
            tmp[t++] = A[j++];
        }
    }
    while (i <= q)
        tmp[t++] = A[i++];
    while (j <= r)
        tmp[t++] = A[j++];
    i = p; t = 1;
    while (i <= r) {
        A[i++] = tmp[t++];
        cnt++;
        if (cnt == K) {
            cout << tmp[t - 1];
            exit(0); // K번째 수를 찾았으면 프로그램 종료
        }
    }
}

void merge_sort(int A[], int p, int r, int K) {
    if (p < r) {
        int q = ((p + r) / 2);
        merge_sort(A, p, q, K);
        merge_sort(A, q + 1, r, K);
        merge(A, p, q, r, K);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    int* A;
    A = new int[N + 1]; // 배열의 크기를 1 증가시켜 out-of-bound 에러를 방지
    tmp = new int[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    merge_sort(A, 0, N - 1, K);
    if (cnt < K) cout << -1;

    // 메모리 해제
    delete[] A;
    delete[] tmp;

    return 0;
}
