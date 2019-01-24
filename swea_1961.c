#include <stdio.h>
#include <string.h>

int arr[7][7];

int main(){
    int tcase,n,i,j,k;
    scanf("%d",&tcase);
    for(i=1;i<=tcase;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                scanf("%d",&arr[j][k]);
            }
        }
        printf("#%d\n",i);
        for(j=0;j<n;j++){
            for(k=n-1;k>=0;k--){
                printf("%d",arr[k][j]);
            }
            printf(" ");
            for(k=n-1;k>=0;k--){
                printf("%d",arr[n-j-1][k]);
            }
            printf(" ");
            for(k=0;k<n;k++){
                printf("%d",arr[k][n-j-1]);
            }
            printf("\n");
        }
        memset(arr,0,sizeof(int)*7*7);
    }

    return 0;
}