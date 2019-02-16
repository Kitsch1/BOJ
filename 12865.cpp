#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> stuff;
int knapsack[101][100001];

int main(){
    int n,limit;
    scanf("%d %d",&n,&limit);
    for(int i=0;i<n;i++){
        int w,v;
        scanf("%d %d",&w,&v);
        stuff.push_back(make_pair(w,v));
    }
    sort(stuff.begin(),stuff.end());
    for(int r=1;r<=n;r++){
        int w_start = stuff[r-1].first;
        int cur_v = stuff[r-1].second;
        for(int c=0;c<=limit;c++){
            if(c < w_start) knapsack[r][c] = knapsack[r-1][c];
            else knapsack[r][c] = max(knapsack[r-1][c],knapsack[r-1][c-w_start]+cur_v);
        }
    }
    printf("%d\n",knapsack[n][limit]);

    return 0;
}