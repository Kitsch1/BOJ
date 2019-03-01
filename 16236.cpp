#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int fish[20][20];
int dist[20][20];
int eaten_fish, eat_time, ans_time;
int r_shark,c_shark;
int n;

const int r_way[4] = {-1,0,0,1};
const int c_way[4] = {0,-1,1,0};

bool bfs(int shark_size){
    int first_time = -1;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{r_shark,c_shark}});
    dist[r_shark][c_shark] = 0;
    while(!q.empty()){
        int cur_time = q.front().first;
        int r_cur = q.front().second.first;
        int c_cur = q.front().second.second;
        q.pop();
        if(first_time == cur_time){
            eat_time = first_time;
            return true;
        }
        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next >= 0 && r_next < n && c_next >= 0 && c_next < n){
                if(dist[r_next][c_next] == -1){
                    if(!fish[r_next][c_next] || shark_size == fish[r_next][c_next]){
                        dist[r_next][c_next] = dist[r_cur][c_cur] + 1;
                        q.push({cur_time+1,{r_next,c_next}});
                    }
                    else if(shark_size > fish[r_next][c_next]){
                        dist[r_next][c_next] = dist[r_cur][c_cur] + 1;
                        if(first_time == -1) first_time = dist[r_next][c_next];
                        q.push({cur_time+1,{r_next,c_next}});
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    int f_size;
    scanf("%d",&n);
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            scanf("%d",&f_size);
            if(f_size == 9){
                r_shark = r; c_shark = c;
            }
            else fish[r][c] = f_size;
        }
    }
    int shark_size = 2;
    while(1){
        memset(dist,-1,sizeof(dist));
        bool flag = bfs(shark_size);
        if(!flag) break;
        bool find_first = false;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(fish[r][c] && fish[r][c] < shark_size && dist[r][c] == eat_time){
                    r_shark = r; c_shark = c;
                    fish[r][c] = 0;
                    find_first = true;
                    break;                    
                }
            }
            if(find_first) break;
        }
        ans_time += eat_time;
        eaten_fish += 1;
        if(eaten_fish == shark_size){
            eaten_fish = 0;
            shark_size += 1;
        }
    }
    printf("%d\n",ans_time);

    return 0;
}