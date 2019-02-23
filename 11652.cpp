#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lld;

int main(){
    int n;
    scanf("%d",&n);
    vector<lld> card(n);
    for(int r=0;r<n;r++){
        scanf("%lld",&card[r]);
    }
    sort(card.begin(),card.end());
    lld cur_num = card[0], plenty_num = card[0];
    int cnt = 1, cur_cnt = 1;
    for(int r=1;r<n;r++){
        if(cur_num == card[r]){
            cur_cnt += 1;
        }
        else{
            if(cnt < cur_cnt){
                plenty_num = cur_num;
                cnt = cur_cnt;
            }
            cur_num = card[r];
            cur_cnt = 1;
        }
    }
    if(cnt < cur_cnt){
        plenty_num = cur_num;
    }
    printf("%lld\n",plenty_num);

    return 0;
}