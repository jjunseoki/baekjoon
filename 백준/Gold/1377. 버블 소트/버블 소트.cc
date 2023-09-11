#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//int A[MAX];

//void swap(int &a, int &b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
////인접한 두 숫자를 비교하여 맞지 않는 경우 교환
//void bubble_sort(int A[] , int N) {
//    bool changed = false;
//    for (int i = 1; i <= N; i++) {
//        changed = false;
//        for (int j = 1; j <= N - i; j++) {
//            if (A[j] > A[j + 1]) {
//                changed = true;
//                swap(A[j], A[j + 1]);
//            }
//        }
//        //i회전에 pass 
//        if (changed == false) {
//            cout << i << '\n';
//            break;
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    
//    int N;
//    cin >> N;
//    
//    for (int i = 1; i <= N; i++) {
//        cin >> A[i];
//    }
//    bubble_sort(A, N);
//    return 0;
//}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    int ans = -1;
    for (int i = 0; i < N; i++) {
        if (ans < v[i].second - i) {
            ans = v[i].second - i;
        }
    }
    cout << ans + 1;
}
