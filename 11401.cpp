#include <iostream>
using namespace std;

const long long modifier = 1000000007;
long long factorial[4000001], inv_fac[4000001];

long long sq_fac(long long a,long long sq_num){
    long long res = 1;
    while(sq_num > 0){
        if(sq_num % 2 == 1){
            sq_num -= 1;
            res = (res * a) % modifier;
        }
        a = (a * a) % modifier;
        sq_num /= 2;
    }
    return res;
}

int main(){
    int n,k;
    cin >> n >> k;

    if(n == k || !k){
        cout << "1\n";
    }
    else{
        factorial[0] = factorial[1] = 1;
        for(int r=2;r<=n;r++){
            factorial[r] = (factorial[r-1] * r) % modifier;
        }
        inv_fac[n] = sq_fac(factorial[n],modifier-2);
        for(int r=n-1;r>0;r--){
            inv_fac[r] = (inv_fac[r+1] * (r+1)) % modifier;
        }
        long long res = (factorial[n] * inv_fac[n-k]) % modifier;
        res = (res * inv_fac[k]) % modifier;
        printf("%d\n",res); 
    }

    return 0;
}