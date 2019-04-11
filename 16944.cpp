#include <iostream>
#include <string>
using namespace std;

int cnt_pwd[4]; // 0 : small, 1: capital, 2 : number 3 : else

int main(){
    int n,ans = 0;
    string pwd;
    cin >> n;
    cin >> pwd;
    for(auto a : pwd){
        if(a >= 'a' && a <= 'z') cnt_pwd[0] += 1;
        else if(a >= 'A' && a <= 'Z') cnt_pwd[1] += 1;
        else if(a >= '0' && a <= '9') cnt_pwd[2] += 1;
        else cnt_pwd[3] += 1;
    }
    for(int i=0;i<4;i++){
        if(cnt_pwd[i] == 0) ans += 1;
    }
    if(n+ans < 6) ans += (6-(n+ans));
    cout << ans << '\n';

    return 0;
}