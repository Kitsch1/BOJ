#include <iostream>
#include <cstring>
using namespace std;

int r,c,k,len;
char board[100][100];
char need_to_find[84];
int dp[100][100][80];

const int way_r[4] = {0,0,1,-1};
const int way_c[4] = {1,-1,0,0};

int solve(int cur_r,int cur_c,int idx){
    if(idx == len) return 1;

    int& ans = dp[cur_r][cur_c][idx];
    if(ans != -1) return ans;
    
    ans = 0;
    for(int i=0;i<4;i++){
        int next_r = cur_r;
        int next_c = cur_c;
        for(int j=0;j<k;j++){
            next_r += way_r[i];
            next_c += way_c[i];

            if(next_r < 0 || next_r >= r || next_c < 0 || next_c >= c) break;
            if(need_to_find[idx] == board[next_r][next_c]){
                ans += solve(next_r,next_c,idx+1);
            }
        }
    }
    return ans;
}

int main(){
    char input[104];
    int res = 0;

    cin >> r >> c >> k;
    for(int i=0;i<r;i++){
        cin >> input;
        for(int j=0;j<c;j++){
            board[i][j] = input[j];
        }
    }
    cin >> need_to_find;
    len = strlen(need_to_find);
    memset(dp,-1,sizeof(int)*100*100*80);
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j] == need_to_find[0]){
                res += solve(i,j,1);
            }
        }
    }
    cout << res << '\n';

    return 0;
}