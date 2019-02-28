#define MOD 1000000007
#include <cstdio>
using namespace std;
typedef long long lld;

lld sq_two(int s_num){
    lld ans = 1;
    lld cur_sq = 2;
    while(s_num > 0){
        if(s_num % 2){
            ans = (ans * cur_sq) % MOD;
            s_num -= 1;
        }
        cur_sq = (cur_sq * cur_sq) % MOD;
        s_num /= 2;
    }
    return ans;
}

int main(){
    int n;
    lld ans = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        lld coef;
        int sq;
        scanf("%lld %d",&coef,&sq);
        lld cur_ans = (sq_two(sq-1) * sq) % MOD;
        cur_ans = (cur_ans * coef) % MOD;
        ans = (ans + cur_ans) % MOD;
    }
    printf("%lld\n",ans);

    return 0;
}