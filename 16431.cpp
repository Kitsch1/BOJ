#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int dist[1001][1001];
int r_john,c_john;

const int r_way[8] = {1,-1,0,0,1,1,-1,-1};
const int c_way[8] = {0,0,1,-1,1,-1,1,-1}; 

int bfs(int r_start,int c_start,int idx_limit){
    queue<pair<int,int>> q;
    q.push({r_start,c_start});
    memset(dist,-1,sizeof(dist));
    dist[r_start][c_start] = 0;

    while(!q.empty()){
        int r_cur = q.front().first;
        int c_cur = q.front().second;
        q.pop();
        if(r_cur == r_john && c_cur == c_john){
            break;
        }
        for(int i=0;i<idx_limit;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next <= 0 || r_next > 1000 || c_next <= 0 || c_next > 1000) continue;
            if(dist[r_next][c_next] == -1){
                dist[r_next][c_next] = dist[r_cur][c_cur] + 1;
                q.push({r_next,c_next});
            }
        }
    }
    return dist[r_john][c_john];
}

int main(){
    int row_bessie,col_bessie,row_daisy,col_daisy;
    scanf("%d %d",&row_bessie,&col_bessie);
    scanf("%d %d",&row_daisy,&col_daisy);
    scanf("%d %d",&r_john,&c_john);

    int ans_bessie = bfs(row_bessie,col_bessie,8);
    int ans_daisy = bfs(row_daisy,col_daisy,4);
    if(ans_bessie == ans_daisy){
        printf("tie\n");
    }
    else if(ans_bessie < ans_daisy){
        printf("bessie\n");
    }
    else{
        printf("daisy\n");
    }

    return 0;
}