#include <stdio.h>

int dp[101];

int main(){
    int n,r,tcase;
    dp[0] = dp[1] = 1;
    for(r=2;r<=100;r++){
        dp[r] = (dp[r-1] + dp[r-2]) % 1000000007;
    }
    scanf("%d",&tcase);
    while(tcase > 0){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
        tcase -= 1;
    }

    return 0;
}