#define INF 987654321
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

vector<vector<pair<int,int>>> bus_road;
int dist[1001];
int start_city,end_city;

void dijkstra(int n){
    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }
    priority_queue<pair<int,int>> cur_bus; // first : dist, second : city
    cur_bus.push({0,start_city});
    while(!cur_bus.empty()){
        int cur_dist = -cur_bus.top().first;
        int cur_city = cur_bus.top().second;
        cur_bus.pop();
        if(dist[cur_city] != INF) continue;
        dist[cur_city] = cur_dist;
        if(cur_city == end_city){
            printf("%d\n",cur_dist); return;
        }
        for(auto a : bus_road[cur_city]){
            int next_city = a.first;
            int next_dist = -cur_dist - a.second;
            if(dist[next_city] != INF) continue;
            cur_bus.push({next_dist,next_city});
        }
    }
}

int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    bus_road.resize(n+1);
    for(int i=0;i<m;i++){
        int c1,c2,weight;
        scanf("%d %d %d",&c1,&c2,&weight);
        bus_road[c1].push_back({c2,weight});
    }
    scanf("%d %d",&start_city,&end_city);
    dijkstra(n);

    return 0;
}