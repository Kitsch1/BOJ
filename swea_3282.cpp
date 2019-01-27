#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

int dp[101][1001];

int solve(vector<pair<int,int>> &stuff,int num,int dense){
    for(int i=1;i<=num;i++){
        int v_cur = stuff[i-1].first;
        int price_cur = stuff[i-1].second;
        for(int j=1;j<=dense;j++){
            if(j-v_cur < 0){
                dp[i][j] = dp[i-1][j]; continue;
            }
            dp[i][j] = (dp[i-1][j-v_cur] + price_cur > dp[i-1][j]) ? dp[i-1][j-v_cur] + price_cur : dp[i-1][j];
        }
    }
    int res = -1;
    for(int i=1;i<=num;i++){
        for(int j=1;j<=dense;j++){
            if(res < dp[i][j]) res = dp[i][j];
        }
    }
    return res;
}

int main(){
    int tcase;
    scanf("%d",&tcase);
    for(int i=1;i<=tcase;i++){
        int num,dense;
        vector<pair<int,int>> stuff; 
        scanf("%d %d",&num,&dense);
        for(int j=0;j<num;j++){
            int v,c;
            scanf("%d %d",&v,&c);
            stuff.push_back(make_pair(v,c));
        }
        sort(stuff.begin(),stuff.end());
        printf("#%d %d\n",i,solve(stuff,num,dense));
        memset(dp,0,sizeof(int)*101*1001);
    }

    return 0;
}