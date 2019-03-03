#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> atm(n),sum_all(n);
    for(int r=0;r<n;r++){
        scanf("%d",&atm[r]);
    }
    sort(atm.begin(),atm.end());
    sum_all[0] = atm[0];
    for(int r=1;r<n;r++){
        sum_all[r] = sum_all[r-1] + atm[r];
    }
    int ans = 0;
    for(int r=0;r<n;r++){
        ans += sum_all[r];
    }
    printf("%d\n",ans);

    return 0;
}