#include<iostream>
#include<queue>
#include<vector>
 
using namespace std;
 
int axisY, axisX;
vector<string> map;
 
struct node {
    int y;
    int x;
};
queue<node> q;
 
int dt[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int Wsum, Bsum;
 
void bfs(int yy, int xx, char tar) {
    /*
     * 인접해 있는 팀을 발견할 때 마다 cnt++
     * 탐색이 완료된 팀은 'X'표식을 해서 다시 탐색하지 않게 설정
     */
    
    //초기 상태에 대한 정보 입력
    int cnt = 0;
    q.push({yy, xx});
    map[yy][xx] = 'X';
    cnt++;
    
    //bfs 탐색
    node now;
    while (!q.empty()) {
        now = q.front();
        q.pop();
 
        for (int t = 0; t < 4; t++) {
            int dy = now.y + dt[t][0];
            int dx = now.x + dt[t][1];
 
            if (dy < 0 || dx < 0 || dy >= axisY || dx >= axisX)continue;
            if (map[dy][dx] != tar) continue;
 
            cnt++;
            map[dy][dx] = 'X';
            q.push({dy, dx});
        }
    }
 
    //팀의 힘은 주어진 조건에 따라 제곱해준다.
    if (tar == 'W') Wsum += (cnt * cnt);
    else Bsum += (cnt * cnt);
}
 
int main() {
    //전쟁터의 크기 입력 (X축, Y축 순으로)
    cin >> axisX >> axisY;
    map.assign(axisY, "");
    
    //전쟁터에 아군 적군 입력
    for (int x = 0; x < axisY; x++) {
        cin >> map[x];
    }
 
    //전쟁터에 아군 적군 탐색 후 bfs
    for (int y = 0; y < axisY; y++) {
        for (int x = 0; x < axisX; x++) {
            if (map[y][x] == 'W') bfs(y, x, 'W');
            if (map[y][x] == 'B') bfs(y, x, 'B');
        }
    }
 
    cout << Wsum << " " << Bsum;
 
    return 0;
}