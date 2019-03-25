#include <cstdio>
#include <cstring>
using namespace std;
typedef long long lld;

int n;
int pipe[32][32];
lld dp[32][32][3];

lld solve(int r,int c,int dir){
    if(r == n-1 && c == n-1) return 1;
    lld &ans = dp[r][c][dir];
    if(ans != -1) return ans;
    ans = 0;

    if(dir == 0){
        if(c+1 < n && pipe[r][c+1] == 0) ans += solve(r,c+1,0);
        if(r+1 < n && c+1 < n && pipe[r][c+1] == 0 && pipe[r+1][c] == 0 && pipe[r+1][c+1] == 0){
            ans += solve(r+1,c+1,1);
        }
    }
    else if(dir == 1){
        if(c+1 < n && pipe[r][c+1] == 0) ans += solve(r,c+1,0);
        if(r+1 < n && pipe[r+1][c] == 0) ans += solve(r+1,c,2);
        if(r+1 < n && c+1 < n && pipe[r][c+1] == 0 && pipe[r+1][c] == 0 && pipe[r+1][c+1] == 0){
            ans += solve(r+1,c+1,1);
        }
    }
    else{
        if(r+1 < n && pipe[r+1][c] == 0) ans += solve(r+1,c,2);
        if(r+1 < n && c+1 < n && pipe[r][c+1] == 0 && pipe[r+1][c] == 0 && pipe[r+1][c+1] == 0){
            ans += solve(r+1,c+1,1);
        }
    }

    return ans;
}

int main(){
    scanf("%d",&n);
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            scanf("%d",&pipe[r][c]);
        }
    }
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",solve(0,1,0));

    return 0;
}