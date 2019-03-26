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

int main(){
    int ans = -1;
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
        for(int t1=0;t1<4;t1++){
            for(int t2=0;t2<4;t2++){
                for(int t3=0;t3<4;t3++){
                    for(int t4=0;t4<4;t4++){
                        for(int t5=0;t5<4;t5++){
                            int cur_ans = bfs(changed_maze);
                            if(cur_ans != -1){
                                if(ans == -1 || ans > cur_ans){
                                    ans = cur_ans;
                                }
                            }
                            changed_maze[4] = clockwise(changed_maze[4]);
                        }
                        changed_maze[3] = clockwise(changed_maze[3]);
                    }
                    changed_maze[2] = clockwise(changed_maze[2]);
                }
                changed_maze[1] = clockwise(changed_maze[1]);
            }
            changed_maze[0] = clockwise(changed_maze[0]);
        }
    }while(next_permutation(board_num.begin(),board_num.end()));
    printf("%d\n",ans);

    return 0;
}