#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<int> v;
int N, M;

int binarySearch(int target, int start = 0, int end = N - 1) {
    if (start > end) return 0;
    int mid = (start + end) / 2;
    // ã�� ��� �߰��� �ε��� ��ȯ
    if (v[mid] == target) return 1;
    // �߰����� ������ ã���� �ϴ� ���� ���� ��� ���� Ȯ��
    else if (v[mid] > target) return binarySearch(target, start, mid - 1);
    // �߰����� ������ ã���� �ϴ� ���� ū ��� ������ Ȯ��
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