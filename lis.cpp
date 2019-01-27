#include <cstdio>
#include <cstring>

int n;
int numbers[501];
int dp[501];

int solve(){
    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=i-1;j>0;j--){
            if(numbers[j] < numbers[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }
    }
    int res = dp[1];
    for(int i=2;i<=n;i++){
        if(res < dp[i]) res = dp[i];
    }
    return res;
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&numbers[i]);
        }
        printf("%d\n",solve());
        tcase -= 1;
    }

    return 0;
}