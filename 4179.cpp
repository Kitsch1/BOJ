#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int r_len,c_len;
char maze[1000][1000];
int fire_go[1000][1000];
int jihoon_go[1000][1000];

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void fire_bfs(queue<pair<int,int>> &fire_q){
    while(!fire_q.empty()){
        int r_cur = fire_q.front().first;
        int c_cur = fire_q.front().second;
        fire_q.pop();

        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next >= 0 && r_next < r_len && c_next >= 0 && c_next < c_len){
                if(maze[r_next][c_next] != '#' && fire_go[r_next][c_next] == -1){
                    fire_go[r_next][c_next] = fire_go[r_cur][c_cur] + 1;
                    fire_q.push(make_pair(r_next,c_next));
                }
            }
        }
    }
}

int jihoon_bfs(queue<pair<int,int>> &j_q){
    while(!j_q.empty()){
        int r_cur = j_q.front().first;
        int c_cur = j_q.front().second;
        int cur_dist = jihoon_go[r_cur][c_cur];
        j_q.pop();

        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next >= 0 && r_next < r_len && c_next >= 0 && c_next < c_len){
                if(maze[r_next][c_next] != '#' && jihoon_go[r_next][c_next] == -1 && 
                (cur_dist + 1 < fire_go[r_next][c_next] || fire_go[r_next][c_next] == -1)){
                    jihoon_go[r_next][c_next] = cur_dist + 1;
                    j_q.push(make_pair(r_next,c_next));
                }
            }
            else{
                return cur_dist + 1;
            }
        }
    }
    return -1;
}

int main(){
    char input[1004];
    queue<pair<int,int>> j_q,fire_q;
    scanf("%d %d",&r_len,&c_len);
    memset(fire_go,-1,sizeof(fire_go));
    memset(jihoon_go,-1,sizeof(jihoon_go));
    for(int r=0;r<r_len;r++){
        scanf("%s",input);
        for(int c=0;c<c_len;c++){
            maze[r][c] = input[c];
            if(maze[r][c] == 'J'){
                j_q.push(make_pair(r,c));
                jihoon_go[r][c] = 0;
            }
            if(maze[r][c] == 'F'){
                fire_q.push(make_pair(r,c));
                fire_go[r][c] = 0;
            }
        }
    }
    fire_bfs(fire_q);
    int res = jihoon_bfs(j_q);
    if(res == -1) printf("IMPOSSIBLE\n");
    else printf("%d\n",res);

    return 0;
}