#include <cstdio>
#include <algorithm>
using namespace std;

int rgb[1001][3];
int cost[1001][3];

void solve(int n);

int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&rgb[i][0],&rgb[i][1],&rgb[i][2]);
    }

    solve(n);

    return 0;
}

void solve(int n){
    cost[1][0] = rgb[1][0];
    cost[1][1] = rgb[1][1];
    cost[1][2] = rgb[1][2];

    for(int i=2;i<=n;i++){
        cost[i][0] = rgb[i][0] + min(cost[i-1][1],cost[i-1][2]);
        cost[i][1] = rgb[i][1] + min(cost[i-1][0],cost[i-1][2]);
        cost[i][2] = rgb[i][2] + min(cost[i-1][0],cost[i-1][1]);
    }

    printf("%d\n",min(cost[n][0],min(cost[n][1],cost[n][2])));
}