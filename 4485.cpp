#define INF 987654321
#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n;
int zelda[125][125];
int dist[125][125];

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void find_way(){
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({-zelda[0][0],{0,0}});
    dist[0][0] = zelda[0][0];
    while(!pq.empty()){
        int cur_dist = -pq.top().first;
        int r_cur = pq.top().second.first;
        int c_cur = pq.top().second.second;
        pq.pop();
        if(cur_dist > dist[r_cur][c_cur]) continue;
        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            int next_dist;
            if(r_next >= 0 && r_next < n && c_next >= 0 && c_next < n){
                next_dist = zelda[r_next][c_next] + cur_dist;
                if(next_dist < dist[r_next][c_next]){
                    dist[r_next][c_next] = next_dist;
                    pq.push({-next_dist,{r_next,c_next}});
                }
            }
        }
    }
}

int main(){
    int p_num = 1;
    while(1){
        scanf("%d",&n);
        if(!n) break;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                scanf("%d",&zelda[r][c]);
            }
        }
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                dist[r][c] = INF;
            }
        }
        find_way();
        printf("Problem %d: %d\n",p_num,dist[n-1][n-1]);
        p_num += 1;
        memset(zelda,0,sizeof(zelda));
    }

    return 0;
}