#include <cstdio>
using namespace std;

int price[1000001];
long long earn = 0;
int max_price;

int main(){
    int tcase;
    scanf("%d",&tcase);
    for(int i=1;i<=tcase;i++){
        int n;
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d",&price[j]);
        }
        max_price = price[n];
        for(int j=n-1;j>=1;j--){
            if(max_price < price[j]) max_price = price[j];
            else earn += max_price - price[j];
        }
        printf("#%d %lld\n",i,earn);
        earn = 0;
    }

    return 0;
}