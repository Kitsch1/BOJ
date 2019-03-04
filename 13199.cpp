#include <cstdio>
using namespace std;

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        int p,budget,c_need,c_give;
        scanf("%d %d %d %d",&p,&budget,&c_need,&c_give);
        int c_received = (budget / p) * c_give; // received coupon
        int coupon_chicken = c_received / c_need; // coupon chicken
        int more_more = 0;
        int finally = c_need - c_give;
        while(c_received >= c_need){
            c_received -= finally;
            more_more += 1;
        }
        printf("%d\n",more_more-coupon_chicken);

        tcase -= 1;
    }

    return 0;
}