#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

bool bfs(int start,int end,int n,vector<vector<int>> city_way){
    vector<bool> visited(n+1);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int cur_city = q.front();
        q.pop();
        if(cur_city == end) return true;

        int size = city_way[cur_city].size();
        for(int i=0;i<size;i++){
            if(!visited[city_way[cur_city][i]]){
                q.push(city_way[cur_city][i]);
                visited[city_way[cur_city][i]] = true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    bool flag = true;
    scanf("%d",&n);
    scanf("%d",&m);
    vector<vector<int>> city_way(n+1);
    vector<int> plan_list(m);

    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            int state;
            scanf("%d",&state);
            if(state) city_way[r].push_back(c);
        }
    }
    for(int r=0;r<m;r++){
        scanf("%d",&plan_list[r]);
    }
    for(int r=0;r<m-1;r++){
        if(!bfs(plan_list[r],plan_list[r+1],n,city_way)){
            flag = false; break;
        }
    }
    if(flag) printf("YES\n");
    else printf("NO\n");

    return 0;
}