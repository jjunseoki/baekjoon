#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visit;

void bfs(vector<vector<int>> computers, int start){
    queue<int> q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        for (int j = 0; j < computers.size(); j++) {
            if (computers[current][j] == 1 && !visit[j]) {
                visit[j] = true;
                q.push(j);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visit = vector<bool>(n, false); //초기화

    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            bfs(computers, i);
            answer++;
        }
    }
    return answer;
}