#include <cstdio>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int r_len,c_len;
int barrack[100][100];
int dist[100][100][2];

const int r_way[4] = {1,-1,0,0};
const int c_way[4] = {0,0,1,-1};

bool bfs(int cur_level){
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,0}});
    dist[0][0][0] = 0;

    while(!q.empty()){
        int skip = q.front().first;
        int r_cur = q.front().second.first;
        int c_cur = q.front().second.second;
        q.pop();
        if(r_cur == r_len - 1 && c_cur == c_len - 1){
            break;
        }
        for(int i=0;i<4;i++){
            int r_next = r_cur + r_way[i];
            int c_next = c_cur + c_way[i];
            if(r_next >= 0 && r_next < r_len && c_next >= 0 && c_next < c_len){
                if(dist[r_next][c_next][skip] == -1){
                    if(cur_level >= barrack[r_next][c_next]){
                        dist[r_next][c_next][skip] = dist[r_cur][c_cur][skip] + 1;
                        q.push({skip,{r_next,c_next}});
                    }
                    else if(skip == 0){
                        int r_two = r_next + r_way[i];
                        int c_two = c_next + c_way[i];
                        if(r_two < 0 || r_two >= r_len || c_two < 0 || c_two >= c_len) continue;
                        if(cur_level >= barrack[r_two][c_two] && dist[r_two][c_two][skip+1] == -1){
                            dist[r_two][c_two][skip+1] = dist[r_cur][c_cur][skip] + 1;
                            q.push({skip+1,{r_two,c_two}});
                        }
                    }
                }
            }
        }
    }
    if(dist[r_len-1][c_len-1][0] != -1 || dist[r_len-1][c_len-1][1] != -1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    scanf("%d %d",&r_len,&c_len);
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            scanf("%d",&barrack[r][c]);
        }
    }
    int l_start = barrack[0][0], l_end = 1000000000;
    while(l_start <= l_end){
        int m_level = (l_start + l_end) / 2;
        memset(dist,-1,sizeof(dist));
        bool flag = bfs(m_level);
        if(flag){
            l_end = m_level - 1;
        }
        else{
            l_start = m_level + 1;
        }
    }
    printf("%d\n",l_start);

    return 0;
}