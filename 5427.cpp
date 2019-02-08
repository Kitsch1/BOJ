#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

char building[1002][1002];
int dist[1002][1002];
int fire_time[1002][1002];
int r_len,c_len;


const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void fire_bfs(queue<pair<int,int>> fire_q){
    while(!fire_q.empty()){
        int r_cur = fire_q.front().first;
        int c_cur = fire_q.front().second;
        int sec = fire_time[r_cur][c_cur];
        fire_q.pop();

        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next >= 0 && r_next < r_len && c_next >= 0 && c_next < c_len){
                if(building[r_next][c_next] != '#' && fire_time[r_next][c_next] == -1){
                    fire_q.push(make_pair(r_next,c_next));
                    fire_time[r_next][c_next] = sec + 1;
                }
            }
        }
    }
}

int escape_bfs(queue<pair<int,int>> &sang_q){
    while(!sang_q.empty()){
        int r_cur = sang_q.front().first;
        int c_cur = sang_q.front().second;
        int sec = dist[r_cur][c_cur];
        sang_q.pop();

        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];

            if(r_next < 0 || r_next >= r_len || c_next < 0 || c_next >= c_len){
                return sec + 1;
            }
        }

        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next >= 0 && r_next < r_len && c_next >= 0 && c_next < c_len){
                if(building[r_next][c_next] != '#' && dist[r_next][c_next] == -1 && (sec + 1 < fire_time[r_next][c_next] || fire_time[r_next][c_next] == -1)){
                    sang_q.push(make_pair(r_next,c_next));
                    dist[r_next][c_next] = sec + 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    int tcase;
    char input[1004];
    scanf("%d",&tcase);
    while(tcase > 0){
        queue<pair<int,int>> fire_q, sang_q;
        scanf("%d %d",&c_len,&r_len);
        memset(building,0,sizeof(building));
        memset(fire_time,-1,sizeof(fire_time));
        memset(dist,-1,sizeof(dist));

        for(int r=0;r<r_len;r++){
            scanf("%s",input);
            for(int c=0;c<c_len;c++){
                building[r][c] = input[c];
                if(building[r][c] == '*'){
                    fire_q.push(make_pair(r,c));
                    fire_time[r][c] = 0;
                }
                if(building[r][c] == '@'){
                    sang_q.push(make_pair(r,c));
                    dist[r][c] = 0;
                }
            }
        }
        fire_bfs(fire_q);
        int ans = escape_bfs(sang_q);
        if(ans == -1) {
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("%d\n",ans);
        }
        tcase -= 1;
    }

    return 0;
}