#include <iostream>
using namespace std;
typedef long long lld;

bool ans_check[1000001];

int main(){
    lld l_min,l_max;
    cin >> l_min >> l_max;
    lld l_cnt = l_max - l_min;
    for(lld i=2;i*i<=l_max;i++){
        lld sq = i*i;
        lld start = sq - (l_min%sq); // make the start
        if(start == sq) start = 0; // need to check very first (if very first is nono number)
        for(lld j=start;j<=l_cnt;j+=sq){
            ans_check[j] = true;
        }
    }
    int ans = 0;
    for(int i=0;i<=l_cnt;i++){
        if(!ans_check[i]) ans += 1;
    }
    cout << ans << '\n';

    return 0;
}