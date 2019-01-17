#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int triangle[100][100];
int dp[100][100];

int solve(int n){
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for(int j=1;j<=i;j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
        }
    }
    int res = dp[n-1][0];
    for(int i=1;i<n;i++){
        if(res < dp[n-1][i]) res = dp[n-1][i];
    }
    return res;
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                scanf("%d",&triangle[i][j]);
            }
        }
        dp[0][0] = triangle[0][0];
        printf("%d\n",solve(n));
        
        memset(triangle,0,sizeof(int)*100*100);
        memset(dp,0,sizeof(int)*100*100);
        tcase -= 1;
    }

    return 0;
}