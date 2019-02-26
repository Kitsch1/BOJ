#include <cstdio>
using namespace std;
typedef long long lld;

int r_len,c_len;
char combat[100][100];
bool visited[100][100];
lld p_num;

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void dfs(int r_cur,int c_cur,char team){
    visited[r_cur][c_cur] = true;
    p_num += 1;
    for(int i=0;i<4;i++){
        int r_next = r_cur + r_way[i];
        int c_next = c_cur + c_way[i];
        if(r_next >= 0 && r_next < r_len && c_next >= 0 && c_next < c_len){
            if(!visited[r_next][c_next] && combat[r_next][c_next] == team){
                dfs(r_next,c_next,team);
            }
        }
    }
}

void power_of_army(){
    lld ally = 0,enemy = 0;
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            if(!visited[r][c]){
                p_num = 0;
                dfs(r,c,combat[r][c]);
                if(combat[r][c] == 'W') ally += (p_num * p_num);
                else enemy += (p_num * p_num);
            }
        }
    }
    printf("%lld %lld\n",ally,enemy);
}

int main(){
    char input[104];
    scanf("%d %d",&c_len,&r_len);
    for(int r=0;r<r_len;r++){
        scanf("%s",input);
        for(int c=0;c<c_len;c++){
            combat[r][c] = input[c];
        }
    }
    power_of_army();

    return 0;
}