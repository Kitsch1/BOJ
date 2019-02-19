#define MOD 1000000007
#include <iostream>
using namespace std;
typedef long long lld;

lld fermat(lld a,lld b){
    lld ans = 1;
    a = (a % MOD);
    while(b > 0){
        if(b % 2 == 1){
            ans = (ans * a) % MOD;
            b -= 1;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}

int main(){
    lld a,b,a_b;
    lld a_fac,b_fac,a_b_fac,inv_1,inv_2;
    lld res;

    cin >> a >> b;
    a_b = a - b;
    a_fac = b_fac = a_b_fac = 1;
    for(lld i=1;i<=a;i++){
        a_fac = (a_fac * i) % MOD;
    }
    for(lld i=1;i<=b;i++){
        b_fac = (b_fac * i) % MOD;
    }
    for(lld i=1;i<=a_b;i++){
        a_b_fac = (a_b_fac * i) % MOD;
    }
    inv_1 = fermat(b_fac,MOD-2);
    inv_2 = fermat(a_b_fac,MOD-2);
    res = (a_fac * inv_1) % MOD;
    res = (res * inv_2) % MOD;
    cout << res << '\n';

    return 0;
}