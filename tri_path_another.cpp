#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int triangle[100][100];
int dp[100][100];
int n;

int solve(int r_cur,int c_cur){
    int& ans = dp[r_cur][c_cur];
    if(ans) return ans;
    if(r_cur == n-1){
        ans = triangle[r_cur][c_cur];
        return ans;
    }
    return ans = triangle[r_cur][c_cur] + max(solve(r_cur+1,c_cur),solve(r_cur+1,c_cur+1));
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        int res = 0;

        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                scanf("%d",&triangle[i][j]);
            }
        }
        printf("%d\n",solve(0,0));

        memset(triangle,0,sizeof(int)*100*100);
        memset(dp,0,sizeof(int)*100*100);
        tcase -= 1;
    }

    return 0;
}