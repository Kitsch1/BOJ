#include <stdio.h>

int numbers[1000];
int dp[1000];

int main(){
    int n,i,j,res;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&numbers[i]);
    }
    dp[0] = numbers[0];
    for(i=1;i<n;i++){
        dp[i] = numbers[i];
        for(j=0;j<i;j++){
            if(numbers[j] < numbers[i] && dp[j]+numbers[i] > dp[i]) dp[i] = dp[j] + numbers[i];
        }
    }
    res = dp[0];
    for(i=1;i<n;i++){
        if(res < dp[i]) res = dp[i];
    }
    printf("%d\n",res);

    return 0;
}