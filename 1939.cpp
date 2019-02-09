#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int n,m,start,last;

bool bfs(vector<vector<pair<int,int>>> &bridge,int weight){
    vector<bool> visited(n+1);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int cur_fac = q.front();
        q.pop();
        if(cur_fac == last) return true;

        int size = bridge[cur_fac].size();
        for(int i=0;i<size;i++){
            int next_fac = bridge[cur_fac][i].first;
            int next_limit = bridge[cur_fac][i].second;
            if(!visited[next_fac] && next_limit >= weight){
                visited[next_fac] = true;
                q.push(next_fac);
            }
        }
    }
    return false;
}

int main(){
    scanf("%d %d",&n,&m);
    vector<vector<pair<int,int>>> bridge(n+1);
    int min_weight,max_weight;
    min_weight = max_weight = -1;
    for(int i=0;i<m;i++){
        int n1,n2,limit;
        scanf("%d %d %d",&n1,&n2,&limit);
        bridge[n1].push_back(make_pair(n2,limit));
        bridge[n2].push_back(make_pair(n1,limit));
        if(min_weight == -1 || min_weight > limit) min_weight = limit;
        if(max_weight == -1 || max_weight < limit) max_weight = limit;
    }
    scanf("%d %d",&start,&last);
    int mid;
    while(min_weight <= max_weight){
        mid = (min_weight + max_weight) / 2;
        if(bfs(bridge,mid)){
            min_weight = mid + 1;
        }
        else{
            max_weight = mid - 1;
        }
    }
    printf("%d\n",max_weight);

    return 0;
}