#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int n = 5;
const int h_way[6] = {1,-1,0,0,0,0};
const int r_way[6] = {0,0,1,-1,0,0};
const int c_way[6] = {0,0,0,0,1,-1};
vector<int> turned_num;
int ans = -1;

vector<vector<int>> clockwise(vector<vector<int>> &v){
    vector<vector<int>> turn_board(n,vector<int>(n));
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            turn_board[r][c] = v[n-c-1][r];
        }
    }
    return turn_board;
}

int bfs(vector<vector<vector<int>>> &changed_maze){
    if(changed_maze[0][0][0] == 0) return -1;

    int dist[5][5][5];
    queue<pair<int,pair<int,int>>> q;
    memset(dist,-1,sizeof(dist));
    q.push({0,{0,0}});
    dist[0][0][0] = 0;

    while(!q.empty()){
        int h = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        for(int i=0;i<6;i++){
            int h_next = h + h_way[i];
            int r_next = r + r_way[i];
            int c_next = c + c_way[i];
            if(h_next < 0 || h_next >= n || r_next < 0 || r_next >= n || c_next < 0 || c_next >= n) continue;
            if(changed_maze[h_next][r_next][c_next] == 1 && dist[h_next][r_next][c_next] == -1){
                dist[h_next][r_next][c_next] = dist[h][r][c] + 1;
                q.push({h_next,{r_next,c_next}});
            }
        }
    }
    return dist[n-1][n-1][n-1];
}

void solve(int idx,vector<vector<vector<int>>> &changed_maze){
    if(idx == n){
        vector<vector<vector<int>>> now_maze(n);
        for(int i=0;i<n;i++){
            now_maze[i] = changed_maze[i];
        }
        for(int i=0;i<n;i++){
            int cnt = turned_num[i];
            for(int j=0;j<cnt;j++){
                now_maze[i] = clockwise(now_maze[i]);
            }
        }
        int cur_ans = bfs(now_maze);
        if(cur_ans != -1){
            if(ans == -1 || ans > cur_ans) ans = cur_ans;
        }
        return;
    }
    for(int i=0;i<4;i++){
        turned_num.push_back(i);
        solve(idx+1,changed_maze);
        turned_num.pop_back();
    }
}

int main(){
    vector<vector<vector<int>>> first_maze(n);
    for(int h=0;h<n;h++){
        first_maze[h].resize(n,vector<int>(n));
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                scanf("%d",&first_maze[h][r][c]);
            }
        }
    }
    vector<int> board_num;
    for(int i=0;i<5;i++){
        board_num.push_back(i);
    }
    do{
        vector<vector<vector<int>>> changed_maze(n);
        for(int i=0;i<n;i++){
            changed_maze[board_num[i]] = first_maze[i];
        }
        solve(0,changed_maze);
    }while(next_permutation(board_num.begin(),board_num.end()));
    printf("%d\n",ans);

    return 0;
}