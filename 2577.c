#include <stdio.h>
typedef long long lld;

int freq[10];

int main(){
    lld a,b,c,mul_num;
    int i;
    scanf("%lld %lld %lld",&a,&b,&c);
    mul_num = a*b*c;
    while(mul_num > 0){
        freq[mul_num % 10] += 1;
        mul_num /= 10;
    }
    for(i=0;i<10;i++){
        printf("%d\n",freq[i]);
    }

    return 0;
}