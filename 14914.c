#include <stdio.h>

int main(){
    int apple,banana;
    int n1,n2,temp,i;
    scanf("%d %d",&apple,&banana);
    if(apple > banana){
        n1 = apple; n2 = banana;
    }
    else{
        n1 = banana; n2 = apple;
    }
    while(n2 > 0){
        temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }
    for(i=1;i<=n1;i++){
        if(n1 % i == 0){
            printf("%d %d %d\n",i,apple/i,banana/i);
        }
    }

    return 0;
}