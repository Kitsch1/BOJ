#include <stdio.h>

int main(){
    int tcase,n,i,ans;
    scanf("%d",&tcase);
    while(tcase > 0){
        scanf("%d",&n);
        ans = 0;
        for(i=1;i*i<=n;i++){
            if(n % i == 0){
                if(i == (n/i)) ans += 1;
                else ans += 2;
            }
        }
        printf("%d %d\n",n,ans);

        tcase -= 1;
    }

    return 0;
}