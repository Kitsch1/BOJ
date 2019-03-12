#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int next_pos[101],dist[101];

void bfs(){
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()){
        int r_cur = q.front();
        q.pop();
        if(r_cur == 100){
            printf("%d\n",dist[100]); break;
        }
        for(int r=1;r<=6;r++){
            int r_next = r_cur + r;
            if(r_next > 100) continue;
            if(dist[next_pos[r_next]] == -1){
                dist[next_pos[r_next]] = dist[r_cur] + 1;
                q.push(next_pos[r_next]);
            }
        }
    }
}

int main(){
    int ladder,snake,n1,n2;
    for(int i=1;i<=100;i++){
        next_pos[i] = i;
    }
    scanf("%d %d",&ladder,&snake);
    for(int i=0;i<ladder+snake;i++){
        scanf("%d %d",&n1,&n2);
        next_pos[n1] = n2;
    }
    memset(dist,-1,sizeof(dist));
    bfs();

    return 0;
}