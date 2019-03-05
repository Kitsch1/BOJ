#define INF 987654321
#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int road[100][100];
int dist[100][100];

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void dijkstra(int n){
    priority_queue<pair<int,pair<int,int>>> pq;
    dist[0][0] = road[0][0];
    pq.push({-road[0][0],{0,0}});
    while(!pq.empty()){
        int cur_dist = -pq.top().first;
        int r_cur = pq.top().second.first;
        int c_cur = pq.top().second.second;
        pq.pop();
        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            int next_dist;
            if(r_next < 0 || r_next >= n || c_next < 0 || c_next >= n) continue;
            next_dist = cur_dist + road[r_next][c_next];
            if(next_dist < dist[r_next][c_next]){
                dist[r_next][c_next] = next_dist;
                pq.push({-next_dist,{r_next,c_next}});
            }
        }
    }
}

int main(){
    int tcase;
    char input[104];
    scanf("%d",&tcase);
    for(int i=1;i<=tcase;i++){
        int n;
        scanf("%d",&n);
        for(int r=0;r<n;r++){
            scanf("%s",input);
            for(int c=0;c<n;c++){
                road[r][c] = input[c] - '0';
            }
        }
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                dist[r][c] = INF;
            }
        }
        dijkstra(n);
        printf("#%d %d\n",i,dist[n-1][n-1]);
    }

    return 0;
}