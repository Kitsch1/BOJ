#include <cstdio>

int main(){
    int n;
    bool flag = false;
    scanf("%d",&n);
    for(int i=1;i<=1000000;i++){
        int cur_jari = 0;
        for(int j=i;j>0;j/=10){
            cur_jari += (j % 10);
        }
        if(n == i+cur_jari){
            printf("%d\n",i);
            flag = true;
            break;
        }
    }
    if(!flag) printf("0\n");

    return 0;
}