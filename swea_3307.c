#include <stdio.h>
#include <string.h>

int numbers[1000];
int dp[1000];

int solve(int n){
    int i,j,res;
    for(i=0;i<n;i++){
        dp[i] = 1;
        for(j=i-1;j>=0;j--){
            if(numbers[j] < numbers[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }
    }
    res = dp[0];
    for(i=1;i<n;i++){
        if(res < dp[i]) res = dp[i];
    }
    return res;
}

int main(){
    int tcase,i,j,n;
    scanf("%d",&tcase);
    for(i=1;i<=tcase;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d",&numbers[j]);
        }
        printf("#%d %d\n",i,solve(n));
    }

    return 0;
}