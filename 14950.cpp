#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long lld;

int n,m;
lld t;
vector<vector<pair<int,lld>>> road; // first : city, second : weight
bool visited[10001];

lld solve(){
    lld ans = 0;
    lld defence = 0;
    priority_queue<pair<lld,int>> pq; // first : weight(-), second : city
    visited[1] = true;
    for(auto a : road[1]){
        pq.push({-a.second,a.first});
    }
    while(!pq.empty()){
        lld c_weight = -pq.top().first;
        int c_city = pq.top().second;
        pq.pop();
        if(visited[c_city]) continue;
        visited[c_city] = true;
        ans += (c_weight + defence);
        defence += t;
        for(auto a : road[c_city]){
            int next_city = a.first;
            lld next_weight = a.second;
            if(visited[next_city]) continue;
            pq.push({-next_weight,next_city});
        }
   }
    return ans; 
}

int main(){
    scanf("%d %d %lld",&n,&m,&t);
    road.resize(n+1);
    for(int i=0;i<m;i++){
        int n1,n2;
        lld w;
        scanf("%d %d %lld",&n1,&n2,&w);
        road[n1].push_back({n2,w});
        road[n2].push_back({n1,w});
    }
    printf("%lld\n",solve());

    return 0;
}