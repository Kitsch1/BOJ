#include <cstdio>
#include <algorithm>
using namespace std;

int wine[10000];
int dp[10000][3];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&wine[i]);
    }
    dp[0][1] = wine[0]; dp[0][2] = wine[0];
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        dp[i][1] = dp[i-1][0] + wine[i];
        dp[i][2] = dp[i-1][1] + wine[i];
    }
    printf("%d\n",max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])));

    return 0;
}