#include <stdio.h>

int main(){
    int n,i,j=1,ans=1;
    scanf("%d",&n);
    for(i=1;;i++){
        if(j >= n) break;
        else{
            ans += 1;
            j += (i*6);
        }
    }
    printf("%d\n",ans);

    return 0;
}