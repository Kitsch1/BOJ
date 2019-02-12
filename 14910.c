#include <stdio.h>

int main(){
    int before,after;
    int flag = 1;
    scanf("%d",&before);
    while(~(scanf("%d",&after))){
        if(before > after){
            flag = 0; break;
        }
        before = after;
    }
    if(flag) printf("Good\n");
    else printf("Bad\n");

    return 0;
}