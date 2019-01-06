#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[1001];

void bfs(vector<vector<int>> &v,int start);
void dfs(vector<vector<int>> &v,int start);

int main(){
    int vertex,edge,start;
    int v1,v2;

    scanf("%d %d %d",&vertex,&edge,&start);
    vector<vector<int>> graph(vertex+1);  
    for(int i=0;i<edge;i++){
        scanf("%d %d",&v1,&v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i=1;i<=vertex;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(graph,start);
    printf("\n");
    memset(visited,false,sizeof(bool)*1001);
    bfs(graph,start);
    printf("\n");

    return 0;
}

void dfs(vector<vector<int>> &v,int start){
    visited[start] = true;
    printf("%d ",start);
    unsigned int size = v[start].size();
    for(unsigned int i = 0;i<size;i++){
        if(visited[v[start][i]] == false){
            dfs(v,v[start][i]);
        }
    }
}

void bfs(vector<vector<int>> &v,int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    printf("%d ",start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        unsigned int size = v[cur].size();

        for(unsigned int i = 0;i<size;i++){
            if(visited[v[cur][i]] == false){
               visited[v[cur][i]] = true;
               q.push(v[cur][i]);
               printf("%d ",v[cur][i]);
            }
        }
    }
}