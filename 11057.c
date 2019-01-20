#include <stdio.h>

int dp[1001][10];

int main(){
    int n,i,j,res = 0;
    scanf("%d",&n);
    for(i=0;i<10;i++){
        dp[1][i] = 1;
    }
    for(i=2;i<=n;i++){
        dp[i][0] = 1;
        for(j=1;j<10;j++){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
        }
    }
    for(i=0;i<10;i++){
        res = (res + dp[n][i]) % 10007;
    }
    printf("%d\n",res);

    return 0;
}