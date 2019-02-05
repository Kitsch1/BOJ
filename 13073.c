#include <stdio.h>

int main(){
    int tcase,i,n;
    scanf("%d",&tcase);
    while(tcase > 0){
        scanf("%d",&n);
        printf("%d %d %d\n",n*(n+1)/2,n*(2+2*(n-1))/2,n*(4+2*(n-1))/2);
        tcase -= 1;
    }

    return 0;
}