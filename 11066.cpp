#include <cstdio>
#include <cstring>

int file_size[501];
int dp[501][501];

int solve(int start,int end){
    if(start == end) return 0;

    int& ans = dp[start][end];
    if(ans != -1) return ans;
    ans = 0;

    int f_sum = 0;
    for(int i=start;i<=end;i++){
        f_sum += file_size[i];
    }
    for(int i=start;i<=end;i++){
        int new_ans = solve(start,i) + solve(i+1,end) + f_sum;
        if(ans == 0 || ans > new_ans){
            ans = new_ans;
        }
    }
    return ans;
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        int n,res = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&file_size[i]);
        }
        memset(dp,-1,sizeof(int)*501*501);
        solve(1,n);
        printf("%d\n",dp[1][n]);
        tcase -= 1;
    }

    return 0;
}