#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> tomo;
int dist[501];

int bfs(int n){
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int st_num = q.front();
        q.pop();
        for(auto t : tomo[st_num]){
            if(dist[t] == -1){
                dist[t] = dist[st_num] + 1;
                q.push(t);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] == 1 || dist[i] == 2) ans += 1;
    }
    return ans;
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    for(int i=1;i<=tcase;i++){
        int n,m;
        scanf("%d %d",&n,&m);
        tomo.resize(n+1);
        for(int j=0;j<m;j++){
            int p1,p2;
            scanf("%d %d",&p1,&p2);
            tomo[p1].push_back(p2);
            tomo[p2].push_back(p1);
        }
        memset(dist,-1,sizeof(dist));
        printf("#%d %d\n",i,bfs(n));
        tomo.clear();
    }

    return 0;
}