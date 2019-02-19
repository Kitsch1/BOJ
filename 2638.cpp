#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int cheese[100][100];
bool outer[100][100];
int r_len,c_len,cur_cheese;

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void check_outer(int r_cur,int c_cur){
    outer[r_cur][c_cur] = true;
    for(int i=0;i<4;i++){
        int r_next = r_cur + r_way[i];
        int c_next = c_cur + c_way[i];
        if(r_next < 0 || r_next >= r_len || c_next < 0 || c_next >= c_len) continue;
        if(!cheese[r_next][c_next] && !outer[r_next][c_next]){
            check_outer(r_next,c_next);
        }
    }
}

int solve(){
    int ans = 0;
    int r_cheese = r_len - 1;
    int c_cheese = c_len - 1;
    while(1){
        if(!cur_cheese) break;
        ans += 1;
        check_outer(0,0);
        vector<pair<int,int>> melted;
        for(int r=1;r<r_cheese;r++){
            for(int c=1;c<c_cheese;c++){
                int out_num = 0;
                if(cheese[r][c]){
                    for(int i=0;i<4;i++){
                        int r_beside = r + r_way[i];
                        int c_beside = c + c_way[i];
                        if(!cheese[r_beside][c_beside] && outer[r_beside][c_beside]){
                            out_num += 1;
                        }
                    }
                    if(out_num >= 2) melted.push_back(make_pair(r,c));
                }
            }
        }
        int size = melted.size();
        cur_cheese -= size;
        for(int i=0;i<size;i++){
            cheese[melted[i].first][melted[i].second] = 0;
        }
        memset(outer,false,sizeof(outer));
    }
    return ans;
}

int main(){
    scanf("%d %d",&r_len,&c_len);
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            scanf("%d",&cheese[r][c]);
            if(cheese[r][c]) cur_cheese += 1;
        }
    }
    printf("%d\n",solve());

    return 0;
}