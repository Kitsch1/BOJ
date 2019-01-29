#include <cstdio>
#include <cstring>

int dp[1001];
int price[1001];

int main(){
    int n;
    scanf("%d",&n);
    for(int r=1;r<=n;r++){
        scanf("%d",&price[r]);
    }
    memset(dp,-1,sizeof(int)*1001);
    dp[0] = 0;
    for(int r=1;r<=n;r++){
        for(int c=r;c<=n;c++){
            if(dp[c] == -1 || dp[c] > dp[c-r] + price[r] ){
                dp[c] = dp[c-r] + price[r];
            }
        }
    }
    printf("%d\n",dp[n]);

    return 0;
}