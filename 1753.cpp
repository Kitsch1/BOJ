#define INF 987654321
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int v_num,e_num,start_v;
int dist[20002];

void dijkstra(vector<vector<pair<int,int>>> &v_graph){
    priority_queue<pair<int,int>> cur_edges;
    cur_edges.push({0,start_v});
    while(!cur_edges.empty()){
        int cur_weight = -cur_edges.top().first;
        int cur_vertex = cur_edges.top().second;
        cur_edges.pop();
        if(dist[cur_vertex] != INF) continue;
        dist[cur_vertex] = cur_weight;
        for(auto a : v_graph[cur_vertex]){
            int v_next = a.first;
            int weight_next = -a.second - cur_weight;
            if(dist[v_next] != INF) continue;
            cur_edges.push({weight_next,v_next});
        }
    }
    for(int i=1;i<=v_num;i++){
        if(dist[i] == INF) printf("INF\n");
        else printf("%d\n",dist[i]);
    }
}

int main(){
    scanf("%d %d",&v_num,&e_num);
    scanf("%d",&start_v);
    vector<vector<pair<int,int>>> v_graph(v_num+1);
    for(int i=0;i<e_num;i++){
        int v1,v2,weight;
        scanf("%d %d %d",&v1,&v2,&weight);
        v_graph[v1].push_back({v2,weight});
    }
    for(int i=1;i<=v_num;i++){
        dist[i] = INF;
    }
    dijkstra(v_graph);

    return 0;
}