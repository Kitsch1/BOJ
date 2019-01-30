#include <iostream>
#include <map>
using namespace std;

long long n,p,q;
map<long long,long long> dp;

long long solve(long long cur){
    if(cur == 0) return 1;
    if(dp[cur]) return dp[cur];
    return dp[cur] = solve(cur/p) + solve(cur/q);
}

int main(){
    cin >> n >> p >> q;
    cout << solve(n) << '\n';

    return 0;
}