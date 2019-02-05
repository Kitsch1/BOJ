#include <stdio.h>

int main(){
    long long a,b,temp,i,n1,n2;
    scanf("%lld %lld",&a,&b);
    if(a > b){
        n1 = a; n2 = b;
    }
    else{
        n1 = b; n2 = a;
    }
    while(n2 > 0){
        temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }
    for(i=0;i<n1;i++){
        printf("1");
    }
    printf("\n");

    return 0;
}