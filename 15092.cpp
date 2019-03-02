#include <cstdio>
using namespace std;

char plate[100][100];
bool visited[100][100];
int r_len,c_len;

const int r_way[8] = {1,-1,0,0,1,1,-1,-1};
const int c_way[8] = {0,0,1,-1,1,-1,1,-1};

void dfs(int r_cur,int c_cur){
    visited[r_cur][c_cur] = true;
    for(int i=0;i<8;i++){
        int r_next = r_cur + r_way[i];
        int c_next = c_cur + c_way[i];
        if(r_next >= 0 && r_next < r_len && c_next >= 0 && c_next < c_len){
            if(!visited[r_next][c_next] && plate[r_next][c_next] == '#'){
                dfs(r_next,c_next);
            }
        }
    }
}

int amoeba(){
    int ans = 0;
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            if(!visited[r][c] && plate[r][c] == '#'){
                dfs(r,c);
                ans += 1;
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
            plate[r][c] = input[c];
        }
    }
    printf("%d\n",amoeba());

    return 0;
}