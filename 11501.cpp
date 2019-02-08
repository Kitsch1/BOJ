#include <cstdio>
using namespace std;
typedef long long lld;

lld stock[1000000];

int main(){
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&stock[i]);
        }
        lld highest = stock[n-1];
        lld res = 0;
        for(int i=n-2;i>=0;i--){
            if(highest < stock[i]){
                highest = stock[i];
            }
            else{
                res += highest - stock[i];
            }
        }
        printf("%lld\n",res);
        tcase -= 1;
    }

    return 0;
}