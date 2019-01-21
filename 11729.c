#include <stdio.h>

void solve(int n,int from,int go){
    if(n==1){
        printf("%d %d\n",from,go);
        return;
    }
    solve(n-1,from,6-from-go);
    printf("%d %d\n",from,go);
    solve(n-1,6-from-go,go);
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    solve(n,1,3);

    return 0;
}