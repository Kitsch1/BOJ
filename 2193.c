#include <stdio.h>

long long dp[91][2];

int main(){
    int n,i;
    scanf("%d",&n);
    dp[1][1] = dp[2][0] = 1;
    for(i=3;i<=n;i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    printf("%lld\n",dp[n][0] + dp[n][1]);

    return 0;
}