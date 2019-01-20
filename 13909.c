#include <stdio.h>

int main(){
    long long n,i;
    scanf("%lld",&n);
    for(i=1;(i*i)<=n;i++);
    printf("%lld\n",i-1);

    return 0;
}