#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

int r_len,c_len,cur_cheese;
int cheese[100][100];
bool outer[100][100];

const int r_way[4] = {0,0,1,-1};
const int c_way[4] = {1,-1,0,0};

void check_out(int r,int c){
    outer[r][c] = true;
    for(int i=0;i<4;i++){
        int r_next = r + r_way[i];
        int c_next = c + c_way[i];
        if(r_next >= 0 && r_next < r_len && c_next >= 0 && c_next < c_len){
            if(!cheese[r_next][c_next] && !outer[r_next][c_next]){
                check_out(r_next,c_next);
            }
        }
    }
}

void solve(){
    int ans = 0;
    int r_cheese = r_len - 1;
    int c_cheese = c_len - 1;
    while(1){
        vector<pair<int,int>> melted;
        check_out(0,0);
        for(int r=1;r<r_cheese;r++){
            for(int c=1;c<c_cheese;c++){
                bool out_flag = false;
                if(cheese[r][c]){
                    for(int i=0;i<4;i++){
                        int r_beside = r + r_way[i];
                        int c_beside = c + c_way[i];
                        if(outer[r_beside][c_beside]){
                            out_flag = true; break;
                        }
                    }
                }
                if(out_flag) melted.push_back(make_pair(r,c));
            }
        }
        int size = melted.size();
        if(cur_cheese - size == 0){
            printf("%d\n%d\n",ans+1,cur_cheese); break;
        }
        cur_cheese -= size;
        for(int i=0;i<size;i++){
            cheese[melted[i].first][melted[i].second] = 0;
        }
        ans += 1;
        memset(outer,false,sizeof(outer));
    }
}

int main(){
    scanf("%d %d",&r_len,&c_len);
    for(int r=0;r<r_len;r++){
        for(int c=0;c<c_len;c++){
            scanf("%d",&cheese[r][c]);
            if(cheese[r][c]) cur_cheese += 1;
        }
    }
    solve();

    return 0;
}