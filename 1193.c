#include <stdio.h>

int main(){
    int x,i,cur;
    int numer,denom,diff;
    scanf("%d",&x);
    for(i=1;i<=5000;i++){
        cur = i*(i+1)/2;
        if(x <= cur) break;
    }
    diff = cur-x;
    if(i % 2 == 0){
        numer = i; denom = 1;
        numer -= diff;
        denom += diff;
    }
    else{
        numer = 1; denom = i;
        numer += diff;
        denom -= diff;
    }
    printf("%d/%d\n",numer,denom);

    return 0;
}