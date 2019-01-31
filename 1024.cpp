#include <iostream>
using namespace std;

int main(){
    long long n;
    int l;
    cin >> n >> l;
    
    bool find = false;
    for(int i=l;i<=100;i++){
        long long back_num = (i*(i-1)) / 2;
        long long start = -1;
        if(n < back_num) break;
        if((n-back_num) % i == 0){
            start = (n-back_num) / i;
            for(int j=0;j<i;j++){
                cout << start + j << ' ';
            }
            find = true; break;
        }
    }
    if(!find) cout << "-1\n";

    return 0;
}