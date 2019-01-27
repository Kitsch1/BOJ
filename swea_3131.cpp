#include <cstdio>

bool eratos[1000001]; // true : not prime, false : prime

int main(){
    for(int i=4;i<=1000000;i += 2){
        eratos[i] = true;
    }
    for(int i=3;i*i<=1000000;i++){
        for(int j=i*2;j<=1000000;j+=i){
            eratos[j] = true;
        }
    }
    for(int i=2;i<=1000000;i++){
        if(!eratos[i]) printf("%d ",i);
    }
    printf("\n");

    return 0;
}