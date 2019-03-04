#define MOD 1000000007
#include <iostream>
using namespace std;
typedef long long lld;

lld sq_num(lld a,int b){
    lld ans = 1;
    while(b > 0){
        if(b % 2){
            ans = (ans * a) % MOD;
            b -= 1;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}

int main(){
    lld boy,girl;
    cin >> boy >> girl;

    lld diff = boy-girl;
    lld boy_f,girl_f,diff_f;
    boy_f = girl_f = diff_f = 1;

    for(lld i=1;i<=boy;i++){
        boy_f = (boy_f * i) % MOD;
    }
    for(lld i=1;i<=girl;i++){
        girl_f = (girl_f * i) % MOD;
    }
    for(lld i=1;i<=diff;i++){
        diff_f = (diff_f * i) % MOD;
    }

    lld ans = (boy_f * sq_num(girl_f,MOD-2)) % MOD;
    ans = (ans * sq_num(diff_f,MOD-2)) % MOD;
    cout << ans << '\n';

    return 0;
}