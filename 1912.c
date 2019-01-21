#include <stdio.h>

int numbers[100000];
int dp[100000];

int main(){
    int n,i,res;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&numbers[i]);
    }
    dp[0] = numbers[0];
    for(i=1;i<n;i++){
        dp[i] = numbers[i] > (dp[i-1]+numbers[i]) ? numbers[i] : dp[i-1] + numbers[i];
    }
    res = dp[0];
    for(i=1;i<n;i++){
        if(res < dp[i]) res = dp[i];
    }
    printf("%d\n",res);

    return 0;
}