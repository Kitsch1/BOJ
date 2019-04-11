#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

int r_len,c_len;
int water[50][50];
int safe[50][50];

const int r_way[8] = {1,-1,0,0,1,-1,1,-1};
const int c_way[8] = {0,0,1,-1,1,1,-1,-1};

int bfs(int r_start,int c_start){
    bool visited[50][50];
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{r_start,c_start}});
    memset(visited,false,sizeof(visited));
    visited[r_start][c_start] = true;
    
    int ans;
    while(!q.empty()){
        int dist = q.front().first;
        int r_cur = q.front().second.first;
        int c_cur = q.front().second.second;
        q.pop();

        if(water[r_cur][c_cur] == 1){
            ans = dist; break;
        }
        for(int i=0;i<8;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next < 0 || r_next >= r_len || c_next < 0 || c_next >= c_len) continue;
            if(!visited[r_next][c_next]){
                visited[r_next][c_next] = true;
                q.push({dist+1,{r_next,c_next}});
            }
        }
    }
    return ans;
}

int solve(){
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            if(water[r][c]) continue;
            safe[r][c] = bfs(r,c);
        }
    }
    int ans = -1;
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            if(safe[r][c] > 0 && (ans == -1 || ans < safe[r][c])){
                ans = safe[r][c];
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d %d",&r_len,&c_len);
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            scanf("%d",&water[r][c]);
        }
    }
    printf("%d\n",solve());

    return 0;
}