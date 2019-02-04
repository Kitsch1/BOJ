#include <stdio.h>

int pascal[31][31];

int main(){
    int r,c;
    int n,k;
    pascal[1][1] = pascal[2][1] = pascal[2][2] = 1;
    for(int r=3;r<=30;r++){
        pascal[r][1] = 1;
        for(int c=2;c<=r;c++){
            pascal[r][c] = pascal[r-1][c] + pascal[r-1][c-1];
        }
        pascal[r][r] = 1;
    }
    scanf("%d %d",&n,&k);
    printf("%d\n",pascal[n][k]);

    return 0;
}