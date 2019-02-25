#define INF 987654321
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int dist[1001], from[1001];
int start_city,end_city;

void dijkstra(vector<vector<pair<int,int>>> &bus){
    priority_queue<pair<int,int>> cur_road; // first : dist, second : city
    from[start_city] = -1;
    dist[start_city] = 0;
    cur_road.push({0,start_city});
    while(!cur_road.empty()){
        int cur_dist = -cur_road.top().first;
        int cur_city = cur_road.top().second;
        cur_road.pop();
        if(cur_dist > dist[cur_city]) continue;
        for(auto a : bus[cur_city]){
            int next_city = a.first;
            int next_dist = a.second;
            if(dist[cur_city] + next_dist < dist[next_city]){
                dist[next_city] = dist[cur_city] + next_dist;
                from[next_city] = cur_city;
                cur_road.push({-dist[next_city],next_city});
            }
        }
    }
    printf("%d\n",dist[end_city]);
    deque<int> c_num;
    int city_back = end_city;
    while(city_back != -1){
        c_num.push_front(city_back);
        city_back = from[city_back];
    }
    printf("%d\n",c_num.size());
    for(auto it : c_num){
        printf("%d ",it);
    }
    printf("\n");
}

int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    vector<vector<pair<int,int>>> bus(n+1);
    for(int i=0;i<m;i++){
        int c1,c2,weight;
        scanf("%d %d %d",&c1,&c2,&weight);
        bus[c1].push_back({c2,weight});
    }
    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }
    scanf("%d %d",&start_city,&end_city);
    dijkstra(bus);

    return 0;
}