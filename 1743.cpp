#include <cstdio>
using namespace std;

char rubbish[101][101];
bool visited[101][101];
int cur_size;
int r_len, c_len;

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void dfs(int r_cur,int c_cur){
    visited[r_cur][c_cur] = true;
    cur_size += 1;
    for(int i=0;i<4;i++){
        int r_next = r_cur + r_way[i];
        int c_next = c_cur + c_way[i];
        if(r_next >= 1 && r_next <= r_len && c_next >= 1 && c_next <= c_len){
            if(rubbish[r_next][c_next] == '#' && !visited[r_next][c_next]){
                dfs(r_next,c_next);
            }
        }
    }
}


int flood_fill(){
    int ans = -1;
    for(int r=1;r<=r_len;r++){
        for(int c=1;c<=c_len;c++){
            if(rubbish[r][c] == '#' && !visited[r][c]){
                cur_size = 0;
                dfs(r,c);
                if(ans < cur_size) ans = cur_size;
            }
        }
    }
    return ans;
}

int main(){
    int rub_num;
    scanf("%d %d %d",&r_len,&c_len,&rub_num);
    for(int i=0;i<rub_num;i++){
        int r,c;
        scanf("%d %d",&r,&c);
        rubbish[r][c] = '#';
    }
    printf("%d\n",flood_fill());

    return 0;
}