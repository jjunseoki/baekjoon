#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<int> v;
int N, M;

int binarySearch(int target, int start = 0, int end = N - 1) {
    if (start > end) return 0;
    int mid = (start + end) / 2;
    // 찾은 경우 중간점 인덱스 반환
    if (v[mid] == target) return 1;
    // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
    else if (v[mid] > target) return binarySearch(target, start, mid - 1);
    // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
    else return binarySearch(target, mid + 1, end);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }
    sort(v.begin(), v.end());
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;
        cout << binarySearch(target) << "\n";
    }
}