#include <cstdio>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1500001];
int n;
vector<pair<int,int>> work(1500001);

int solve(int day,int n){
    if(day > n) return 0;

    int& ans = dp[day];
    if(ans != -1) return ans;
    ans = 0;

    int cur_day_need = work[day].first;
    int cur_benefit = work[day].second;
    if(day + cur_day_need - 1 <= n){
        return ans += max(solve(day+cur_day_need,n)+cur_benefit,solve(day+1,n));
    }
    else{
        return ans += solve(day+1,work);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&work[i].first,&work[i].second);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1,n));

    return 0;
}