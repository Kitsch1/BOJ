#include <iostream>
using namespace std;

const long long modifier = 1000000007;

long long solve(long long a,long long x){
    long long res = 1;
    a = a % modifier;
    while(x > 0){
        if(x % 2 == 1){
            res = (res * a) % modifier;
            x -= 1;
        }
        a = (a * a) % modifier;
        x /= 2;
    }
    return res;
}

int main(){
    long long a,x;
    cin >> a >> x;
    cout << solve(a,x) << '\n';

    return 0;
}