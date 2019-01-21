#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int sticker[100001][2];
int dp[100001][3];

int solve(int n){
    dp[1][0] = sticker[1][0];
    dp[1][1] = sticker[1][1];

    for(int i=2;i<=n;i++){
        dp[i][0] = sticker[i][0] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = sticker[i][1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]);
    }

    return max(dp[n][0],max(dp[n][1],dp[n][2]));
}

int main(){
    int tcase,n;
    scanf("%d",&tcase);
    while(tcase > 0){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&sticker[i][0]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&sticker[i][1]);
        }
        printf("%d\n",solve(n));

        memset(dp,0,sizeof(int)*100001*3);
        tcase -= 1;
    }

    return 0;
}