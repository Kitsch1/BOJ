#include <stdio.h>

int main(){
    int n,i;
    long long res,iter;
    scanf("%d",&n);
    
    res = 2;
    iter = 1;
    for(i=1;i<=n;i++){
        res += iter;
        iter += (1<<(i-1));
    }
    printf("%lld\n",res*res);

    return 0;
}