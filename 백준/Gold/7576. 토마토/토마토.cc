#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;

int M, N;
int day = 1;
queue<pair<int,int>> q;
int tomato[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void bfs(){
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        //현재 처리중인 정점을 제거
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && tomato[nx][ny] == 0) {
                tomato[nx][ny] = tomato[xx][yy] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    //입력
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> tomato[i][j];

            //토마토가 익었을 때
            if(tomato[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }
    }

    bfs();

    int maxDay = 0; 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){

            //모두 익지는 못한 경우
            if(tomato[i][j] == 0){
                cout << -1 << '\n';
                return 0;
            }

            if(tomato[i][j] > maxDay){
                maxDay = tomato[i][j];
            }
        }
    }

    cout << maxDay - 1 << '\n'; 
    return 0;
}
