#define MODIFIER 1000000000
#include <stdio.h>

int dp[101][10];

int main(){
    int n,i,j,res = 0;
    scanf("%d",&n);
    for(i=1;i<10;i++){
        dp[1][i] = 1;
    }
    for(i=2;i<=n;i++){
        for(j=0;j<10;j++){
            if(j == 0) dp[i][j] = dp[i-1][1];
            else if(j == 9) dp[i][j] = dp[i-1][8];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MODIFIER;
        }
    }
    for(i=0;i<10;i++){
        res = (res + dp[n][i]) % MODIFIER; 
    }
    printf("%d\n",res);

    return 0;
}