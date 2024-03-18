#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<stack>
#include<algorithm>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int visited[MAX] = { 0, };
int result[MAX];
int cnt = 0;
queue<int> q;

void bfs(int r) {
	queue<int> q;
	q.push(r); 
	visited[r] = true; 
	cnt++; // 처음 방문한 곳 카운트 + 1
	result[r] = cnt; // 처음으로 방문 cnt == 1
	while (!q.empty()) {
		int inq = q.front(); // 큐에 첫번째 원소 저장
		q.pop();
		for (int i = 0; i < graph[inq].size(); i++) {
			int temp = graph[inq][i];
			if (!visited[temp]) { // 노드에 연결된 노드가 방문하지 않은 곳이면
				cnt++;
				result[temp] = cnt;
				q.push(temp);
				visited[temp] = true;
			}
		}
	}
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	//입력
    int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // (1,4) (1,2) (2,3) (2,4) (3,4)
		graph[b].push_back(a); // (4,1) (2,1) (3,2) (4,2) (4,3)	
	}

    // 오름차순 방문을 위한 정렬
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
    bfs(r);

	for (int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}
    return 0;
}