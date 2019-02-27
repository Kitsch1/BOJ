#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>> road;
vector<bool> included;

int mst(int n){
    int ans = 0;
    int biggest_bridge = -1;
    priority_queue<pair<int,int>> pq; // first : weight (-), second : city
    for(auto a : road[1]){
        pq.push({-a.second,a.first});
    }
    included[1] = true;
    while(!pq.empty()){
        int c_weight = -pq.top().first;
        int c_city = pq.top().second;
        pq.pop();
        if(included[c_city]) continue;
        included[c_city] = true;
        ans += c_weight;
        if(biggest_bridge < c_weight) biggest_bridge = c_weight;
        for(auto a : road[c_city]){
            int next_city = a.first;
            int next_weight = -a.second;
            if(included[next_city]) continue;
            pq.push({next_weight,next_city});
        }
    }
    return ans - biggest_bridge;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    road.resize(n+1);
    included.resize(n+1);
    for(int i=0;i<m;i++){
        int c1,c2,w;
        scanf("%d %d %d",&c1,&c2,&w);
        road[c1].push_back({c2,w});
        road[c2].push_back({c1,w});
    }
    printf("%d\n",mst(n));

    return 0;
}