#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int r_start,c_start,r_end,c_end,n;
int dist[200][200];

const int r_way[6] = {-2,-2,0,0,2,2};
const int c_way[6] = {-1,1,-2,2,-1,1};

void bfs(){
    queue<pair<int,int>> q;
    dist[r_start][c_start] = 0;
    q.push({r_start,c_start});
    
    while(!q.empty()){
        int r_cur = q.front().first;
        int c_cur = q.front().second;
        q.pop();
        if(r_cur == r_end && c_cur == c_end) break;
        for(int i=0;i<6;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next < 0 || r_next >= n || c_next < 0 || c_next >= n) continue;
            if(dist[r_next][c_next] == -1){
                dist[r_next][c_next] = dist[r_cur][c_cur] + 1;
                q.push({r_next,c_next});
            }
        }
    }
    printf("%d\n",dist[r_end][c_end]);
}

int main(){
    scanf("%d",&n);
    scanf("%d %d %d %d",&r_start,&c_start,&r_end,&c_end);
    memset(dist,-1,sizeof(dist));
    bfs();

    return 0;
}