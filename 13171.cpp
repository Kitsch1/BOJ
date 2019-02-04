#define MODIFIER 1000000007
#include <iostream>
using namespace std;

long long sq_lst[64];

int main(){
    long long a,x;
    cin >> a >> x;
    sq_lst[0] = a % MODIFIER;
    for(int i=1;i<=60;i++){
        sq_lst[i] = ((sq_lst[i-1] % MODIFIER) * (sq_lst[i-1] % MODIFIER)) % MODIFIER;
    }
    long long ans = 1;
    while(x > 0){
        long long i = ((long long)1<<(long long)60);
        int idx = 60;
        for(;i>1;i>>=1){
            if(i <= x){
                x -= i; 
                ans = ((ans % MODIFIER) * (sq_lst[idx]) % MODIFIER) % MODIFIER;
                break;
            }
            idx -= 1;
        }
        if(i == 1){
            x -= 1;
            ans = ((ans % MODIFIER) * (a % MODIFIER)) % MODIFIER;
        }
    }
    cout << ans << '\n';

    return 0;
}