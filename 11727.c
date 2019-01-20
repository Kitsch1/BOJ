#include <stdio.h>

int dp[1001];

int main(){
    int n,i;
    scanf("%d",&n);
    dp[1] = 1; dp[2] = 3;
    for(i=3;i<=n;i++){
        dp[i] = (2 * dp[i-2] + dp[i-1]) % 10007;
    }
    printf("%d\n",dp[n]);

    return 0;
}