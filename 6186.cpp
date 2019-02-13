#include <cstdio>
using namespace std;

int r_len,c_len;
char field[100][100];
bool visited[100][100];

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void dfs(int r_cur,int c_cur){
    visited[r_cur][c_cur] = true;
    for(int i=0;i<4;i++){
        int r_next = r_cur + r_way[i];
        int c_next = c_cur + c_way[i];
        if(r_next >= 0 && r_next < r_len && c_next >= 0 && c_next < c_len){
            if(field[r_next][c_next] == '#' && !visited[r_next][c_next]){
                dfs(r_next,c_next);
            }
        }
    }
}

int solve(){
    int ans = 0;
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            if(field[r][c] == '#' && !visited[r][c]){
                ans += 1;
                dfs(r,c);
            }
        }
    }
    return ans;
}

int main(){
    char input[104];
    scanf("%d %d",&r_len,&c_len);
    for(int r=0;r<r_len;r++){
        scanf("%s",input);
        for(int c=0;c<c_len;c++){
            field[r][c] = input[c];
        }
    }
    printf("%d\n",solve());

    return 0;
}