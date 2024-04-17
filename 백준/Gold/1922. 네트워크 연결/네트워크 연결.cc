#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

int N, M;
vector<pair<int, int>> edge[MAX];
bool visited[MAX];

int prim(){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> pq;
    int result = 0;
    pq.push({0, 1});
    for(int i = 1; i <= N; i++){
        while (!pq.empty() &&visited[pq.top().second]) {
			pq.pop();
		}
		int next = pq.top().second;
		int minCost = pq.top().first;
		visited[next] = true;
		result += minCost;
		for (auto o : edge[next]) {
			pq.push({ o.second,o.first });
		}
	}
	return result;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0; i  < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    cout << prim();
	return 0;	
}