#include <stdio.h>

int dp[1001];

int main(){
    int n,i;
    scanf("%d",&n);
    dp[1] = 1; dp[2] = 2;
    for(i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    printf("%d\n",dp[n]);

    return 0;
}