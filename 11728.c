#include <stdio.h>

int arr1[1000000];
int arr2[1000000];

int main(){
    int n,m,r,c;
    scanf("%d %d",&n,&m);
    for(r=0;r<n;r++){
        scanf("%d",&arr1[r]);
    }
    for(r=0;r<m;r++){
        scanf("%d",&arr2[r]);
    }
    r = c = 0;
    while(r < n && c < m){
        if(arr1[r] > arr2[c]){
            printf("%d ",arr2[c]);
            c += 1;
        }
        else{
            printf("%d ",arr1[r]);
            r += 1;
        }
    }
    while(r < n){
        printf("%d ",arr1[r]);
        r += 1;
    }
    while(c < m){
        printf("%d ",arr2[c]);
        c += 1;
    }
    printf("\n");

    return 0;
}