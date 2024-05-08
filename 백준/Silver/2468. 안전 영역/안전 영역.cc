#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int N, answer;
int input[MAX][MAX];
int map[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int,int>> q;
vector<int> v;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(int y, int x){
    visited[y][x] = true;
    q.push(make_pair(y,x));

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;
            if (map[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

void reset(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = 0;
            visited[i][j] = false;
        }
    }
    answer = 0;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    int maxheight = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input[i][j];
            if(input[i][j] > maxheight){
                maxheight = input[i][j];
            }
        }
    } 
    for(int h = 1;  h <= maxheight; h++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(input[i][j] < h) map[i][j] = 0;
                else map[i][j] = 1;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] && !visited[i][j]) {
                    bfs(i, j);
                    answer++;
                }
            }
        }
        v.push_back(answer);
        
        reset();   
    }
    sort(v.rbegin(), v.rend());
    cout << v[0];
    return 0;	
}