#include <iostream>
using namespace std;

int main(){
    int l_num,r_num;
    long long ans = 0, back_ans = 0;
    int back_num;
    cin >> l_num >> r_num;
    for(int i=1;i<=r_num;i++){
        ans += (r_num / i) * i;
    }
    back_num = l_num - 1;
    for(int i=1;i<=back_num;i++){
        back_ans += (back_num / i) * i;
    }
    ans -= back_ans;
    cout << ans << '\n';

    return 0;
}