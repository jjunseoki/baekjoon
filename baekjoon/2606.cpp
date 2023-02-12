#include<iostream>
#include<vector>
#define max 101

using namespace std;

bool visited[max];
vector<int> graph[max];
int cnt = 0;

void dfs(int x) {
    // 현재 노드를 방문 처리
    visited[x] = true;
    //cout << x << ' ';
    // 현재 노드와 연결된 다른 노드를 재귀적으로 방문
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