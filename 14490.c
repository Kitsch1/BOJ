#include <stdio.h>
#include <string.h>

int main(){
    char input[24];
    int n,m,temp,tenten,idx;
    int big,small;
    scanf("%s",input);
    n = m = 0;
    tenten = 1;
    idx = strlen(input) - 1;
    while(input[idx] != ':'){
        m += tenten * (input[idx] - '0');
        tenten *= 10;
        idx -= 1;
    }
    tenten = 1;
    idx -= 1;
    while(idx >= 0){
        n += tenten * (input[idx] - '0');
        tenten *= 10;
        idx -= 1;
    }
    
    if(n > m){
        big = n; small = m;
    }
    else{
        big = m; small = n;
    }
    while(big % small != 0){
        temp = big % small;
        big = small;
        small = temp;
    }
    printf("%d:%d\n",n/small,m/small);

    return 0;
}