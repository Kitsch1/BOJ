#include <cstdio>
#include <vector>
using namespace std;

bool prime_check[1000001];

int main(){
    prime_check[1] = true;
    for(int r=4;r<=1000000;r+=2){
        prime_check[r] = true;
    }
    for(int r=3;r*r<=1000000;r+=2){
        for(int c=r*2;c<=1000000;c+=r){
            prime_check[c] = true;
        }
    }
    int tcase;
    scanf("%d",&tcase);
    while(tcase > 0){
        int n,ans=0;
        scanf("%d",&n);
        for(int r=2;r<=n/2;r++){
            if(prime_check[r]) continue;
            if(!prime_check[n-r]) ans += 1;
        }
        printf("%d\n",ans);
        tcase -= 1;
    }

    return 0;
}