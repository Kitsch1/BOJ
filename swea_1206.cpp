#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int building[1000];

int solve(int n){
    int end = n-2, ans = 0;
    for(int i=2;i<end;i++){
        int highest = max(max(building[i-2],building[i-1]),max(building[i+1],building[i+2]));
        if(building[i] > highest){
            ans += building[i] - highest;
        }
    }
    return ans;
}

int main(){
    for(int i=1;i<=10;i++){
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%d",&building[j]);
        }
        printf("#%d %d\n",i,solve(n));
        memset(building,0,sizeof(int)*1000);
    }

    return 0;
}