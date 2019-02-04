#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool eratos[40001];
long long dp[40001];
vector<int> prime;

int main(){
    int n;
    cin >> n;
    
    for(int i=4;i<=n;i+=2){
        eratos[i] = true;
    }
    for(int i=3;i*i<=n;i+=2){
        for(int j=i*2;j<=n;j+=i){
            eratos[j] = true;
        }
    }
    for(int i=2;i<=n;i++){
        if(!eratos[i]) prime.push_back(i);
    }
    memset(dp,-1,sizeof(long long)*40001);
    dp[0] = 1;

    int size = prime.size();
    for(int i=2;i<=n;i+=2){
        dp[i] = 1;
    }
    for(int i=1;i<size;i++){
        for(int j=prime[i];j<=n;j++){
            if(dp[j-prime[i]] != -1){
                if(dp[j] == -1) dp[j] = dp[j-prime[i]];
                else dp[j] = (dp[j] + dp[j-prime[i]]) % 123456789;
            }
        }
    }
    cout << dp[n] << '\n';

    return 0;
}