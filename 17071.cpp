#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int dist[500001][2];
int subin,young;

int bfs(){
    queue<pair<int,int>> q;
    memset(dist,-1,sizeof(dist));
    dist[subin][0] = 0;
    q.push({0,subin});
    while(!q.empty()){
        int sec = q.front().first;
        int pos = q.front().second;
        q.pop();
        int t = sec % 2;
        if(pos+1 <= 500000 && dist[pos+1][1-t] == -1){
            dist[pos+1][1-t] = sec + 1;
            q.push({sec+1,pos+1});
        }
        if(pos-1 >= 0 && dist[pos-1][1-t] == -1){
            dist[pos-1][1-t] = sec + 1;
            q.push({sec+1,pos-1});
        }
        if(pos*2 <= 500000 && dist[pos*2][1-t] == -1){
            dist[pos*2][1-t] = sec + 1;
            q.push({sec+1,pos*2});
        }
    }
    int y_pos = young;
    int ans = -1;
    for(int r=0;;r++){
        y_pos += r;
        if(y_pos > 500000) break;
        if(dist[y_pos][r%2] != -1 && dist[y_pos][r%2] <= r){
            ans = r; break;
        }
    }
    return ans;
}

int main(){
    scanf("%d %d",&subin,&young);
    printf("%d\n",bfs());

    return 0;
}