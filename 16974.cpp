#include <cstdio>
typedef long long lld;

lld burger[51], patty[51];

lld solve(int n,lld layer){
    if(n == 0){
        if(!layer) return 0;
        else return 1;
    }
    lld ans = 0;
    if(layer <= 1) return 0; // no patty
    else if(layer <= burger[n-1] + 1) ans += solve(n-1,layer-1); // checking Level N-1 burger
    else if(layer == burger[n-1] + 2) ans += patty[n-1] + 1; // eat center patty
    else if(layer <= 2*burger[n-1] + 2) ans += patty[n-1] + 1 + solve(n-1,layer-burger[n-1]-2); // checking upside N-1 burger
    else ans = 2 * patty[n-1] + 1; // eat all patty
    return ans;
}

int main(){
    int n;
    lld layer;
    scanf("%d %lld",&n,&layer);
    burger[0] = patty[0] = 1;
    for(int i=1;i<=n;i++){
        burger[i] = (2 * burger[i-1]) + 3;
        patty[i] = (2 * patty[i-1]) + 1;
    }
    printf("%lld\n",solve(n,layer));

    return 0;
}