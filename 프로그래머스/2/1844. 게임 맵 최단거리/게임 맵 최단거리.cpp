#include<vector>
#include<queue>
using namespace std;

int num_row, num_col;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool visit[101][101];
int dist[101][101];
queue<pair<int,int>> q;
 
int solution(vector<vector<int>> maps){
    
    int answer = 0;
    int num_row = maps.size(); 
    int num_col = maps[0].size(); 
 
    visit[0][0] = true;
    q.push({0,0});
    dist[0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop(); 
        
        for(int i=0;i<4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx<0 || nx>=num_row || ny<0 || ny>=num_col)
                continue;
            if(visit[nx][ny])
                continue;
            if(maps[nx][ny]==0)
               continue; 
    
            q.push({nx,ny});
            visit[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            }
    }
    if(dist[num_row - 1][num_col - 1] == 0)
        return -1;
    answer = dist[num_row - 1][num_col - 1];
    
    return answer;
}