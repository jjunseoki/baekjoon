#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define MAX 26
using namespace std;

int arr[MAX][MAX];
bool visited[MAX][MAX];
vector<int> ans;
int N;
//상 하 좌 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int cnt = 0;
    cnt++;

    while(!q.empty()){
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if((0 <= nx) && (nx < N) && (0 <= ny) && (ny < N) && visited[nx][ny] == false && arr[nx][ny] == 1){
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    ans.emplace_back(cnt);
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < N; j++){
            arr[i][j] = str.at(j) - '0';
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == false && arr[i][j] == 1){  
                bfs(i, j);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
    return 0;
}