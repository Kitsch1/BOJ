#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int score[100000][3];
int dp[100000][3];

int main(){
    int n;
    int res_big, res_small;
    scanf("%d",&n);
    for(int r=0;r<n;r++){
        scanf("%d %d %d",&score[r][0],&score[r][1],&score[r][2]);
    }

    dp[0][0] = score[0][0]; dp[0][1] = score[0][1]; dp[0][2] = score[0][2];
    for(int r=1;r<n;r++){
        dp[r][0] = max(dp[r-1][0],dp[r-1][1]) + score[r][0];
        dp[r][1] = max(dp[r-1][0],max(dp[r-1][1],dp[r-1][2])) + score[r][1];
        dp[r][2] = max(dp[r-1][1],dp[r-1][2]) + score[r][2];
    }
    res_big = max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    
    memset(dp,0,sizeof(dp));
    dp[0][0] = score[0][0]; dp[0][1] = score[0][1]; dp[0][2] = score[0][2];
    for(int r=1;r<n;r++){
        dp[r][0] = min(dp[r-1][0],dp[r-1][1]) + score[r][0];
        dp[r][1] = min(dp[r-1][0],min(dp[r-1][1],dp[r-1][2])) + score[r][1];
        dp[r][2] = min(dp[r-1][1],dp[r-1][2]) + score[r][2];
    }
    res_small = min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    printf("%d %d",res_big,res_small);

    return 0;
}