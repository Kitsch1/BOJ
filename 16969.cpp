#define MOD 1000000009
#include <iostream>
#include <string>
typedef long long lld;
using namespace std;

int main(){
    string car_num;
    lld ans;
    int c_len;
    cin >> car_num;

    c_len = car_num.size();
    if(car_num[0] == 'c') ans = 26;
    else ans = 10;

    for(int i=1;i<c_len;i++){
        if(car_num[i] == 'c'){
            if(car_num[i-1] == 'c') ans = (ans * 25) % MOD;
            else ans = (ans * 26) % MOD; 
        }
        else{
            if(car_num[i-1] == 'd') ans = (ans * 9) % MOD;
            else ans = (ans * 10) % MOD;
        }
    }
    cout << ans << '\n';

    return 0;
}