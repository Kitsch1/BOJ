#include <stdio.h>
#include <string.h>

int dp[100001];

int main(){
    int n,i,j;
    scanf("%d",&n);
    memset(dp,-1,sizeof(int)*100001);
    dp[0] = 0;
    for(i=1;i<=n;i++){
        for(j=1;j*j<=i;j++){
            if(dp[i] == -1 || dp[i-j*j] + 1 < dp[i]){
                dp[i] = dp[i-j*j] + 1; 
            }
        }
    }
    printf("%d\n",dp[n]);

    return 0;
}