#define MOD 1000000009
#define MAX_N 100000
#include <stdio.h>

int dp[100001][4];

int main(){
    int n,i,tcase,ans;
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(i=4;i<=MAX_N;i++){
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
    }
    scanf("%d",&tcase);
    while(tcase > 0){
        scanf("%d",&n);
        ans = (dp[n][1] + dp[n][2]) % MOD;
        ans = (ans + dp[n][3]) % MOD;
        printf("%d\n",ans);
        tcase -= 1;
    }

    return 0;
}