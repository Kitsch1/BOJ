#include <stdio.h>
#include <string.h>
typedef long long lld;

lld numbers[100];

lld gcd(lld n1,lld n2){
    lld temp;
    while(n2 > 0){
        temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }
    return n1;
}

int main(){
    int tcase,n,i,j;
    lld ans;
    scanf("%d",&tcase);
    
    while(tcase > 0){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&numbers[i]);
        }
        ans = 0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(numbers[i] > numbers[j]){
                    ans += gcd(numbers[i],numbers[j]);
                }
                else{
                    ans += gcd(numbers[j],numbers[i]);
                }
            }
        }
        printf("%lld\n",ans);
        tcase -= 1;
    }

    return 0;
}