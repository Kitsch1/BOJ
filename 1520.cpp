#include <cstdio>
#include <cstring>
using namespace std;

int m,n;
int mountain[500][500];
int dp[500][500];

const int dir_m[4] = {0,0,1,-1};
const int dir_n[4] = {1,-1,0,0};

int solve(int cur_m,int cur_n){
    if(cur_m == m-1 && cur_n == n-1) return 1;
    if(dp[cur_m][cur_n] != -1) return dp[cur_m][cur_n];
    
    int& ans = dp[cur_m][cur_n];
    ans = 0;
    
    for(int i=0;i<4;i++){
        int next_m = cur_m + dir_m[i];
        int next_n = cur_n + dir_n[i];
        if(cur_m >= 0 && cur_m < m && cur_n >= 0 && cur_n < n){
            if(mountain[cur_m][cur_n] > mountain[next_m][next_n]){
                ans += solve(next_m,next_n);
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mountain[i][j]);
        }
    }
    memset(dp,-1,sizeof(int)*500*500);
    solve(0,0);
    printf("%d\n",dp[0][0]);

    return 0;
}