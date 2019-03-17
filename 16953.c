#include <stdio.h>

int main(){
    int a,b,cnt;
    scanf("%d %d",&a,&b);
    for(cnt=0;a<=b;cnt++){
        if(a == b){
            break;
        }
        if(!(b%2)) b /= 2;
        else if(b % 10 == 1) b = (b-1) / 10;
        else break; 
    }
    if(a == b) printf("%d\n",cnt+1);
    else printf("-1\n");

    return 0;
}