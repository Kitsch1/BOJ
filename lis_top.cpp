#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int numbers[501];
int dp[501];

int solve(int start){
    int& ans = dp[start];
    if(ans != -1) return ans;
    ans = 1;
    for(int next=start+1;next<=n;next++){
        if(numbers[start] < numbers[next]){
            ans = max(ans,solve(next)+1);
        }
    }
    return ans;
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&numbers[i]);
        }
        memset(dp,-1,sizeof(int)*501);
        for(int i=1;i<=n;i++){
            solve(i);
        }
        int res = dp[1];
        for(int i=2;i<=n;i++){
            if(res < dp[i]) res = dp[i];
        }
        printf("%d\n",res);
        tcase -= 1;
    }

    return 0;
}