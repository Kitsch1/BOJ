#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int h_way[6] = {1,-1,0,0,0,0};
const int r_way[6] = {0,0,1,-1,0,0};
const int c_way[6] = {0,0,0,0,1,-1}; 
int h_start,r_start,c_start;
int h_end,r_end,c_end;
int h_size,r_size,c_size;

int bfs(vector<vector<vector<char>>> &maze){
    int dist[30][30][30];
    queue<pair<int,pair<int,int>>> q;
    q.push({h_start,{r_start,c_start}});
    memset(dist,-1,sizeof(dist));
    dist[h_start][r_start][c_start] = 0;
    
    while(!q.empty()){
        int h_cur = q.front().first;
        int r_cur = q.front().second.first;
        int c_cur = q.front().second.second;
        q.pop();
        if(h_cur == h_end && r_cur == r_end && c_cur == c_end){
            break;
        }
        for(int i=0;i<6;i++){
            int h_next = h_cur + h_way[i];
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(h_next < 0 || h_next >= h_size || r_next < 0 || r_next >= r_size || c_next < 0 || c_next >= c_size) continue;
            if(maze[h_next][r_next][c_next] != '#' && dist[h_next][r_next][c_next] == -1){
                dist[h_next][r_next][c_next] = dist[h_cur][r_cur][c_cur] + 1;
                q.push({h_next,{r_next,c_next}});
            }
        }
    }
    return dist[h_end][r_end][c_end];
}

int main(){
    while(1){
        scanf("%d %d %d",&h_size,&r_size,&c_size);
        if(h_size == 0 && r_size == 0 && c_size == 0) break;
        vector<vector<vector<char>>> maze(h_size);
        char input[36];
        for(int i=0;i<h_size;i++){
            maze[i].resize(r_size,vector<char>(c_size));
            for(int r=0;r<r_size;r++){
                scanf("%s",input); 
                for(int c=0;c<c_size;c++){
                    maze[i][r][c] = input[c];
                    if(maze[i][r][c] == 'S'){
                        h_start = i; r_start = r; c_start = c;
                    }
                    if(maze[i][r][c] == 'E'){
                        h_end = i; r_end = r; c_end = c;
                    }
                }
                getchar();
            }
        }
        int ans = bfs(maze);
        if(ans == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",ans);
    }

    return 0;
}