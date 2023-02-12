#include<iostream>
#include<vector>
#define max 101

using namespace std;

bool visited[max];
vector<int> graph[max];
int cnt = 0;

void dfs(int x) {
    // ���� ��带 �湮 ó��
    visited[x] = true;
    //cout << x << ' ';
    // ���� ���� ����� �ٸ� ��带 ��������� �湮
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) {
            dfs(y);
            cnt++;
        }
    }
}

int main() {
    int com, line;
    cin >> com >> line;
    for (int i = 0; i < line; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    dfs(1);
    cout << cnt << '\n';
}